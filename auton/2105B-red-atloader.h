void Auton_Red_AtLoader() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted(FORWARD, 80, 80);
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	while(SensorValue[DriveEncoder] < 125) {}
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	Collection(-150);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 160);
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -140);
	Collection(800);
	Auton_Drive_Targeted(BACKWARD, 150);
	MinOverride = true;
	Lift_Target = 30;
	StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) > 40 && (nSysTime - StartTime) < 2000) {}
	MinOverride = false;
}
