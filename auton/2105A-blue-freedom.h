void Auton_Blue_Freedom() {
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,250,63);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD,120);
	Auton_Lift_Targeted(DOWN,550);
	Auton_Drive_Targeted(BACKWARD,-200);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_TurnTo(CLOCKWISE,-850);
	Auton_Drive_Targeted(FORWARD,1500);
	Auton_Lift_Targeted(UP,1800);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-200);
	Auton_Drive_Targeted(FORWARD,25);
	Auton_Lift_Targeted(DOWN,1400);
	sleep(500);
	Auton_Drive_Targeted(BACKWARD,-200);
}
