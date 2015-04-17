void Auton_Blue_AtLoader() {
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
	Auton_Drive_Targeted(FORWARD, 150);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	Lift_Target = 400;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 300) {}
	Auton_Drive_Targeted(BACKWARD, 60);
	Lift_Target = -100;
	SensorValue[SolenoidPylons] = 1;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 0) {}
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800); //770
	ResetDriveEncoders();
	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenterA] > -600) {}
	Auton_Drive();
	Auton_Drive_Targeted(FORWARD, 140);
	sleep(500);
	Auton_Drive(LEFT);
	while(nMotorEncoder[DriveCenterA] < 150) {}
	Auton_Drive();
	sleep(250);
	SensorValue[SolenoidPylons] = 0;
	sleep(500);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(UP,200,63);
	Lift_Target = 200;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 500);
	Lift_Target = 100;
	Auton_Drive_TurnTo(CLOCKWISE, 500); // 550
	Auton_Drive_Targeted(FORWARD, 200); // 240
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 430, 63); // 430 // 380
	Auton_Drive(BACKWARD,63,100); // 100 msec
	sleep(1000);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 1, 127, 500);
	Auton_Lift(DOWN, 30);
	sleep(1000);
	SensorValue[SolenoidPylons] = 1;
	sleep(1000);
	Auton_Lift_Targeted(UP,100);
	Auton_Drive_Targeted(BACKWARD, 100);
	Auton_Drive_TurnTo(CLOCKWISE, -100);
	Auton_Drive_Targeted(FORWARD, 200);
	SensorValue[SolenoidCubes] = 1;
	Auton_Lift_Targeted(DOWN, 1);
	Auton_Lift(DOWN, 127, 500, true);
	Auton_Lift_Targeted(UP, 300);
	Lift_Target = 400;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 400, 63); // 430
	Auton_Drive_Targeted(FORWARD, 300);
	SensorValue[SolenoidCubes] = 0;
	Auton_Drive_Targeted(BACKWARD, 200);
}
