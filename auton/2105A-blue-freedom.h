void Auton_Blue_Freedom() {
	Auton_Lift_Targeted(UP,800);
	Auton_Drive_Targeted(FORWARD,100);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_TurnTo(CLOCKWISE,-1200);
	Auton_Drive_Targeted(LEFT,100);
	Auton_Drive_Targeted(FORWARD,300);
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(FORWARD,350);
	Auton_Lift_Targeted(UP,1700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,-650);
	Auton_Drive_Targeted(FORWARD,215);
	sleep(3000);
	Auton_Lift_Targeted(DOWN,600);
	Auton_Drive(BACKWARD);
	Auton_Lift_Targeted(DOWN,0);
	while(SensorValue[LineFollowerCenter] > 1800 && SensorValue[LineFollowerLeft] > 1800) {}
	Auton_Drive(FORWARD,127,100);
}

// FREEDOM 1: Small Post + Medium Post
// FREEDOM 2: Small Post + Pylons
