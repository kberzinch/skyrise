void Auton_Blue_AtLoader() {
	Auton_Drive_Targeted(LEFT,10);
	Auton_Lift_Targeted(UP,350);
	sleep(500);
	Auton_Drive_Targeted(FORWARD, 120);
	sleep(500);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_Targeted(BACKWARD,160);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	Auton_Drive_Targeted(FORWARD,30);
	sleep(500);
	Auton_Lift_Targeted(DOWN,0, 63);
	sleep(500);
	Auton_Drive_Targeted(BACKWARD,50);
	sleep(500);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-400);
	sleep(500);
	Auton_Lift_Targeted(UP,350);
	sleep(500);
	Auton_Drive_Targeted(FORWARD,200);
	sleep(500);
	Auton_Lift_Targeted(UP,700);
	sleep(500);
	Auton_Drive_Targeted(BACKWARD,160);
	sleep(500);
	Auton_Drive_TurnTo(CLOCKWISE,-600);
	sleep(500);
	Auton_Drive_Targeted(FORWARD,30);
}
