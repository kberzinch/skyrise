// ROBOT:  2015A
// DRIVER: John

task usercontrol {
	while(true) {
		// DRIVE
		motor[DriveRearLeft]   =  vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontLeft]  = -vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveRearRight]  =  vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontRight] = -vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];

		// LIFT
		if(vexRT[Btn6U] == 1) {
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1) {
			Auton_Lift(DOWN);
			} else {
			Auton_Lift();
		}
	}
}
