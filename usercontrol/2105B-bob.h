// ROBOT:  2015A
// DRIVER: Bob

task usercontrol {
	while(true) {

		// NOT-BREAK-LIFT PREVENTION
		if(SensorValue[EncoderLiftRight] > 120) {
			motor[LiftLeftA] = 0;
			motor[LiftLeftB] = 0;
			motor[LiftRightA] = 0;
			motor[LiftRightB] = 0;
		}

		// DRIVE
		motor[DriveFrontLeft] = -(vexRT[Ch3] + vexRT[Ch4]);
		motor[DriveFrontRight] = (vexRT[Ch3] - vexRT[Ch4]);
		motor[DriveRearLeft] = -(vexRT[Ch3] + vexRT[Ch4]);
		motor[DriveRearRight] = (vexRT[Ch3] - vexRT[Ch4]);

		// LIFT
		if(vexRT[Btn6U] == 1) {
			IsStabilizerRunning = false;
			Set_Lift_Target();
			motor[LiftLeftA] = 127;
			motor[LiftLeftB] = 127;
			motor[LiftRightA] = 127;
			motor[LiftRightB] = 127;
			} else if(vexRT[Btn6D] == 1) {
			IsStabilizerRunning = false;
			Set_Lift_Target();
			motor[LiftLeftA] = -127;
			motor[LiftLeftB] = -127;
			motor[LiftRightA] = -127;
			motor[LiftRightB] = -127;
			} else {
			if(!IsStabilizerRunning) {
				startTask(Lift_Stabilizer_Left);
				startTask(Lift_Stabilizer_Right);
			}
		}

		// LIFT PRESETS
		if(vexRT[Btn8D] == 1) {
			Lift_Target = 0; // down
			} else if(vexRT[Btn8U] == 1) {
			Lift_Target = 90; // med
			} else if(vexRT[Btn8L] == 1) {
			Lift_Target = 55; // low
			} else if(vexRT[Btn8R] == 1) {
			Lift_Target = 123; // high
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
	}
}
