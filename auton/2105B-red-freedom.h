void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 85);
	Collection(200);
	Lift_Target = 45; // low post
	while(SensorValue[EncoderLiftLeft] < 30){}
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 350);
	Lift_Target = 0;
	while(SensorValue[EncoderLiftLeft] > 10) {} // LIFT DOWN AFTER 1st cube
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 350); // 2nd cube turn
	Auton_Drive_Targeted(FORWARD, 50);
	Collection(200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 625); // TURN TOWARDS 2nd Pole
	Lift_Target = 80;
	while(SensorValue[EncoderLiftLeft] < 70) {}
	Auton_Drive_Targeted(FORWARD,20);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1290); // WAS 1300
	Lift_Target = 0;
	Collection(1100);
	Auton_Drive_Targeted(FORWARD,1270,127,4000); // AFTER 2nd cube
	Auton_Drive_TurnTo(CLOCKWISE,700); // whacko
	Auton_Drive_Targeted(FORWARD,65);
	Collection(700);
	Auton_Drive_Targeted(BACKWARD,80);
	Lift_Target = 55;
	while(SensorValue[EncoderLiftLeft] < 35) {}
	Auton_Drive_Targeted(FORWARD,50);
	Collection(900);
	Auton_Drive_Targeted(BACKWARD,300);
}
