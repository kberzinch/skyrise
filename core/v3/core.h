// Initial setup
#pragma systemFile
#pragma platform(VEX2)
#pragma competitionControl(Competition)
#if defined(_DEBUG)
#pragma DebuggerWindows("debugStream")
#endif
#ifndef NoLCD
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

typedef enum tSide {
	LEFT,
	RIGHT
};

// Must be defined per robot
void init();
void ResetDriveEncoders();
void ResetLiftEncoders();
tMotor DriveLeftA, DriveLeftB, DriveRightA, DriveRightB;
tSensors DriveEncoderLeft, DriveEncoderRight, LiftEncoder, LiftLimitA, LiftLimitB;

// Function definitions
void Halt(int Line) {
#if defined(_DEBUG)
	writeDebugStreamLine("Halt command sent from line %i",Line);
#endif
	allMotorsOff();
	stopAllTasks();
}

void Die() {
#if defined(_DEBUG)
	VERIFY(false);
#endif
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
void Auton_Drive_Turn(tDirection Direction, tSpeed Speed = 0, int Distance = 0) {
	Auton_Drive(Direction, Speed);
	while(SensorValue[DriveEncoderLeft] > 10);
}
#endif

void Auton_Drive_Linear(tDirection Direction, tSpeed Speed = 0, int Distance = 0) {
	Auton_Drive(Direction, Speed);
	while(SensorValue[DriveEncoderLeft] > 0);
}

void Auton_Drive_Targeted(tDirection Direction = STOP, tSpeed Speed = 0, int Distance = 0) {
#ifdef HasGyro
	if(Direction == CLOCKWISE || Direction == COUNTERCLOCKWISE) {
		Auton_Drive_Turn(Direction, Speed, Distance);
#endif
	}
}

void Auton_WaitForKeyPress(int Sleep = 0) {
	while(nLCDButtons == 0)
		EndTimeSlice();
	while(nLCDButtons != 0)
		EndTimeSlice();
	sleep(Sleep);
}

void pre_auton() {
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
	writeDebugStreamLine(" - Batt A   %1.2fv", (float)nImmediateBatteryLevel / (float)1000);
#ifndef NoPowerExpander
	writeDebugStreamLine(" - Batt B   %1.2fv", (float)SensorValue[PowerExpander] / (float)280);
#endif
	writeDebugStreamLine(" - Backup   %1.2fv", (float)BackupBatteryLevel / (float)1000);
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
	displayLCDCenteredString(0, "Position robot then");
	displayLCDCenteredString(1, "press any key");
	Auton_WaitForKeyPress();
	displayLCDString(0, 0, "*** KEEP BACK ***");
	displayLCDString(1, 0, " CALIBRATING...");
	sleep(1000);
	clearLCDLine(0);
	clearLCDLine(1);
#ifndef NoLCD
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
