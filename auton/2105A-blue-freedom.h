void Auton_Blue_Freedom() {
	Auton_Lift_Targeted(UP,800);
	Auton_Drive_Targeted(FORWARD,100);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_TurnTo(CLOCKWISE,-1150);
	Auton_Drive_Targeted(LEFT,100);
	Auton_Drive_Targeted(FORWARD,300);
}

// FREEDOM 1: Small Post + Medium Post
// FREEDOM 2: Small Post + Pylons
