int Lift_Target = 0;
bool IsStabilizerRunning = false;
const float Kp = 1.5;
const float Kd = 0.2;

int Normalize(int speed) {
	if(speed > 127) {
		return 127;
	}
	if(speed < -127) {
		return -127;
	}
	return speed;
}

void Set_Lift_Target(int Adjustment) {
	Lift_Target = ((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) + Adjustment;
}

task Lift_Stabilizer_Left {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderLiftLeft;
	int error, previous_error, speed, derivative;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 800 || SensorValue[sensor] < 100) {
			motor[LiftLeftA] = 0;
			motor[LiftLeftB] = 0;
			continue;
		}
		error = (Lift_Target - SensorValue[sensor]);
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative;
		motor[LiftLeftA] = Normalize(speed);
		motor[LiftLeftB] = Normalize(speed);
		EndTimeSlice();
	}
}

task Lift_Stabilizer_Right {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderLiftRight;
	int error, previous_error, speed, derivative;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 800 || SensorValue[sensor] < 100) {
			motor[LiftRightA] = 0;
			motor[LiftRightB] = 0;
			continue;
		}
		error = (Lift_Target - SensorValue[sensor]);
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative;
		motor[LiftRightA] = Normalize(speed);
		motor[LiftRightB] = Normalize(speed);
		EndTimeSlice();
	}
}
