// ROBOT:  2015A
// DRIVER: John

task usercontrol {
	int leftdrive, rightdrive;
	const int deadband = 15;
	while(true) {
		// MAIN DRIVE
		leftdrive = vexRT[Ch2] + vexRT[Ch1];
		rightdrive = vexRT[Ch2] - vexRT[Ch1];
		// ** DEADBANDING
		if(leftdrive < deadband && leftdrive > -deadband)
			leftdrive = 0;
		if(rightdrive < deadband && rightdrive > -deadband)
			rightdrive = 0;
		// DEADBANDING **
		motor[DriveLeftA] = leftdrive;
		motor[DriveLeftB] = leftdrive;
		motor[DriveRightA] = rightdrive;
		motor[DriveRightB] = rightdrive;

		// LIFT
		if(vexRT[Btn6U] == 1) {
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1) {
			Auton_Lift(DOWN);
			} else {
			Auton_Lift();
		}

		// TRANSMISSION
		if(vexRT[Btn5U] == 1) {
			SensorValue[TransmissionPneumatic] = 1;
			} else if(vexRT[Btn5D] == 1) {
			SensorValue[TransmissionPneumatic] = 0;
		}

		// CLAW
		if(vexRT[Btn7U] == 1) {
			SensorValue[ClawPneumatic] = 1;
			} else if(vexRT[Btn7D] == 1) {
			SensorValue[ClawPneumatic] = 0;
		}
	}
}
