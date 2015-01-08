int Lift_Target = 0;
const float Kp = 5;
const float Kd = 1;

int Normalize(int speed) {
	if(speed > 127) {
		return 127;
	}
	if(speed < -127) {
		return -127;
	}
	return speed;
}

void Set_Lift_Target() {
	Lift_Target = (SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2;
}

task Lift_Stabilizer_Left {
	const tSensors sensor = EncoderLiftLeft;
	int error, previous_error, speed, derivative;
	while(true) {
		error = Lift_Target - SensorValue[sensor];
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative;
		motor[LiftLeftA] = Normalize(speed);
		motor[LiftLeftB] = Normalize(speed);
	}
}

task Lift_Stabilizer_Right {
	const tSensors sensor = EncoderLiftRight;
	int error, previous_error, speed, derivative;
	while(true) {
		error = Lift_Target - SensorValue[sensor];
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative;
		motor[LiftRightA] = Normalize(speed);
		motor[LiftRightB] = Normalize(speed);
	}
}
