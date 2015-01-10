/*task LiftTo0 {
Auton_Lift_Targeted(DOWN,0);
}

task LiftTo800 {
Auton_Lift_Targeted(UP,800);
}*/

void Auton_Red_AtLoader() {
	Auton_Lift_Targeted(UP,400);
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 90);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 750);
	Auton_Drive_Targeted(FORWARD,200);
	sleep(500);
	Auton_Lift_Targeted(DOWN,1);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(CLOCKWISE, 500);
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD,160);
	sleep(250);
	Auton_Lift_Targeted(UP,800);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 700);
	Auton_Drive_Targeted(FORWARD,230);
	sleep(500);
	Auton_Lift_Targeted(DOWN,200);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(CLOCKWISE, 500);
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD,130);
	sleep(250);
	Auton_Lift_Targeted(UP,1100,127,2000);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 700);
	Auton_Drive_Targeted(FORWARD,180);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,200);
	Auton_Drive_Targeted(BACKWARD,70);
	Auton_Drive_TurnTo(CLOCKWISE, 500);
	Auton_Lift_Targeted(UP,400);
}
