void Auton_Blue_Freedom() {
	Collection(-127);
	sleep(450);
	Collection();
	Auton_Drive_Targeted(FORWARD,300);
	Collection(127);
	sleep(700);
	Collection();
	Auton_Drive_Targeted(BACKWARD,250);
	Auton_Drive(COUNTERCLOCKWISE);
	ResetDriveEncoders();
	while(SensorValue[DriveEncoder] < 150) {}
	Auton_Drive();
	Auton_Drive_Targeted(FORWARD,400);
	Auton_Drive(CLOCKWISE);
	ResetDriveEncoders();
	while(SensorValue[DriveEncoder] > -670) {}
	Auton_Drive();
	Lift_Target = 50;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD,220);
	Collection(-127);
	sleep(500);
	Collection();
	Auton_Drive_Targeted(BACKWARD,400);
	Auton_Drive(CLOCKWISE);
	ResetDriveEncoders();
	while(SensorValue[DriveEncoder] > -200) {}
	Auton_Drive();
	Lift_Target = 90;
	Auton_Drive_Targeted(FORWARD,340); // increase probably
	sleep(1000);
	Collection(-127);
	sleep(1000);
	Auton_Drive(BACKWARD,127,500);
}
