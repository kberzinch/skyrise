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
	Auton_Drive_Targeted_PID(FORWARD, -160, 127, 10);
	Collection(1000);
	Auton_Drive_Targeted_PID(BACKWARD, -100);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
}
