void Auton_Red_Freedom() {
	// STARTING POSITION:
	// Cube in lower position
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenterA] > -100) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 400;
	Auton_Lift_Targeted(UP,300);
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(FORWARD, 330);
	sleep(500);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 0);
	/*Lift_Target = -100;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > -50) {}*/
	sleep(250);
	Lift_Target = 150;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 100) {}
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -25);
	ResetDriveEncoders();
	Auton_Drive(LEFT);
	while(SensorValue[I2C_1] < 400) {}
	Auton_Drive();
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 450);
	Lift_Target = 1100;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 1000) {}
	sleep(500);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 63);
	Auton_Drive_Targeted(FORWARD, 80);
	sleep(500);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	ResetDriveEncoders();
	Auton_Drive(BACKWARD);
	nMotorEncoder[DriveFrontRight] = 0;
	while(nMotorEncoder[DriveFrontRight] > -200) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 0;
}
