void Auton_Blue_AtLoader() {
	Auton_Lift_Targeted(UP,850);
	Auton_Drive_Targeted(FORWARD, 90, 127);
	sleep(1000);
	Auton_Lift_Targeted(DOWN,500);
	sleep(1000);
	Auton_Lift(DOWN,50);
	sleep(1000);
	Auton_Lift(DOWN,50);
	sleep(1000);
	Auton_Lift_Targeted(UP,1000);
}
