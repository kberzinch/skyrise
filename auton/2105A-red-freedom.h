void Auton_Red_Freedom() {
	Auton_Lift_Targeted(UP,1200);
	Auton_Drive_TurnTo(CLOCKWISE,-350,63);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD,80);
	Auton_Lift_Targeted(DOWN,550);
	//Auton_Drive_Targeted(BACKWARD,-60);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,700);
	Auton_Drive_Targeted(FORWARD,1500);
	Auton_Lift_Targeted(UP,1800);
	Auton_Drive_TurnTo(CLOCKWISE,200);
	Auton_Drive_Targeted(FORWARD,25);
	Auton_Lift_Targeted(DOWN,1400);
	sleep(500);
	Auton_Drive_Targeted(BACKWARD,-200);
}
