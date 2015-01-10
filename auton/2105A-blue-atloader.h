task LiftToAutoloader {
	Auton_Lift_Targeted(UP,415);
}

void Auton_Blue_AtLoader() {
	//Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,400);
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-650);
	Auton_Drive_Targeted(FORWARD,90);
	sleep(500);
	Auton_Lift_Targeted(DOWN,0,63);
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,70);
	sleep(100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-450);
	sleep(500);
	Auton_Drive_Targeted(FORWARD,200);
	// PICKED UP SECOND PYLON
	sleep(250);
	Auton_Lift_Targeted(UP,750);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,100);
	sleep(500);
	Auton_Lift_Targeted(DOWN,200,127,2000);
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-440);
	sleep(250);
	Auton_Drive_Targeted(FORWARD,150);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-300);
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_Targeted(FORWARD,160);
	sleep(250);
	Auton_Lift_Targeted(DOWN,600,63);
	Auton_Drive_Targeted(BACKWARD,100);
	startTask(LiftToAutoloader);
}
