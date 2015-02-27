void Auton_Progskills() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted(FORWARD, 80, 80);
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	while(SensorValue[DriveEncoder] < 125) {}
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	Collection(-150);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 140);
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	sleep(100);
	Auton_Drive_Targeted_PID(FORWARD, -100);
	sleep(100);
	Collection(800);
	Auton_Drive_Targeted(BACKWARD, 150);
	Auton_Drive_TurnTo(CLOCKWISE, -50); // reduced for battery?(50)
	Lift_Target = 20; // Lift down
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Collection(1000);
	Auton_WaitForKeyPress(2);
	Auton_Drive_Targeted_PID(FORWARD,-130);
	Collection(700);
Auton_Drive_TurnTo(COUNTERCLOCKWISE,-770);//-760
Auton_Drive_Targeted_PID(FORWARD,-350);//-350
Collection(300);
Auton_Drive_Targeted_PID(BACKWARD,-325);
Auton_WaitForKeyPress(1000);
Auton_Drive_Targeted_PID(BACKWARD,-200);
	Lift_Target = 350;
	MinOverride = true;
	StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD,-50);
	Collection(1500);
	sleep(500);
	Auton_Drive_Targeted(BACKWARD,400);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,60);
	Auton_Drive_Targeted(BACKWARD,20000);

}
