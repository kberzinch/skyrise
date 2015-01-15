void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 125);
	Collection(-127);
	sleep(450);
	Collection();
	Lift_Target = 55; // low
	while(SensorValue[EncoderLiftLeft] < 40){}
	wait1Msec(500);
	Collection(-127);
	sleep(550);
	Collection();
	Auton_Drive_Targeted(BACKWARD, 600);
	Lift_Target = 0; // low
	while(SensorValue[EncoderLiftLeft] > 10){}
	wait1Msec(500);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 390);
	Collection(-127);
	sleep(700);
	Collection();
	Auton_Drive_Targeted(FORWARD, 200);

	//Auton_Drive_Targeted(FORWARD, 100);
}
