task LiftTo0 {
	Auton_Lift_Targeted(DOWN,0);
}

task LiftTo800 {
	Auton_Lift_Targeted(UP,800);
}

void Auton_Red_AtLoader() {
	Auton_Lift_Targeted(UP,400);
	Auton_Drive_Targeted(LEFT,90);
	sleep(500);
	Auton_Drive_Targeted(FORWARD, 120, 127, 1000);
	sleep(250);
	Auton_Lift_Targeted(UP,700);
	Auton_Drive_TurnTo(CLOCKWISE,-1700);
	Auton_Drive_Targeted(FORWARD,100);
	sleep(500);
	Auton_Lift_Targeted(DOWN,0,63);
	Auton_Drive_Targeted(BACKWARD,50);
	startTask(LiftTo0);
	Auton_Drive_Targeted(LEFT,230);
	Auton_Drive_Targeted(BACKWARD,200);
	Auton_Drive(COUNTERCLOCKWISE,127,30);
	sleep(1000);
	Auton_Drive_Targeted(FORWARD,400);
	Auton_Lift_Targeted(UP,300);
	startTask(LiftTo800);
	Auton_Drive_Targeted(BACKWARD,80);
	stopTask(LiftTo800);
	Auton_Lift_Targeted(UP,800);
	Auton_Drive_Targeted(CLOCKWISE,220);
	Auton_Drive_Targeted(FORWARD,100);
	Auton_Drive_Targeted(BACKWARD,50);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_Targeted(BACKWARD,150);
}
