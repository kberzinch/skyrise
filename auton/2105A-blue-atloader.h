void Auton_Blue_AtLoader() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 725);
	Auton_Drive_Targeted(FORWARD, 50);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 600);
	Auton_Drive_Targeted(BACKWARD, 30);
	//Auton_WaitForKeyPress();
	sleep(1000);
	Auton_Lift_Targeted(DOWN, 450);
	for(int pylon = 1; pylon < 6; pylon++) {
		Auton_Drive_Targeted(FORWARD, 20, 127, 500);
		sleep(250);
		Claw(CLOSE);
		Auton_Lift_Targeted(UP, 700 + lift);
		if(pylon != 5) {
			Auton_Drive_TurnTo(CLOCKWISE, -470, 63);
			sleep(500);
			} else {
			Auton_WaitForKeyPress();
		}
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 1000) {}
		Auton_Drive();
		sleep(750 + lift);
		if(pylon > 3)
			Auton_Lift_Targeted(DOWN,0 + lift, 63);
		else
			Auton_Lift_Targeted(DOWN,0 + lift);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,40);
		if(pylon == 5)
			return;
		Auton_Lift_Targeted(UP,650);
		Auton_Drive_TurnTo(COUNTERCLOCKWISE, 750, 63);
		if(pylon > 3)
			Auton_Drive_TurnTo(COUNTERCLOCKWISE, 770, 63);
		Auton_Drive_Targeted(BACKWARD, 30);
		sleep(1000 + lift);
		Auton_Lift_Targeted(DOWN,450);
		lift += 250;
		//Auton_WaitForKeyPress();
		sleep(500);
#if defined(_DEBUG)
		AutonDataDump();
#endif
	}
}
