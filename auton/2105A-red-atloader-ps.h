void Auton_Progskills() {
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
	Auton_Drive_Targeted(BACKWARD,50);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,180);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,800);
	// SECOND PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,150);
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
	Auton_Drive_Targeted(BACKWARD,50);
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
	sleep(1000);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,30);
	Auton_Lift_Targeted(UP,500);
	// THIRD PYLON SCORED
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,250);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	// FOURTH PYLON COLLECTED
	Auton_Lift(UP);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,700);
	Auton_Lift_Targeted(UP,1400);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	sleep(250);
	Auton_Drive_Targeted(BACKWARD,50);
	// FOURTH PYLON SCORED
	startTask(LiftToAutoloader);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,200);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	Auton_Lift(UP);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,500);
	Auton_Lift_Targeted(UP,1700);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(1000);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_WaitForKeyPress();
	Auton_Drive_Targeted(FORWARD,300);
	Claw(CLOSE);
	Auton_Drive_Targeted(BACKWARD,400);
	Auton_WaitForKeyPress();
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_Targeted(FORWARD,400,63);
	sleep(1000);
	writeDebugStreamLine("Going left");
	Auton_Drive(LEFT);
	sleep(600);
	Auton_Drive();
	Auton_Lift_Targeted(DOWN,500);
	sleep(1000);
	Claw(OPEN);
	sleep(1000);
	Auton_Drive(LEFT);
	sleep(750);
	Auton_Drive();
}
