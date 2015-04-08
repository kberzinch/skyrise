int Lift_Target = 0;
bool IsStabilizerRunning = false;
const float Kp = 1.2;
const float Kd = 1.5;
const float Ki = 0;//.0001;
const tSensors sensorLeft = I2C_4;
const tSensors sensorRight = I2C_3;
const int leftAdjust = 0; // -350;
const int rightAdjust = 0; // -430;
const int leftMultiplier = -1;
const int rightMultiplier = 1;
const int IntegralLimit = 200;
const int Max = 1400;
const int Min = -20;
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

int divisible(int num) {
	if(num <= 0) {
		return 1;
	}
	return num;
}

#define PID_SEQUENCE\
IsStabilizerRunning = true;\
int error = 0, previous_error = 0, speed = 0, derivative = 0, integral = 0;\
int last_nSysTime = nSysTime;\
while(IsStabilizerRunning) {\
	if(((mult * SensorValue[sensor]) + offset) > Max || (((mult * SensorValue[sensor]) + offset) < Min && !MinOverride)) {\
		motor[motor1] = 0;\
		motor[motor2] = 0;\
		error = 0;\
		integral = 0;\
		derivative = 0;\
		previous_error = 0;\
		continue;\
	}\
	error = (Lift_Target - ((mult * SensorValue[sensor]) + offset));\
	if(abs(error) < IntegralLimit) {\
		integral += error / divisible(nSysTime - last_nSysTime);\
		} else {\
		integral = 0;\
	}\
	derivative = (error - previous_error) / divisible(nSysTime - last_nSysTime);\
	last_nSysTime = nSysTime;\
	previous_error = error;\
	speed = Kp * error + Kd * derivative + Ki * integral;\
	motor[motor1] = Normalize(speed);\
	motor[motor2] = Normalize(speed);\
}

void Set_Lift_Target(int Adjustment = 0) {
	Lift_Target = ((rightMultiplier * (SensorValue[sensorRight] + rightAdjust) + leftMultiplier * (SensorValue[sensorLeft] + leftAdjust)) / 2) + Adjustment;
}

task Lift_Stabilizer_Left {
	const tSensors sensor = sensorLeft;
	const tMotor motor1 = LiftTopLeft;
	const tMotor motor2 = LiftBottomLeft;
	const int offset = leftAdjust;
	const int mult = leftMultiplier;
	PID_SEQUENCE
}

task Lift_Stabilizer_Right {
	const tSensors sensor = sensorRight;
	const tMotor motor1 = LiftTopRight;
	const tMotor motor2 = LiftBottomRight;
	const int offset = rightAdjust;
	const int mult = rightMultiplier;
	PID_SEQUENCE
}
