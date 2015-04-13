// This robot is not precise enough to reliably score pylons.
// This is a very serious attempt to do so.

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
	Auton_Drive_Targeted(FORWARD, 150);
	SensorValue[SolenoidCubes] = 0;
	sleep(500);
	Lift_Target = 400;
	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) < 200) {}
	Auton_Drive_Targeted(BACKWARD, 60);
	Lift_Target = -100;
	SensorValue[SolenoidPylons] = 1;


	while(((SensorValue[I2C_3] - SensorValue[I2C_4]) / 2) > 0) {}
	Auton_Drive_TurnTo(CLOCKWISE, -620); //770
	ResetDriveEncoders();
	Auton_Drive(LEFT);
	while(nMotorEncoder[DriveCenterA] < 600) {}
	Auton_Drive();
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(200);

	Auton_Drive(RIGHT);
	while(nMotorEncoder[DriveCenterA] > -150) {}
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
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -600);
	//Auton_Drive_Targeted(BACKWARD, 50);
	//Auton_Drive_TurnTo(COUNTERCLOCKWISE, -50);
	Auton_Drive_Targeted(FORWARD, 240);
	Auton_Drive_TurnTo(CLOCKWISE, -430, 63);
	Auton_Drive(BACKWARD,80,100);
	sleep(1000);
	IsStabilizerRunning = false;
	Auton_Lift_Targeted(DOWN, 1);
	Auton_Lift(DOWN, 30);
	sleep(1000);
	SensorValue[SolenoidPylons] = 1;
	return;
	sleep(1000);
	Auton_Lift_Targeted(UP,100);
	Auton_Drive_Targeted(BACKWARD, 100);
}
