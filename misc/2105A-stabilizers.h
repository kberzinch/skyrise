int Lift_Target = 0;
bool IsStabilizerRunning = false;
float Kp = 0.15;
float Ki = 0.00001;
const int IntegralLimit = 100;
float Kd = 0.02;
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
	Lift_Target = ((SensorValue[EncoderRight] + (SensorValue[EncoderLeft])) / 2) + Adjustment;
}

task Lift_Stabilizer_Left {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderLeft;
	int error, previous_error, speed, derivative, integral = 0;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 105 || (SensorValue[sensor] < 10 && !MinOverride)) {
			motor[LiftTopLeft] = 0;
			motor[LiftBottomLeft] = 0;
			continue;
		}
		error = (Lift_Target - (SensorValue[sensor]));
		if(abs(error) < IntegralLimit) {
			integral += error;
			} else {
			integral = 0;
		}
		derivative = error - previous_error;
		previous_error = error;
		speed = Kp * error + Kd * derivative + Ki * integral;
		motor[LiftTopLeft] = Normalize(speed);
		motor[LiftBottomLeft] = Normalize(speed);
		EndTimeSlice();
	}
}

task Lift_Stabilizer_Right {
	IsStabilizerRunning = true;
	const tSensors sensor = EncoderRight;
	int error, previous_error, speed, derivative, integral = 0;
	while(IsStabilizerRunning) {
		if(SensorValue[sensor] > 105 || (SensorValue[sensor] < 10 && !MinOverride)) {
			motor[LiftTopRight] = 0;
			motor[LiftBottomRight] = 0;
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
		motor[LiftTopRight] = Normalize(speed);
		motor[LiftBottomRight] = Normalize(speed);
		EndTimeSlice();
	}
}
