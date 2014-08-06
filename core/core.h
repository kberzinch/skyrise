#pragma systemFile
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#if defined(_DEBUG)
#pragma DebuggerWindows("debugStream")
#endif
#include "Vex_Competition_Includes_patchedv2.h"
#ifndef NoLCD
#include "lcd_menu.h"
#endif

/* ASSUMPTIONS:
- Lift[L/R], Roller[L/R], Drive[L/R][R/F] are all valid motors
- Lift and roller motors are configured to move in same direction (i.e. LiftLeft = LiftRight = 127 is up and v.v.)
- Encoders are on DriveLeftRear, DriveRightRear, and LiftRight
*/

// Warnings

#if defined(_DEBUG)
#warn("Optimization turned off.")
#endif

#ifndef ROBOTC
#error("This program must be compiled using ROBOTC.")
#endif

#ifndef ProgrammingSkills
#ifndef NoProgrammingSkills
#warn("Programming skills not included - is this intentional?")
#endif
#endif

// Type Definitions

typedef byte tSpeed;
typedef long tTimer;

typedef enum {
    LEFT = true,
    RIGHT = false,
} tSide;

typedef enum {
    STOP = 0,
    FORWARD = 1,
    BACKWARD = 2,
    CLOCKWISE = 3,
    COUNTERCLOCKWISE = 4,
} tDirection;

typedef enum {
    CORE_SUCCESS = 0,
    CORE_ERROR = 1,
    CORE_TIMEOUT = 2,
    CORE_COLLISION = 3,
    CORE_INPROGRESS = 4,
} tError;

typedef struct {
    tMotor Port;
    unsigned byte Slaves;
    tSensors Sensor;
    bool NegateTarget;
    tMotor Slave[3];
} tMotorEx;

typedef struct {
    float Kp;
    float Ki;
    float Kd;
    int Error;
    int Error_Prev;
    int Integral;
    int Derivative;
    int Target;
    int Margin;
    TSemaphore Semaphore;
} tPID;

// Procedure/task definitions

void init();
void Auton_ResetEncoders();
void ResetEncoders();
//tMotor LiftLeftAssist, LiftRightAssist;
tMotorEx eRollers, eLift, eDriveLeft, eDriveRight;
tPID pLift, pDrive, pDrift;
tSensors LimitLift;
task PID_Lift;
task PID_Drive;

void Halt(int Line) {
#if defined(_DEBUG)
    writeDebugStreamLine("Halt command sent from line %i",Line);
#endif
    allMotorsOff();
    stopAllTasks();
}

// Basic motor operations

void Auton_Motor_Set(tMotorEx &this, tSpeed Speed = 0) {
    if(Speed > 127)
        Speed = 127;
    if(Speed < -127)
        Speed = -127;
    motor[this.Port] = Speed;
    if(this.Slaves > 0) {
        for(unsigned byte thisSlave = 0; thisSlave < this.Slaves; thisSlave++) {
            motor[this.Slave[thisSlave]] = Speed;
        }
    }
}

int Auton_Motor_GetMultiplier(tDirection Direction, tSide Side) { // if this function is generating an exception, you have passed an invalid Direction. It IS your fault.
#if defined(_DEBUG)
    VERIFY(Direction >= 0 && Direction <= 4); // This line must remain uncommented by order of KB.
#endif
    switch(Direction) {
    case STOP:
        return 0;
    case FORWARD:
        return 1;
    case BACKWARD:
        return -1;
    case CLOCKWISE:
        switch(Side) {
        case LEFT:
            return 1;
        case RIGHT:
            return -1;
        }
    case COUNTERCLOCKWISE:
        switch(Side) {
        case LEFT:
            return -1;
        case RIGHT:
            return 1;
        }
    }
    VERIFY(false); // This line must remain uncommented by order of KB.
    return CORE_ERROR;
}

int Auton_Motor_Sensor(tMotorEx &this, bool AbsVal = false) {
    if(AbsVal) {
        if(this.NegateTarget) {
            return -SensorValue[this.Sensor];
            } else {
            return SensorValue[this.Sensor];
        }
        } else {
        return abs(SensorValue[this.Sensor]);
    }
}

void Auton_ClearPID(tPID &this) {
    this.Error = 0;
    this.Error_Prev = 0;
    this.Integral = 0;
    this.Derivative = 0;
}

void Auton_ResetEncoders() {
    ResetEncoders();
#if defined(_DEBUG)
    writeDebugStreamLine("All encoders reset");
#endif
}

#if defined(_DEBUG)
task ResetEncodersTask {
    Auton_ResetEncoders();
}
#endif

void pre_auton() {
#if defined(_DEBUG)
    clearDebugStream();
    writeDebugStreamLine("Entered preauton");
    writeDebugStreamLine("Batt A: %1.2fv", (float)nImmediateBatteryLevel / (float)1000);
#ifndef NoPowerExpander
    writeDebugStreamLine("Batt B: %1.2fv", (float)SensorValue[PowerExpander] / (float)280);
#endif
    writeDebugStreamLine("Backup: %1.2fv", (float)BackupBatteryLevel / (float)1000);
    writeDebugStream(FILE);
    writeDebugStream(" compiled on ");
    writeDebugStream(__DATE__);
    writeDebugStream(" at ");
    writeDebugStreamLine(__TIME__);
    writeDebugStreamLine(" - Debug			 ON");
#ifdef ProgrammingSkills
    writeDebugStreamLine(" - Progskill	 ON");
#endif
#ifndef ProgrammingSkills
    writeDebugStreamLine(" - Progskill	OFF");
#endif
#ifndef NoInit
    writeDebugStreamLine(" - Init				OFF");
#endif
#ifdef NoInit
    writeDebugStreamLine(" - Init				 ON");
#endif
#ifndef NoLCD
    writeDebugStreamLine(" - LCD				 ON");
#endif
#ifdef NoLCD
    writeDebugStreamLine(" - LCD				OFF");
#endif
#endif
    bPlaySounds = false;
    bLCDBacklight = true;
#ifndef NoLCD
    LCD.Display.BattA = true;
#ifndef NoPowerExpander
    LCD.Display.BattB = PowerExpander;
#endif
    LCD.Display.Backup = true;
#endif
    clearLCDLine(0);
    clearLCDLine(1);
    if(!bIfiRobotDisabled) {
#if defined(_DEBUG)
        writeDebugStreamLine("Not disabled: exiting");
#endif
        return;
    }
#ifndef NoInit
#if defined(_DEBUG)
    writeDebugStreamLine("Starting init()");
#endif
    init();
#endif
#ifndef NoLCD
#if defined(_DEBUG)
    writeDebugStreamLine("Menu launched");
#endif
    LCD_Menu();
#endif

    clearLCDLine(0);
    clearLCDLine(1);

#ifndef NoLCD
    startTask(LCD_Display);
#endif
#if defined(_DEBUG)
    writeDebugStreamLine("Waiting to reset encoders...");
#endif
    sleep(1000);
    Auton_ResetEncoders();
#if defined(_DEBUG)
    writeDebugStreamLine("Ready to roll!");
#endif
}

// Timers

tTimer Auton_TimerSet(long Time = 0) {
    return nSysTime - Time;
}

long Auton_TimerCheck(tTimer this) {
    return this - nSysTime;
}

tError Auton_WaitForKeyPress(long Timeout = 4000) {
    tTimer Timer = Auton_TimerSet();
#ifndef NoLCD
    LCD.Display.Paused = true;
#endif
    while(nLCDButtons == 0) {
        if(Auton_TimerCheck(Timer) > Timeout)
            return CORE_TIMEOUT;
        EndTimeSlice();
    }
#ifndef NoLCD
    LCD.Display.Paused = false;
#endif
    while(nLCDButtons == 0) {
        if(Auton_TimerCheck(Timer) > Timeout)
            return CORE_TIMEOUT;
        EndTimeSlice();
    }
    sleep(100);
    return CORE_SUCCESS;
}

// Semaphores

bool Auton_SemaphoreOwned(TSemaphore nSemaphore) {
    return nSemaphore.nOwningTask == (unsigned)nCurrentTask;
}

void Auton_SemaphoreLock(TSemaphore nSemaphore) {
    while(!Auton_SemaphoreOwned(nSemaphore))
        semaphoreLock(nSemaphore);
}

void Auton_SemaphoreUnlock(TSemaphore nSemaphore) {
    while(Auton_SemaphoreOwned(nSemaphore))
        semaphoreUnlock(nSemaphore);
}

tError Auton_Lift(int Target = 0, tSpeed Speed = 127, bool Wait = true, long Timeout = 1000) {
    tTimer Timer = Auton_TimerSet();
    int OldTarget = pLift.Target;
    pLift.Target = Target;
    if(Wait) { // wait
        Auton_SemaphoreLock(pLift.Semaphore);
        if(Target < SensorValue[eLift.Sensor]) { // determines direction for motor
            Auton_Motor_Set(eLift,-Speed);
            while(Target < SensorValue[eLift.Sensor] && Auton_TimerCheck(Timer) < Timeout)
                EndTimeSlice();
            Auton_Motor_Set(eLift);
            } else {
            Auton_Motor_Set(eLift,Speed);
            while(Target > SensorValue[eLift.Sensor] && Auton_TimerCheck(Timer) < Timeout)
                EndTimeSlice();
            Auton_Motor_Set(eLift);
        }
        Auton_SemaphoreUnlock(pLift.Semaphore);
        if(Auton_TimerCheck(Timer) > Timeout) {
            pLift.Target = OldTarget;
            return CORE_TIMEOUT;
            } else {
            return CORE_SUCCESS;
        }
    }
    return CORE_INPROGRESS;
}

void Auton_Drive(tDirection Direction = STOP, tSpeed Speed = 0, int Time = 0) {
#if defined(_DEBUG)
    VERIFY(Direction >= 0 && Direction <= 4); // This line must remain uncommented by order of KB. Disabled in release compilations.
#endif
    // Please note that no drift compensation is available in this function.
    Auton_Motor_Set(eDriveLeft,Auton_Motor_GetMultiplier(Direction,LEFT) * Speed);
    Auton_Motor_Set(eDriveRight,Auton_Motor_GetMultiplier(Direction,RIGHT) * Speed);
    if(Time > 0) {
        sleep(Time);
        Auton_Drive();
    }
}

// This function probably needs to be redone. 1st objective: reach target accurately, 2nd objective: compensate for drift.
// Or just screw it and do a simple drive as usual.
tError Auton_Drive_Targeted(tDirection Direction, int Distance, tSpeed Speed = 127, int Time = 0, int Accuracy = 10) {
#if defined(_DEBUG)
    VERIFY(Distance > 0);
#endif
    Auton_ResetEncoders();
    int CalcSpeed = 127;
    Distance = Distance * 1.3;
    while(true) {
        pDrive.Error = Distance - (abs(SensorValue[EncoderLeft]) + abs(SensorValue[EncoderRight]) / 2);
        if(pDrive.Error < Accuracy && pDrive.Error > - Accuracy)
            return CORE_SUCCESS;
        pDrive.Integral = pDrive.Integral + pDrive.Error;
        if (CalcSpeed > 110/*pDrive.Error == 0 || abs(pDrive.Error) > pDrive.Margin*/) {
            pDrive.Integral = 0;
        }
        pDrive.Derivative = pDrive.Error - pDrive.Error_Prev;
        pDrive.Error_Prev = pDrive.Error;
        CalcSpeed = (pDrive.Kp * (float)pDrive.Error) + (pDrive.Ki * (float)pDrive.Integral) + (pDrive.Kd * (float)pDrive.Derivative);
        clearLCDLine(0);
        clearLCDLine(1);
        displayLCDNumber(0, 0, CalcSpeed);
        displayLCDNumber(1, 0, pDrive.Error,3);
        Auton_Motor_Set(eDriveLeft,Auton_Motor_GetMultiplier(Direction,LEFT) * CalcSpeed);
        Auton_Motor_Set(eDriveRight,Auton_Motor_GetMultiplier(Direction,RIGHT) * CalcSpeed);
    }
    return CORE_SUCCESS;
}
