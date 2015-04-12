void Auton_Blue_Freedom() {
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
	Auton_Drive_TurnTo(CLOCKWISE, 25);
	/*ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(SensorValue[I2C_1] > -400) {}
	Auton_Drive();
	ResetDriveEncoders();*/
	Auton_Drive_Targeted(FORWARD, 550);
	Lift_Target = 1000;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 900) {}
	sleep(500);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800, 63);
	Auton_Drive_Targeted(FORWARD, 60);
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
	while(nMotorEncoder[DriveFrontRight] > -200) {}
	Auton_Drive();
	ResetDriveEncoders();
	Lift_Target = 400;
	Auton_Drive_TurnTo(CLOCKWISE, -750);
	SensorValue[SolenoidCubes] = 1;
	Auton_Drive_Targeted(FORWARD, 400);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 0);
	Lift_Target = 700;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 600) {}
	Auton_Drive_Targeted(FORWARD, 200);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 100);
	Auton_Lift_Targeted(UP, 400);
	Lift_Target = 500;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	ResetDriveEncoders();
	Auton_Drive(BACKWARD);
	nMotorEncoder[DriveFrontRight] = 0;
	while(nMotorEncoder[DriveFrontRight] > -300) {}
	Auton_Drive();
	ResetDriveEncoders();
	//Lift_Target = 150;
	//while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 250) {}
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 750);
	Auton_Drive_Targeted(FORWARD, 50);
	Lift_Target = 1000;
	Auton_Drive_Targeted(FORWARD, 400);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 900) {}
	Auton_Drive_Targeted(FORWARD, 100);
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
	while(nMotorEncoder[DriveFrontRight] > -200) {}
	Auton_Drive();
}
