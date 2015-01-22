task LiftToAutoloader {
	Auton_Lift_Targeted(UP,415);
}

task LiftToAutoloaderPlusALittle {
	Auton_Lift_Targeted(UP,425);
}

void Auton_Blue_AtLoader() {
	long Watchdog;
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD, 25);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	// FIRST PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	Auton_Lift_Targeted(DOWN,200,63);
	Claw(OPEN);
	// FIRST PYLON SCORED
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-170);
	Auton_Drive_Targeted(FORWARD,80,127,500);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,750);
	// SECOND PYLON COLLECTED
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
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
	return;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-100);
	Auton_Drive_Targeted(FORWARD,150);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	// THIRD PYLON COLLECTED
	Auton_Lift(UP);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-400);
	Auton_Lift_Targeted(UP,1400);
	Auton_Drive(FORWARD);
	Watchdog = nSysTime;
	while(SensorValue[AlignBarButton] != 0 && nSysTime - Watchdog < 2000) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,600,63);
	Claw(OPEN);
	Auton_Drive_Targeted(BACKWARD,100);
	startTask(LiftToAutoloaderPlusALittle);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-100);
	Auton_Drive_Targeted(FORWARD,150);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	Auton_Lift(UP);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-200);
	Auton_Lift_Targeted(UP,1400);
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
