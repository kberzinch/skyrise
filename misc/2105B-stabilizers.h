int Lift_Target = 0;
bool IsStabilizerRunning = false;
const float Kp = 1.5;
const float Ki = 0.0001;
const int IntegralLimit = 100;
const float Kd = 0.2;
bool MinOverride = false;

int Normalize(int speed) {
	if(speed > 127) {
		return 127;
	}
	if(speed < -127) {
		return -127;
	}
	return speed;
}

void Set_Lift_Target(int Adjustment = 0) {
	Lift_Target = ((SensorValue[EncoderLiftLeft] + (SensorValue[EncoderLiftRight])) / 2) + Adjustment;
}

task Lift_Stabilizer_Left {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderLiftLeft;
	int error, previous_error, speed, derivative, integral = 0;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 1000 || (SensorValue[sensor] < 100 && !MinOverride)) {
			motor[LiftLeftA] = 0;
			motor[LiftLeftB] = 0;
			continue;
		}
		error = (Lift_Target - (SensorValue[sensor] + 25));
		if(abs(error) < IntegralLimit) {
			integral += error;
			} else {
			integral = 0;
		}
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative + Ki * integral;
		motor[LiftLeftA] = Normalize(speed);
		motor[LiftLeftB] = Normalize(speed);
		EndTimeSlice();
	}
}

task Lift_Stabilizer_Right {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderLiftRight;
	int error, previous_error, speed, derivative, integral = 0;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 1000 || (SensorValue[sensor] < 100 && !MinOverride)) {
			motor[LiftRightA] = 0;
			motor[LiftRightB] = 0;
			continue;
		}
		error = (Lift_Target - SensorValue[sensor]);
		if(abs(error) < IntegralLimit) {
			integral += error;
			} else {
			integral = 0;
		}
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative + Ki * integral;
		motor[LiftRightA] = Normalize(speed);
		motor[LiftRightB] = Normalize(speed);
		EndTimeSlice();
	}
}
