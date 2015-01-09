/*task LiftTo0 {
Auton_Lift_Targeted(DOWN,0);
}

task LiftTo800 {
Auton_Lift_Targeted(UP,800);
}*/

void Auton_Red_AtLoader() {
	Auton_Lift_Targeted(UP,400);
	sleep(250);
	Auton_Drive_Targeted(FORWARD, 110);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1100);
	Auton_Drive_Targeted(FORWARD,330);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_Targeted(BACKWARD,200);
}
