void Auton_Red_AtLoader() {
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenterA] > -100) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 50;
	Auton_Lift_Targeted(UP,50);
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 100);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	Lift_Target = 400;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 200) {}
	Auton_Drive_Targeted(BACKWARD, 60);
	Lift_Target = -100;
	SensorValue[SolenoidPylons] = 1;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 0) {}
	Auton_Drive_TurnTo(CLOCKWISE, -570); //770
	Auton_Drive_Targeted(FORWARD, 200);
	sleep(500);
	SensorValue[SolenoidPylons] = 0;
	sleep(500);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(UP,200,63);
	Lift_Target = 200;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 75);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -350);
	//Auton_Drive_Targeted(BACKWARD, 50);
	//Auton_Drive_TurnTo(COUNTERCLOCKWISE, -50);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 0);
	Lift_Target = -100;
	Auton_Drive_Targeted(FORWARD, 400);
	SensorValue[SolenoidPylons] = 1;
}
