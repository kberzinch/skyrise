void Auton_Blue_Freedom() {
	Auton_Lift_Targeted(UP,800);
	Auton_Drive_Targeted(FORWARD,100);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_TurnTo(CLOCKWISE,-1200);
	Auton_Drive_Targeted(FORWARD,300);
	Auton_Lift_Targeted(UP,400);
	Auton_Drive(COUNTERCLOCKWISE,127,100);
	Auton_Drive_Targeted(FORWARD,200);
	Auton_Lift_Targeted(UP,1600);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-400);
}

// FREEDOM 1: Small Post + Medium Post
// FREEDOM 2: Small Post + Pylons
