// Initial setup
#pragma systemFile
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#if defined(_DEBUG)
#pragma DebuggerWindows("debugStream")
#endif
#ifndef NoLCD
#define LCD_NotUsing_Prompt
#include "lcd_menu.h"
#endif
#include "competition.h"

// Warnings
#if defined(_DEBUG)
#warn("Optimization turned off.")
#endif

#ifndef ROBOTC
#error("This program must be compiled using ROBOTC.")
#endif

#ifndef ProgrammingSkills
#ifndef NoProgrammingSkills
#warn("Programming skills not included - if intentional add #define NoProgrammingSkills")
#endif
#endif

// Type Definitions

typedef byte tSpeed;
typedef long tTimer;

typedef enum tDirection {
	STOP,
	FORWARD,
	BACKWARD,
	CLOCKWISE,
	COUNTERCLOCKWISE
};

typedef enum tVertical {
	UP = 1,
	DOWN = -1,
	VSTOP = 0
};

typedef enum tSide {
	LEFT,
	RIGHT
};

typedef enum tTransmission {
	SPEED,
	TORQUE
};

// Must be defined per robot
void init();
void ResetDriveEncoders();
void ResetLiftEncoders();
tMotor DriveLeftA, DriveLeftB, DriveRightA, DriveRightB, LiftA, LiftB, LiftC, LiftD, LiftE, LiftF;
tSensors DriveEncoderLeft, LiftEncoder, LiftLimitA, LiftLimitB, Gyro, TransmissionPneumatic, ClawPneumatic, ClawLimitA, ClawLimitB;

// Function definitions

// Use __LINE__ as the parameter
void Halt(int Line) {
#if defined(_DEBUG)
	writeDebugStreamLine("Halt command sent from line %i",Line);
#endif
	allMotorsOff();
	stopAllTasks();
}

int Auton_GetMultiplier(tDirection Direction, tSide Side) {
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
	return 0;
}

void Auton_Drive(tDirection Direction = STOP, tSpeed Speed = 0, int Time = 0) {
	motor[DriveLeftA] = Speed * Auton_GetMultiplier(Direction,LEFT);
	motor[DriveLeftB] = Speed * Auton_GetMultiplier(Direction,LEFT);
	motor[DriveRightA] = Speed * Auton_GetMultiplier(Direction,RIGHT);
	motor[DriveRightB] = Speed * Auton_GetMultiplier(Direction,RIGHT);
	if(Time > 0) {
		sleep(Time);
		Auton_Drive();
	}
}

#ifdef HasGyro
void Auton_Drive_TurnTo(tDirection Direction, tSpeed Speed = 0, int Heading = 0) {
	Auton_Drive(Direction, Speed);
	if(SensorValue[Gyro] > Heading) {
		while(SensorValue[Gyro] > Heading) {}
		} else {
		while(SensorValue[Gyro] < Heading) {}
	}
}
#endif

void Auton_Drive_Targeted(tDirection Direction, tSpeed Speed = 0, int Distance = 0) {
	Auton_Drive(Direction, Speed);
	switch(Auton_GetMultiplier(Direction,LEFT)) {
	case -1:
		while(SensorValue[DriveEncoderLeft] > Distance) {}
		break;
	case 1:
		while(SensorValue[DriveEncoderLeft] < Distance) {}
		break;
	}
}

#ifndef NoLCD
void Auton_WaitForKeyPress(int Sleep = 0) {
	LCD.Display.Paused = true;
	while(nLCDButtons == 0) {}
	while(nLCDButtons != 0) {}
	sleep(Sleep);
	LCD.Display.Paused = false;
}
#endif

void Transmission(tTransmission NewStatus) {
	if(NewStatus == TORQUE) {
		SensorValue[TransmissionPneumatic] = 0;
		} else {
		SensorValue[TransmissionPneumatic] = 1;
	}
}

void pre_auton() {
#ifndef NoLCD
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	displayLCDCenteredString(0, "Starting up");
	displayLCDCenteredString(1, "Please stand by");
#endif
#if defined(_DEBUG)
	clearDebugStream();
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
	writeDebugStreamLine(" - Init				 ON");
#endif
#ifdef NoInit
	writeDebugStreamLine(" - Init				OFF");
#endif
#ifndef NoLCD
	writeDebugStreamLine(" - LCD				 ON");
#endif
#ifdef NoLCD
	writeDebugStreamLine(" - LCD				OFF");
#endif
	writeDebugStreamLine(" - Batt A   %1.2fv", (float)nImmediateBatteryLevel / (float)1000);
#ifndef NoPowerExpander
	writeDebugStreamLine(" - Batt B   %1.2fv", (float)SensorValue[PowerExpander] / (float)280); // TBD: Verify magic number
#endif
	writeDebugStreamLine(" - Backup   %1.2fv", (float)BackupBatteryLevel / (float)1000);
#endif
	bPlaySounds = false;
#ifndef NoLCD
	LCD.Display.BattA = true;
#ifndef NoPowerExpander
	LCD.Display.BattB = PowerExpander;
#endif
	LCD.Display.Backup = true;
#endif
	clearLCDLine(0);
	clearLCDLine(1);
#ifndef NoInit
#if defined(_DEBUG)
	writeDebugStreamLine("Starting init()");
#endif
	init();
#endif
	if(!bIfiRobotDisabled) {
#if defined(_DEBUG)
		writeDebugStreamLine("Not disabled: exiting");
#endif
#ifndef NoLCD
		clearLCDLine(0);
		clearLCDLine(1);
		startTask(LCD_Display);
#endif
		return;
	}
#ifndef NoLCD
#if defined(_DEBUG)
	writeDebugStreamLine("Menu launched");
#endif
	LCD_Menu();
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, "Position robot");
	displayLCDCenteredString(1, "press any key");
	Auton_WaitForKeyPress();
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDString(0, 0, "*** KEEP BACK ***");
	displayLCDString(1, 0, " CALIBRATING");
	sleep(1000);
	clearLCDLine(0);
	clearLCDLine(1);
	startTask(LCD_Display);
#endif
#if defined(_DEBUG)
	writeDebugStreamLine("Waiting to reset encoders...");
#endif
	ResetDriveEncoders();
#if defined(_DEBUG)
	writeDebugStreamLine("Ready to roll!");
#endif
}

void Auton_Lift(tVertical Direction = VSTOP, tSpeed Speed = 127, int Time = 0) {
	motor[LiftLeftA] = Direction * Speed;
	motor[LiftLeftB] = Direction * Speed;
	motor[LiftLeftC] = Direction * Speed;
	motor[LiftRightA] = Direction * Speed;
	motor[LiftRightB] = Direction * Speed;
	motor[LiftRightC] = Direction * Speed;
	if (Time > 0)
		sleep(Time);
}

// if sensorvalue == newposition nothing will happen
void Auton_Lift_Targeted(tVertical Direction, tSpeed Speed = 127, int NewPosition = 0) {
	if(SensorValue[LiftEncoder] > NewPosition) {
		while(SensorValue[LiftEncoder] > NewPosition) {
			Auton_Lift(Direction, Speed);
		}
		} else if(SensorValue[LiftEncoder] < NewPosition) {
		while(SensorValue[LiftEncoder] < NewPosition) {
			Auton_Lift(Direction, Speed);
		}
	}
}

void Auton_Claw(bool Open) {
	if(Open) {
		SensorValue[ClawPneumatic] = 0;
		} else {
		SensorValue[ClawPneumatic] = 1;
	}
}

task BatteryMonitor {
	sleep(1000);
	while(true) {
		if(nAvgBatteryLevel < 7000) { // millivolts
			SensorValue[BattALED] = 1;
		}
		if(((float)SensorValue[LCD.Display.BattB] / (float)280) < 7000) { // see above
			SensorValue[BattBLED] = 1;
		}
	}
}
