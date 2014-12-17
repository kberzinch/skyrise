void Auton_Red_Freedom() {
	/*Auton_Lift_Targeted(UP,800);*/
	//Auton_Drive_Targeted(FORWARD,1500);
	motor[DriveFrontLeft] = 127;
	motor[DriveFrontRight] = 127;
	motor[DriveRearLeft] = 127;
	motor[DriveRearRight] = 127;
	/*Auton_Drive_Targeted(BACKWARD,200);
	Auton_Lift_Targeted(DOWN,0);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,1300);
	Auton_Drive_Targeted(FORWARD,300);
	Auton_Lift_Targeted(UP,300);
	Auton_Drive_Targeted(FORWARD,250);
	Auton_Lift_Targeted(UP,1600);
	Auton_Drive_TurnTo(CLOCKWISE,450);*/
}
