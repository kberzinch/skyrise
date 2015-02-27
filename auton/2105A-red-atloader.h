void Auton_Red_AtLoader() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 450);
	Auton_Drive_Targeted(LEFT, 110);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD, 30);
	while(true) {
		sleep(1000);
		Claw(CLOSE);
		Auton_Lift_Targeted(UP, 700 + lift);
		Auton_Drive_TurnTo(CLOCKWISE, -1700);
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 2000) {}
		Auton_Drive();
		sleep(1000);
		Auton_Lift_Targeted(DOWN,0 + lift);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,30);
		Auton_Lift_Targeted(UP,650);
		Auton_Drive_TurnTo(COUNTERCLOCKWISE, -300);
		sleep(500);
		Auton_Drive_Targeted(RIGHT, 50);
		sleep(1000);
		Auton_Lift_Targeted(DOWN,450);
		lift += 200;
	}
}
