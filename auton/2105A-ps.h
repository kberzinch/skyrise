void Auton_Progskills() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 450);
	for(int pylon = 1; pylon < 7; pylon++) {
		Auton_Drive_Targeted(FORWARD, 50, 127, 500);
		sleep(100);
		Claw(CLOSE);
		Auton_Lift_Targeted(UP, 700 + lift);
		Auton_WaitForKeyPress(200);
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 1000) {}
		Auton_Drive();
		sleep(lift / 2);
		if(pylon == 4) {
			sleep(1000);
		}
		if(pylon > 3)
			Auton_Lift_Targeted(DOWN,0 + lift, 63);
		else
			Auton_Lift_Targeted(DOWN,0 + lift);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,100);
		if(pylon == 6)
			break;
		if(pylon == 3) {
			Auton_Lift_Targeted(DOWN,450);
			} else {
			if(SensorValue[LiftEncoder] < -450) {
				Auton_Lift_Targeted(DOWN,450);
				} else {
				Auton_Lift_Targeted(UP,450);
			}
		}
		lift += 250;
		while(!Lift_TrippedMin()) {}
		while(Lift_TrippedMin()) {}
		sleep(200);
	}
	Auton_Lift_Targeted(DOWN,0);
	Auton_WaitForKeyPress();
	Auton_Drive_Targeted(FORWARD, 200);
	Claw(CLOSE);
	Auton_Drive(COUNTERCLOCKWISE, 127, 500);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD, 10);
}
