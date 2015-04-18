void Auton_Blue_Freedom() {
	ReleaseLift();
	Lift_Target = 400;
	Auton_Lift_Targeted(UP,300);
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(FORWARD, 400);
	SensorValue[SolenoidCubes] = 1;
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 1);
	Auton_Lift(DOWN, 127, 500, true); // THIS CONSTITUTES A PAUSE.
	Lift_Target = 150;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 100) {}
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(SensorValue[I2C_1] > -400) {}
	Auton_Drive();
	ResetDriveEncoders();
	Auton_Drive_Targeted(FORWARD, 650);
	Lift_Target = 1000;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 900) {}
	sleep(500);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800, 63);
	Auton_Drive_Targeted(FORWARD, 200);
	sleep(500);
	Lift_Target = 800;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 850) {}
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
	Auton_Drive_TurnTo(CLOCKWISE, 150);
	Auton_Drive_Targeted(FORWARD, 1175);
	ResetDriveEncoders();
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 750, 63);
	SensorValue[SolenoidCubes] = 1;
	Auton_Drive_Targeted(FORWARD, 300);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 1);
	Auton_Lift(DOWN, 127, 500, true); // THIS CONSTITUTES A PAUSE.
	Lift_Target = 700;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 600) {}
	Auton_Drive_Targeted(FORWARD, 400);
	IsStabilizerRunning = false;
	sleep(500);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	Auton_Drive_Targeted(BACKWARD, 1200); //1200
	ResetDriveEncoders();
	Auton_Drive_TurnTo(CLOCKWISE, 750, 63);
}
