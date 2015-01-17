void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 100);
	Collection(200);
	Lift_Target = 45; // low post
	while(SensorValue[EncoderLiftLeft] < 30) {}
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 300);
	Lift_Target = 0;
	while(SensorValue[EncoderLiftLeft] > 10){}
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 400);
	Auton_Drive_Targeted(FORWARD, 2);
	Collection(200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 650);
	Lift_Target = 80;
	while(SensorValue[EncoderLiftLeft] < 70) {}
	Auton_Drive_Targeted(FORWARD,20);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1300);
	Lift_Target = 0;
	Collection(1000);
	Auton_Drive_Targeted(FORWARD,1200,127,4000);
	Auton_Drive_TurnTo(CLOCKWISE,700);
	Auton_Drive_Targeted(FORWARD,70);
	Collection(200);
	Auton_Drive_Targeted(BACKWARD,70);
	Lift_Target = 45;
	while(SensorValue[EncoderLiftLeft] < 35) {}
	sleep(500);
	Auton_Drive_TurnTo(CLOCKWISE,700);
	Auton_Drive_Targeted(FORWARD,50);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD,100);
}
