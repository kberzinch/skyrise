void Auton_Blue_AtLoader_Pylon() {
	Auton_Lift_Targeted(UP,850);
	Auton_Drive_Targeted(FORWARD, 90);
	sleep(500);
	Auton_Lift_Targeted(DOWN,500,127);
	sleep(500);
	Auton_Lift(DOWN,127,50);
	sleep(500);
	Auton_Lift_Targeted(UP,1000);
	Auton_Drive_Targeted(BACKWARD, -250);
	Auton_Drive_TurnTo(CLOCKWISE,-800, 63);
	Auton_Drive_Targeted(FORWARD, 80);
	Auton_Drive_TurnTo(CLOCKWISE, -900, 50);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_Targeted(BACKWARD, -30);
	Auton_Lift_Targeted(UP,850);
}
