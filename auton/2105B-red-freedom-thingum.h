void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125, 127, 10);
	Collection(-150);
	Lift_Target = 640; // low post
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 630) {}
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -100, 127, 10);
	Auton_Drive_TurnTo(CLOCKWISE, -160); // -220, -160 (or thereabouts) works well usually
	ResetDriveEncoders();
	Auton_Drive(FORWARD, 127, 150);
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	while(SensorValue[DriveEncoder] < 70) {}
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	Collection(1000);
	Auton_Drive_Targeted_PID(BACKWARD, -100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -100);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -600);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE,830);
	//Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE, 900, 127, 6, 1000);
	Auton_Drive_Targeted_PID(FORWARD, -278, 127, 5, 2000);
	sleep(500);
	Collection(500);
}
