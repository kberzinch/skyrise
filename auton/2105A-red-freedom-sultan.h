void Auton_Red_Freedom() {
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenterA] > -100) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 200;
	Auton_Lift_Targeted(UP,200);
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(FORWARD, 330);
	sleep(500);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, -50);
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
	Auton_Drive_Targeted(FORWARD, 575);
	Lift_Target = 1000;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 900) {}
	sleep(500);
	Auton_Drive_TurnTo(CLOCKWISE, -800, 63);
	Auton_Drive_Targeted(FORWARD, 80);
	sleep(500);
	Lift_Target = 800;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 800) {}
	sleep(500);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	Lift_Target = 1000;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 900) {}
	sleep(500);
	ResetDriveEncoders();
	Auton_Drive(BACKWARD);
	nMotorEncoder[DriveFrontRight] = 0;
	while(nMotorEncoder[DriveFrontRight] > -250) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 400;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -180);
	Auton_Drive_Targeted(FORWARD, 1350);
	ResetDriveEncoders();
	Auton_Drive_TurnTo(CLOCKWISE, -700, 63);
	SensorValue[SolenoidCubes] = 1;
	Auton_Drive_Targeted(FORWARD, 220);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 1);
	Lift_Target = 700;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 600) {}
	Auton_Drive_Targeted(FORWARD, 400);
	sleep(150);
	IsStabilizerRunning = false;
	SensorValue[SolenoidCubes] = 0;
	sleep(150);
	Auton_Drive_Targeted(BACKWARD, 200); //1200 for optimal driver start position
	//Auton_Drive_TurnTo(COUNTERCLOCKWISE, -750, 63);
}
