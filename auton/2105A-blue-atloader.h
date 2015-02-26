void Auton_Blue_AtLoader() {
	long Watchdog;
	Auton_Lift_Targeted(UP, 400);
	Auton_Drive_Targeted(RIGHT, 110);
	while(true) {
		Auton_Drive_Targeted(FORWARD, 80);
		sleep(1000);
		Claw(CLOSE);
		Auton_Lift_Targeted(UP, 800);
		Auton_Drive_Targeted(BACKWARD, 40);
		Auton_Drive_TurnTo(CLOCKWISE, -1700);
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 2000) {}
		Auton_Drive();
		sleep(1000);
		Auton_Lift_Targeted(DOWN,0);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,50);
		Auton_Lift_Targeted(UP,400);
		Auton_Drive_TurnTo(COUNTERCLOCKWISE, -300);
		sleep(1000);
	}
}
