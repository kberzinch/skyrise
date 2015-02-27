void Auton_Red_AtLoader() {
	int lift = 0;
	long Watchdog;
	Auton_Lift_Targeted(UP, 725);
	Auton_Drive_Targeted(FORWARD, 50);
	Auton_Drive_TurnTo(CLOCKWISE, -600);
	Auton_Drive_Targeted(BACKWARD, 80);
	sleep(500);
	Auton_Lift_Targeted(DOWN, 450);
	// START FIRST PYLON
	sleep(500);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP, 600 + lift);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,0 + lift);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,30);
	Auton_Lift_Targeted(UP,650);
	Auton_Drive_TurnTo(CLOCKWISE, -200);
	sleep(500 + lift);
	Auton_Lift_Targeted(DOWN,450);
	lift += 250;
	// START SECOND PYLON
	sleep(500);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP, 600 + lift);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,0 + lift);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,30);
	Auton_Lift_Targeted(UP,650);
	Auton_Drive_TurnTo(CLOCKWISE, -250);
	sleep(500 + lift);
	Auton_Lift_Targeted(DOWN,450);
	lift += 200;
	// START THIRD PYLON
	sleep(500);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP, 600 + lift);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignButton] == 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,0 + lift);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,30);
	Auton_Lift_Targeted(UP,650);
	Auton_Drive_TurnTo(CLOCKWISE, -200);
	sleep(500 + lift);
	Auton_Lift_Targeted(DOWN,450);
	lift += 250;
}
