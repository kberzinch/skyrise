// ROBOT:  2015A
// DRIVER: Bob

task usercontrol {
	while(true) {
		// DRIVE
		motor[DriveFrontLeft] = (vexRT[Ch3] + vexRT[Ch4]);
		motor[DriveFrontRight] = (vexRT[Ch3] - vexRT[Ch4]);
		motor[DriveRearLeft] = (vexRT[Ch3] + vexRT[Ch4]);
		motor[DriveRearRight] = (vexRT[Ch3] - vexRT[Ch4]);

		// LIFT
		if(vexRT[Btn6U] == 1) {
			stopTask(Lift_Stabilizer_Left);
			stopTask(Lift_Stabilizer_Right);
			Set_Lift_Target();
			motor[LiftLeftA] = 127;
			motor[LiftLeftB] = 127;
			motor[LiftRightA] = 127;
			motor[LiftRightB] = 127;
			} else if(vexRT[Btn6D] == 1) {
			stopTask(Lift_Stabilizer_Left);
			stopTask(Lift_Stabilizer_Right);
			Set_Lift_Target();
			motor[LiftLeftA] = -127;
			motor[LiftLeftB] = -127;
			motor[LiftRightA] = -127;
			motor[LiftRightB] = -127;
			} else {
			startTask(Lift_Stabilizer_Left);
			startTask(Lift_Stabilizer_Right);
		}

		// COLLECTION
		if(vexRT[Btn5U] == 1) {
			motor[CollectionA] = 127;
			motor[CollectionB] = 127;
			} else if(vexRT[Btn5D] == 1) {
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
			} else {
			motor[CollectionA] = 0;
			motor[CollectionB] = 0;
		}
		// DONE
	}
}
