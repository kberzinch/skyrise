void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125, 127, 10);
	Collection(-150);
	Lift_Target = 600; // low post
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 590) {}
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -100, 127, 10);
	Auton_Drive_TurnTo(CLOCKWISE, -230);
	ResetDriveEncoders();
	Auton_Drive(FORWARD, 127, 100);
	while(SensorValue[DriveEncoder] < 80) {}
	Collection(1000);
}
