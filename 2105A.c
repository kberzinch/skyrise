#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    PowerExpander,  sensorAnalog)
#pragma config(Sensor, in2,    Gyroscope,      sensorGyro)
#pragma config(Sensor, in3,    LiftLimitMinA,  sensorAnalog)
#pragma config(Sensor, dgtl1,  DriveEncoderLeft, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  DriveEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  LiftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  SolenoidA,      sensorDigitalOut)
#pragma config(Sensor, dgtl8,  AlignButton,    sensorTouch)
#pragma config(Motor,  port1,           LiftLeftA,     tmotorVex393_HBridge, openLoop, reversed, encoderPort, dgtl1)
#pragma config(Motor,  port2,           LiftRightA,    tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port3,           LiftLeftB,     tmotorVex393_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port4,           DriveFrontRight, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl3)
#pragma config(Motor,  port5,           DriveRearRight, tmotorVex393_MC29, openLoop, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port6,           DriveFrontLeft, tmotorVex393_MC29, openLoop, driveLeft, encoderPort, dgtl3)
#pragma config(Motor,  port7,           DriveRearLeft, tmotorVex393_MC29, openLoop, driveRight, encoderPort, dgtl3)
#pragma config(Motor,  port8,           LiftRightB,    tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl1)
#pragma config(Motor,  port9,           LiftLeftC,     tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl1)
#pragma config(Motor,  port10,          LiftRightC,    tmotorVex393_HBridge, openLoop, encoderPort, dgtl1)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int LastPosition = 0;
int NumberOfOpens = 0;
int NumberOfCloses = 0;
long TimeOpen = 0;
long TimeClosed = 0;
long LastSwitched = nSysTime;

#define HasGyro
#define Pneumatics
//#define MultiDriveEncoders
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif
//#include "core\v3\batteryindicators.h"
#include "core\v3\acore.h"
#include "usercontrol\2105A-john.h"
#include "auton\2105A-blue-atloader.h"
#include "auton\2105A-red-atloader.h"
#include "auton\2105A-ps.h"
#include "misc\2105A-autonmanager.h"

void ResetDriveEncoders() {
	SensorValue[DriveEncoder] = 0;
	SensorValue[DriveEncoderLeft] = 0;
}

void init() {
	SensorValue[LiftEncoder] = 0;
	ResetDriveEncoders();
	SensorValue[Gyroscope] = 0;
}
