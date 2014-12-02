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
	LEFT,
	RIGHT,
	CLOCKWISE,
	COUNTERCLOCKWISE
};

typedef enum tVertical {
	UP = 1,
	DOWN = -1,
	VSTOP = 0
};

// Must be defined per robot
void init();
void ResetDriveEncoders();
void ResetLiftEncoders();
tSensors DriveEncoder, LiftEncoder, LiftLimitMinA, LiftLimitMinB, LiftLimitMax;

// Function definitions

// Use __LINE__ as the parameter
void Halt(int Line) {
#if defined(_DEBUG)
	writeDebugStreamLine("Halt command sent from line %i",Line);
#endif
	allMotorsOff();
	stopAllTasks();
}

int Auton_GetMultiplier(tDirection Direction, tMotor WhichMotor) {
	switch(Direction) {
	case STOP:
		return 0;
	case FORWARD:
		switch(WhichMotor) {
		case DriveFrontLeft:
			return -1;
		case DriveFrontRight:
			return 1;
		case DriveRearLeft:
			return -1;
		case DriveRearRight:
			return 1;
		}
	case BACKWARD:
		return -Auton_GetMultiplier(FORWARD, WhichMotor);
	case LEFT:
		switch(WhichMotor) {
		case DriveFrontLeft:
			return 1;
		case DriveFrontRight:
			return 1;
		case DriveRearLeft:
			return -1;
		case DriveRearRight:
			return -1;
		}
	case RIGHT:
		return -Auton_GetMultiplier(LEFT, WhichMotor);
	case CLOCKWISE:
		return -1;
	case COUNTERCLOCKWISE:
		return 1;
	}
	return 0;
}

void Auton_Drive(tDirection Direction = STOP, tSpeed Speed = 127, int Time = 0) {
	motor[DriveFrontLeft] = Speed * Auton_GetMultiplier(Direction,DriveFrontLeft);
	motor[DriveFrontRight] = Speed * Auton_GetMultiplier(Direction,DriveFrontRight);
	motor[DriveRearLeft] = Speed * Auton_GetMultiplier(Direction,DriveRearLeft);
	motor[DriveRearRight] = Speed * Auton_GetMultiplier(Direction,DriveRearRight);
	if(Time > 0) {
		sleep(Time);
		Auton_Drive();
	}
}

#ifdef HasGyro
void Auton_Drive_TurnTo(tDirection Direction, int Heading = 0, tSpeed Speed = 127) {
	Auton_Drive(Direction, Speed);
	if(Direction == CLOCKWISE) {
		while(SensorValue[Gyroscope] > Heading) {
			//writeDebugStreamLine("TARGET=%i, POSITION=%i", Heading, SensorValue[Gyroscope]);
		}
		} else {
		while(SensorValue[Gyroscope] < Heading) {}
	}
	Auton_Drive();
}
#endif

void Auton_Drive_Targeted(tDirection Direction, int Distance = 0, tSpeed Speed = 127) {
	ResetDriveEncoders();
	Auton_Drive(Direction, Speed);
	writeDebugStreamLine("Multiplier is %i", -Auton_GetMultiplier(Direction,DriveRearRight));
	switch(-Auton_GetMultiplier(Direction,DriveRearRight)) {
	case -1:
		writeDebugStreamLine("Current encoder reading is %i, wanting less than %i", SensorValue[DriveEncoder], Distance);
		while(SensorValue[DriveEncoder] > -Auton_GetMultiplier(Direction,DriveRearRight) * Distance) {}
		break;
	case 1:
		writeDebugStreamLine("Current encoder reading is %i, wanting greater than %i", SensorValue[DriveEncoder], Distance);
		while(SensorValue[DriveEncoder] < -Auton_GetMultiplier(Direction,DriveRearRight) * Distance) {}
		break;
	}
	Auton_Drive();
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

void pre_auton() {
	bStopTasksBetweenModes = false;
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
	writeDebugStream(DATE);
	writeDebugStream(" at ");
	writeDebugStreamLine(TIME);
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
	init();
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
	displayLCDString(1, 0, "   CALIBRATING");
	sleep(1000);
	clearLCDLine(0);
	clearLCDLine(1);
	startTask(LCD_Display);
#endif
#if defined(_DEBUG)
	writeDebugStreamLine("Waiting to reset encoders...");
#endif
#ifndef NoInit
#if defined(_DEBUG)
	writeDebugStreamLine("Starting init()");
#endif
	init();
#endif
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
	if (Time > 0) {
		sleep(Time);
		Auton_Lift();
	}
}

// if sensorvalue == newposition nothing will happen
void Auton_Lift_Targeted(tVertical Direction, int NewPosition = 0, tSpeed Speed = 127) {
	if(NewPosition == 0) {
		Auton_Lift(Direction, Speed);
		while(SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0 && vexRT[Btn6U] != 1 && vexRT[Btn6U] != 1) {}
		Auton_Lift();
		return;
	}
	if(Direction == UP) {
		Auton_Lift(Direction, Speed);
		while(-SensorValue[LiftEncoder] < NewPosition && SensorValue[LiftLimitMax] != 0 && vexRT[Btn6U] != 1 && vexRT[Btn6U] != 1) {}
		Auton_Lift();
		} else if(Direction == DOWN) {
		Auton_Lift(Direction, Speed);
		while(-SensorValue[LiftEncoder] > NewPosition && SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0 && vexRT[Btn6U] != 1 && vexRT[Btn6U] != 1) {}
		Auton_Lift();
	}
}
