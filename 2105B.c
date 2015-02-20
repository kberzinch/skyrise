#pragma config(Sensor, in1,    Gyroscope,      sensorGyro)
#pragma config(Sensor, dgtl1,  EncoderLiftRight, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  EncoderLiftLeft, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  CollectionEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  DriveEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  IndicatorBattA, sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, DONOTUSE,       sensorNone)
#pragma config(Sensor, dgtl11, SolenoidB,      sensorDigitalOut)
#pragma config(Sensor, dgtl12, SolenoidA,      sensorDigitalOut)
#pragma config(Motor,  port1,           DriveFrontLeft, tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           DriveFrontRight, tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           DriveRearLeft, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           DriveRearRight, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           LiftLeftA,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LiftLeftB,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LiftRightA,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LiftRightB,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           CollectionA,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          CollectionB,   tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// TODO: Tilt=slow

#define HasGyro
#define NoPowerExpander
#define NoLiftLimits
#define OneLiftEncoder
#if defined(_DEBUG)
const string FILE = __FILE__;
#endif
//#include "core\v3\batteryindicators.h"
#include "core\v3\core.h"

void Collection(int Position, int Timeout = 3000) {
	const int StartTime = nSysTime;
	if(SensorValue[CollectionEncoder] > Position) {
		while(SensorValue[CollectionEncoder] > Position && (nSysTime - StartTime) < Timeout) {
			motor[CollectionA] = 127;
			motor[CollectionB] = 127;
		}
		} else if(SensorValue[CollectionEncoder] < Position) {
		while(SensorValue[CollectionEncoder] < Position && (nSysTime - StartTime) < Timeout) {
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
		}
	}
	motor[CollectionA] = 0;
	motor[CollectionB] = 0;
#if defined(_DEBUG)
	if(!((nSysTime - StartTime) < Timeout)) {
		writeDebugStreamLine("**WARNING: Collection to position %i timed out after %i ms (encoder reading %i)", Position, Timeout, SensorValue[CollectionEncoder]);
	}
#endif
}

#include "misc\2105B-stabilizers.h"
#include "usercontrol\2105B-bob.h"
//#include "auton\2105B-blue-atloader.h"
//#include "auton\2105B-red-atload.h"
#include "auton\2105B-blue-freedom.h"
//#include "auton\2105B-red-freedom.h"
#include "auton\2105B-red-freedom-thingum.h"
#include "misc\2105B-autonmanager.h"

void ResetDriveEncoders() {
	SensorValue[DriveEncoder] = 0;
}

void init() {
	PID_Drive.Sensor = DriveEncoder;
	PID_Drive.IntegralLimit = 100;
	PID_Drive.Kp = 0.7;
	PID_Drive.Ki = 0.001;
	PID_Drive.Kd = 0.2;
	PID_Drive_TurnTo.Sensor = Gyroscope;
	PID_Drive_TurnTo.IntegralLimit = 200;
	PID_Drive_TurnTo.Kp = 0.7;
	PID_Drive_TurnTo.Ki = 0.001;
	PID_Drive_TurnTo.Kd = 0.2;
	SensorValue[EncoderLiftLeft] = 0;
	SensorValue[EncoderLiftRight] = 0;
	SensorValue[Gyroscope] = 0;
	SensorValue[CollectionEncoder] = 0;
	SensorValue[SolenoidA] = 0;
	SensorValue[SolenoidB] = 0;
}
