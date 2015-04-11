void Auton_Red_Freedom() {
	// STARTING POSITION:
	// Cube in lower position
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenter] < 50) {}
	Auton_Drive();
	ResetDriveEncoders();
	Auton_Lift_Targeted(UP,200);
	Set_Lift_Target();
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(FORWARD, 400);
	sleep(500);
	Lift_Target = -100;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > -75) {}
	Lift_Target = 970;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 750) {}
	ResetDriveEncoders();
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -25);
	ResetDriveEncoders();
	Auton_Drive(LEFT);
	while(nMotorEncoder[DriveCenter] > -100) {}
	Auton_Drive();
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 400);
	sleep(500);
	Auton_Drive_TurnTo(CLOCKWISE, -750);
	Auton_Drive_Targeted(FORWARD, 50);
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
