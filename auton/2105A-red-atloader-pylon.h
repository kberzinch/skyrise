void Auton_Red_AtLoader() {
	Auton_Lift_Targeted(UP,850);
	Auton_Drive_Targeted(FORWARD, 90);
	sleep(500);
	Auton_Lift_Targeted(DOWN,500,127);
	sleep(500);
	Auton_Lift(DOWN,127,50);
	sleep(500);
	Auton_Lift_Targeted(UP,1000);
	Auton_Drive_Targeted(BACKWARD, -250);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,800, 63);
	Auton_Drive_Targeted(FORWARD, 50);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900, 50);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_Targeted(BACKWARD, -30);
	Auton_Lift_Targeted(UP,850);
}

void OVERRIDE() {
	Auton_Lift_Targeted(UP,850);
	Auton_Drive_Targeted(FORWARD, 65, 63);
	sleep(500);
	Auton_Lift_Targeted(DOWN,500,127);
	sleep(500);
	Auton_Lift(DOWN,127,50);
	sleep(500);
	Auton_Lift_Targeted(UP,1000);
	Auton_Drive_Targeted(BACKWARD, -100, 63);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 700, 63);
	Auton_Drive_Targeted(FORWARD, 100);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_Targeted(BACKWARD, -10);
	Auton_Lift_Targeted(UP,850);
}
