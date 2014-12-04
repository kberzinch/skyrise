task LiftToAutoloader {
	Auton_Lift_Targeted(UP,400);
}

void Auton_Blue_AtLoader() {
	Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,400);
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,90);
	sleep(250);
	Auton_Lift_Targeted(DOWN,0,63);
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-160);
	sleep(250);
	Auton_Drive_Targeted(FORWARD,200);
	// PICKED UP SECOND PYLON
	sleep(250);
	Auton_Lift_Targeted(UP,750);
	sleep(250);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,100);
	sleep(250);
	Auton_Lift_Targeted(DOWN,200);
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-160);
	sleep(250);
	Auton_Drive_Targeted(FORWARD,150);
	sleep(250);
	Auton_Lift_Targeted(UP,1100);
	sleep(250);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,100);
	sleep(250);
	Auton_Lift_Targeted(DOWN,700);
	Auton_Drive_Targeted(BACKWARD,100);
}
