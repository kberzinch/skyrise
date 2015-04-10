void Auton_Red_AtLoader() {
	nMotorEncoder[DriveCenter] = 0;
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenter] < 50) {}
	Auton_Drive();
	ResetDriveEncoders(); // clean up after yourself
	Auton_Lift_Targeted(UP,200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_Targeted(BACKWARD, 70);
	Auton_Drive(FORWARD, 127, 10);
	allMotorsOff();
	Set_Lift_Target();
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Pylon_Target = 2700;
	startTask(PylonLock);
	while(SensorValue[PylonPot] < 2700) {}
	sleep(500);
	SensorValue[SolenoidPylons] = 1;
	sleep(500);
	Lift_Target = 200;
	while(SensorValue[LiftEncoder] < 200) {}
	// clean up after yourself
	IsStabilizerRunning = false;
	stopTask(PylonLock);
	return;
}

// 1200 = skyrise base
// 2700 = autoloader
