task LiftTo1K {
	Auton_Lift_Targeted(UP,1100);
}

void Auton_Red_AtLoader() {
	long Watchdog;
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD, 50);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	// FIRST PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,700);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	Auton_Lift_Targeted(DOWN,200,63);
	Claw(OPEN);
	// FIRST PYLON SCORED
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,180);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,800);
	// SECOND PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,700);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,200,127,2000);
	Claw(OPEN);
	// SECOND PYLON SCORED
	startTask(LiftToAutoloaderPlusALittle);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,180);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	startTask(LiftTo1K);
	// THIRD PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,700);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,100);
	// THIRD PYLON SCORED
	startTask(LiftToAutoloaderPlusALittle);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,200);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	Auton_Lift(UP);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,500);
	Auton_Lift_Targeted(UP,1500);
	return;
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	sleep(250);
	Auton_Drive_Targeted(BACKWARD,100);
	startTask(LiftToAutoloader);
}
