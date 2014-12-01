// ROBOT:  2015A
// DRIVER: John

task usercontrol_liftpresets;

task usercontrol {
	//startTask(usercontrol_liftpresets);
	while(true) {
		// DRIVE
		motor[DriveRearLeft]   =  vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontLeft]  = -vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4];
		motor[DriveRearRight]  =  vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];
		motor[DriveFrontRight] = -vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4];

		// LIFT MANUAL
		if(vexRT[Btn6U] == 1 && SensorValue[LiftLimitMax] != 0) {
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1 && SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0) {
			Auton_Lift(DOWN);
			} else {
			Auton_Lift();
		}
	}
}

task usercontrol_liftpresets {
	while(true) {
		if(vexRT[Btn7D] == 1) {
			// move lift to floor
		}
	}
}
