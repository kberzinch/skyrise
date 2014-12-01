// ROBOT:  2015A
// DRIVER: John

task usercontrol {
	while(true) {
		// DRIVE
	if(vexRT[Btn5D] == 1) {
		motor[DriveRearLeft]   =  vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontLeft]  = -vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveRearRight]  =  vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontRight] = -vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];
	} else {
		motor[DriveRearLeft]   = 0;
		motor[DriveFrontLeft]  = 0;
		motor[DriveRearRight]  = 0;
		motor[DriveFrontRight] = 0;
}


		// LIFT
		if(vexRT[Btn6U] == 1 && SensorValue[LiftLimitMax] != 0) {
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1 && SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0) {
			Auton_Lift(DOWN);
			} else {
			Auton_Lift();
		}
	}
}
