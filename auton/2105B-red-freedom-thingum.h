void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125);
	Collection(-150);
	Lift_Target = 600; // low post
	MinOverride = true;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 590) {}
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -94, 127, 10);//100
	Auton_Drive_TurnTo(CLOCKWISE, -220); // -220, -160 (or thereabouts) works well usually
	//Auton_Drive(COUNTERCLOCKWISE, 127, 10);
	Auton_Drive(FORWARD, 80, 100);
	writeDebugStreamLine("%i", SensorValue[EncoderLiftLeft]);
	writeDebugStreamLine("%i", SensorValue[EncoderLiftRight]);
	sleep(1000);
	Collection(1000);
	Auton_Drive_Targeted_PID(BACKWARD, -100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -100);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 810);
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 350);
	sleep(500);
	Collection(700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1720);
	Auton_Drive_Targeted(FORWARD, 10);
	Collection(200);
}
