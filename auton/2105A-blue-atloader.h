task LiftToAutoloader {
	Auton_Lift_Targeted(UP,415);
}

task LiftToAutoloaderPlusALittle {
	Auton_Lift_Targeted(UP,425);
}

void Auton_Blue_AtLoader() {
	//Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD, 50);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive(FORWARD);
	while(SensorValue[AlignBarButton] != 0) {}
	Auton_Lift_Targeted(DOWN,200,63);
	Claw(OPEN);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-100);
	Auton_Drive_Targeted(FORWARD,200);
	Claw(CLOSE);
	// PICKED UP SECOND PYLON
	Auton_Lift_Targeted(UP,750);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive(FORWARD);
	while(SensorValue[AlignBarButton] != 0) {}
	Auton_Drive();
	sleep(500);
	Auton_Lift_Targeted(DOWN,200,127,2000);
	Claw(OPEN);
	startTask(LiftToAutoloaderPlusALittle);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-100);
	Auton_Drive_Targeted(FORWARD,150);
	Claw(CLOSE);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_Targeted(FORWARD,160);
	return;
	sleep(250);
	Auton_Lift_Targeted(DOWN,600,63);
	Auton_Drive_Targeted(BACKWARD,100);
	startTask(LiftToAutoloader);
}
