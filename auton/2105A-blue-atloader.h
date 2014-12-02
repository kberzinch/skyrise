void Auton_Blue_AtLoader() {
	Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,450);
	sleep(500);
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(500);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,400);
	Auton_Drive_TurnTo(CLOCKWISE,-700);
}
