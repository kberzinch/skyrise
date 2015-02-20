void Auton_Blue_AtLoader() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125);
	Collection(-150);
	Auton_Drive_TurnTo(CLOCKWISE, -110);
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -125, 127, 10);
	Collection(1000);
	Auton_Drive_Targeted_PID(BACKWARD, -100);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800);
	Auton_Drive(CLOCKWISE, 100);
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 350);
	sleep(250);
	Collection(700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1400);
	Auton_Drive_Targeted(FORWARD, 5);
	Collection(300);
	Auton_Drive_TurnTo(CLOCKWISE, -400);
	Auton_Drive_Targeted(FORWARD, 120);
	Lift_Target = 575;
	MinOverride = true;
	StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -125, 127, 10);
	Collection(1000);
}
