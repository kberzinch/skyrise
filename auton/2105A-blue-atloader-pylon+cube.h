void Auton_Blue_AtLoader_Cube() {
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
	Auton_Drive_TurnTo(CLOCKWISE, -850, 50);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,100);
	Auton_Drive_Targeted(BACKWARD, -30);
	Auton_Lift_Targeted(UP,850);
	Auton_Drive(BACKWARD);
	while(SensorValue[LineFollowerCenter] > 970) {}
	Auton_Drive();
	Auton_Drive_TurnTo(CLOCKWISE, -1200);
	Auton_Lift_Targeted(DOWN, 100);
	Auton_Drive_Targeted(FORWARD, 600);
	Auton_Lift_Targeted(UP, 800);
	Auton_Drive_Targeted(BACKWARD, 600);
	Auton_Lift_Targeted(DOWN, 100);
}
