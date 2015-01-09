void Auton_Blue_Freedom() {
	Collection(-127);
	sleep(400);
	Collection();
	Auton_Drive(FORWARD);
	sleep(700);
	Collection(127);
	sleep(450);
	Auton_Drive();
	sleep(500);
	Collection();
	Auton_Drive(COUNTERCLOCKWISE,127,1100);
	Auton_Drive(FORWARD,127,1200);
	Lift_Target = 90;
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	sleep(2000);
	Auton_Drive(COUNTERCLOCKWISE,127,400);
	Auton_Drive(FORWARD,127,150);
	Collection(-127);
	sleep(500);
	Collection();
	sleep(500);
	Collection(-127);
	sleep(1000);
	Collection();
	Auton_Drive(BACKWARD,127,500);
	Lift_Target = 0;

}
