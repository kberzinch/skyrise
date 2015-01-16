task RunCollectionFor400ms {
	Collection(127);
	sleep(400);
	Collection();
}

task RunCollectionFor700ms {
	Collection(127);
	sleep(700);
	Collection();
}

void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 125);
	Collection(-127);
	sleep(450);
	Collection();
	Lift_Target = 55; // low post
	while(SensorValue[EncoderLiftLeft] < 40) {}
	Collection(-127);
	sleep(550);
	Collection();
	Auton_Drive_Targeted(BACKWARD, 300);
	startTask(RunCollectionFor700ms);
	Lift_Target = 0;
	while(SensorValue[EncoderLiftLeft] > 10){}
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 350);
	Auton_Drive_Targeted(FORWARD, 80); //130?
	Collection(127);
	sleep(800);
	Collection();
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 650);
	Lift_Target = 90;
	while(SensorValue[EncoderLiftLeft] < 80){}
	Auton_Drive_Targeted(FORWARD,50);
	Collection(-127);
	sleep(1000);
	Collection();
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1300);
	Lift_Target = 0;
	startTask(RunCollectionFor400ms);
	Auton_Drive_Targeted(FORWARD,1200,127,4000);
	Auton_Drive_TurnTo(CLOCKWISE,700);
	Collection(127);
	sleep(500);
	Collection();
	Lift_Target = 55;
}
