void Auton_Red_AtLoader() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted_PID(BACKWARD, -75);
	Collection(100);
	Lift_Target = 170;
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 170) {}
	MinOverride = false;
	//Auton_Drive_Targeted_PID(FORWARD, -60);
	Lift_Target = 120;
	sleep(1000);
	SensorValue[SolenoidA] = 1;
	Lift_Target = 400;
	while(SensorValue[EncoderLiftLeft] < 390) {}
	Auton_Drive_Targeted_PID(BACKWARD, -300);
	Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE,300);
	Lift_Target = 100;
	while(SensorValue[EncoderLiftLeft] > 100) {}
}
