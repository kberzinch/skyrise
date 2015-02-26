// ROBOT:  2015A
// DRIVER: Bob

int LastLeft = 0;
int LastRight = 0;
int LastDown = 0;
float Multiplier = 1;

task usercontrol {
	allMotorsOff();
	while(true) {

		// SPEED MULTIPLIER
		if(vexRT[AccelY] > -5) {
			Multiplier = 0.5;
		} else {
			Multiplier = 1;
		}

		// NOT-BREAK-LIFT PREVENTION
		if(SensorValue[EncoderLiftRight] > 800) {
			IsStabilizerRunning = false;
			motor[LiftLeftA] = 0;
			motor[LiftLeftB] = 0;
			motor[LiftRightA] = 0;
			motor[LiftRightB] = 0;
		}

		// DRIVE
		motor[DriveFrontLeft] = -(vexRT[Ch3] + vexRT[Ch4]) * Multiplier;
		motor[DriveFrontRight] = (vexRT[Ch3] - vexRT[Ch4]) * Multiplier;
		motor[DriveRearLeft] = -(vexRT[Ch3] + vexRT[Ch4]) * Multiplier;
		motor[DriveRearRight] = (vexRT[Ch3] - vexRT[Ch4]) * Multiplier;

		// LIFT
		if(vexRT[Btn6U] == 1) {
			IsStabilizerRunning = false;
			Set_Lift_Target(10);
			motor[LiftLeftA] = 127 * Multiplier;
			motor[LiftLeftB] = 127 * Multiplier;
			motor[LiftRightA] = 127 * Multiplier;
			motor[LiftRightB] = 127 * Multiplier;
			} else if(vexRT[Btn6D] == 1) {
			IsStabilizerRunning = false;
			Set_Lift_Target(-10);
			motor[LiftLeftA] = -127 * Multiplier;
			motor[LiftLeftB] = -127 * Multiplier;
			motor[LiftRightA] = -127 * Multiplier;
			motor[LiftRightB] = -127 * Multiplier;
			} else if(vexRT[Btn8D] == 1) {
			IsStabilizerRunning = false;
			Set_Lift_Target(0);
			motor[LiftLeftA] = 0;
			motor[LiftLeftB] = 0;
			motor[LiftRightA] = 0;
			motor[LiftRightB] = 0;
			} else {
			if(!IsStabilizerRunning) {
				startTask(Lift_Stabilizer_Left);
				startTask(Lift_Stabilizer_Right);
			}
		}

		// LIFT PRESETS
		/*if(vexRT[Btn8D] == 1) {
			Lift_Target = 0; // down
			} else */if(vexRT[Btn8U] == 1) { // HIGH
			Lift_Target = 800;
			} else if(vexRT[Btn8L] == 1) { // MED
			Lift_Target = 600;
			} else if(vexRT[Btn8R] == 1) { // LOW
			Lift_Target = 300;
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

		// PNEUMATICS
		if(vexRT[Btn7L] == 1 && LastLeft == 0) {
			SensorValue[SolenoidA] = !SensorValue[SolenoidA];
			LastLeft = 1;
			} else if(vexRT[Btn7L] == 0 && LastLeft == 1) {
			LastLeft = 0;
		}
		if(vexRT[Btn7R] == 1 && LastRight == 0) {
			SensorValue[SolenoidB] = !SensorValue[SolenoidB];
			LastRight = 1;
			} else if(vexRT[Btn7R] == 0 && LastRight == 1) {
			LastRight = 0;
		}
		if(vexRT[Btn7D] == 1 && LastDown == 0) {
			SensorValue[SolenoidA] = !SensorValue[SolenoidA];
			SensorValue[SolenoidB] = !SensorValue[SolenoidB];
			LastDown = 1;
			} else if(vexRT[Btn7D] == 0 && LastDown == 1) {
			LastDown = 0;
		}
	}
}
