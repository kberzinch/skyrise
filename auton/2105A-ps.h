#define ProgrammingSkills
void Auton_Progskills() {
	Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,400);
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	// PICKED UP FIRST PYLON
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,90);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,0,63);
	// FIRST PYLON STASHED
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,70);
	sleep(100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-130);
	sleep(500);
	Auton_Drive_Targeted(FORWARD,200);
	// PICKED UP SECOND PYLON
	sleep(250);
	Auton_Lift_Targeted(UP,750);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,100);
	sleep(250);
	Auton_Lift_Targeted(DOWN,200);
	// SECOND PYLON STASHED
	sleep(100);
	startTask(LiftToAutoloader);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-170);
	sleep(250);
	Auton_Drive_Targeted(FORWARD,170);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	// PICKED UP THIRD PYLON
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-400);
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_Targeted(FORWARD,160);
	sleep(1000);
	// THIRD PYLON STASHED
	Auton_Lift_Targeted(DOWN,600,63);
	Auton_Drive_Targeted(BACKWARD,100);
	startTask(LiftToAutoloader);

	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Lift_Targeted(UP,400);
	// PICKED UP FOURTH PYLON
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 200);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-250);
	Auton_Lift_Targeted(UP,1200);
	// FOURTH PYLON
	Auton_Drive_Targeted(FORWARD,90);
	sleep(250);
	Auton_Lift_Targeted(DOWN,0,63);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Lift_Targeted(UP,1200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_WaitForKeyPress();
	Auton_Drive_Targeted(FORWARD,200);
	Auton_Lift_Targeted(UP,1700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-600);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD,50);
	sleep(3000);
	Auton_Lift_Targeted(DOWN,300);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Lift_Targeted(UP,1200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_WaitForKeyPress();
	Auton_Lift_Targeted(UP,1700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-1000, 63);
	Auton_Drive_Targeted(FORWARD,50,63);
	sleep(2000);
	Auton_Lift_Targeted(DOWN,300);
	Auton_Drive_Targeted(BACKWARD,200);
}
