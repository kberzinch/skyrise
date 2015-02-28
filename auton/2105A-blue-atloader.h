void Auton_Blue_AtLoader() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 725);
	Auton_Drive_Targeted(FORWARD, 50);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 600);
	Auton_Drive_Targeted(BACKWARD, 30);
	sleep(1000);
	Auton_Lift_Targeted(DOWN, 450);
	while(true) {
		Auton_Drive_Targeted(FORWARD, 20, 127, 500);
		sleep(250);
		Claw(CLOSE);
		if(lift == 1250)
			lift += 250;
		Auton_Lift_Targeted(UP, 650 + lift);
		Auton_Drive_TurnTo(CLOCKWISE, -690);
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 1000) {}
		Auton_Drive();
		sleep(750 + lift);
		Auton_Lift_Targeted(DOWN,0 + lift);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,40);
		Auton_Lift_Targeted(UP,650);
		Auton_Drive_TurnTo(COUNTERCLOCKWISE, 600);
		Auton_Drive_Targeted(BACKWARD, 30);
		sleep(750 + lift);
		Auton_Lift_Targeted(DOWN,450);
		lift += 250;
#if defined(_DEBUG)
		AutonDataDump();
#endif
	}
}
