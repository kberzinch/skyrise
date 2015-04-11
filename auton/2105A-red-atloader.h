void Auton_Red_AtLoader() {
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenter] < 50) {}
	Auton_Drive();
	ResetDriveEncoders();
	Auton_Lift_Targeted(UP,200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_Targeted(BACKWARD, 80);
	tVertical Direction = DOWN;
	int Speed = 30;
	motor[LiftLeftA] = Direction * Speed;
	motor[LiftLeftB] = Direction * Speed;
	motor[LiftRightA] = Direction * Speed;
	motor[LiftRightB] = Direction * Speed;
	Pylon_Target = 2700;
	startTask(PylonLock);
	while(SensorValue[PylonPot] < 2700) {}
	Auton_Drive_TurnTo(CLOCKWISE, 50);
	sleep(500);
	SensorValue[SolenoidPylons] = 1;
	sleep(500);
	Lift_Target = 200;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 160) {}
	Pylon_Target = 1200;
	while(SensorValue[PylonPot] > 1200) {}
	sleep(500);
	Lift_Target = 0;
	sleep(500);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 20) {}
	SensorValue[SolenoidPylons] = 0;
	// clean up after yourself
	IsStabilizerRunning = false;
	stopTask(PylonLock);
	return;
}

// 1200 = skyrise base
// 2700 = autoloader
