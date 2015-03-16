void Auton_Blue_AtLoader() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 725);
	Auton_Drive_Targeted(FORWARD, 50);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 650);
	Auton_Drive_Targeted(BACKWARD, 30);
	sleep(1000);
	Auton_Lift_Targeted(DOWN, 450);
	for(int pylon = 1; pylon < 3; pylon++) {
		Auton_Drive_Targeted(FORWARD, 20, 127, 500);
		sleep(250);
		writeDebugStreamLine("!!!%i",SensorValue[SolenoidA]);
		Claw(CLOSE);
		writeDebugStreamLine("!!!%i",SensorValue[SolenoidA]);
		Auton_Lift_Targeted(UP, 700 + lift);
		Auton_Drive_TurnTo(CLOCKWISE, -650, 63);
		Auton_Drive(FORWARD);
		Watchdog = nSysTime;
		while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 1000) {}
		Auton_Drive();
		Auton_Lift_Targeted(DOWN,100 + lift, 50);
		Claw(OPEN);
		Auton_Drive_Targeted(BACKWARD,40);
		Auton_Lift_Targeted(UP,650);
		Auton_Drive_TurnTo(COUNTERCLOCKWISE, 650, 63);
		Auton_Drive_Targeted(BACKWARD, 30);
		Auton_Lift_Targeted(DOWN,450);
		lift += 200;
		sleep(500);
	}
}
