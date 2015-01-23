void Auton_Blue_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 85);
	Collection(200);
	Lift_Target = 45; // low post
	while(SensorValue[EncoderLiftLeft] < 30){}
	Collection(600);
	Lift_Target = 0;
	Auton_Drive_Targeted(BACKWARD, 240);
	while(SensorValue[EncoderLiftLeft] > 10) {} // LIFT DOWN AFTER 1st cube
	Auton_Drive_TurnTo(CLOCKWISE, -450); // 2nd cube turn
	Auton_Drive_Targeted(FORWARD, 50);
	Collection(200);
	Auton_Drive_TurnTo(CLOCKWISE, -775); // TURN TOWARDS 2nd Pole
	Lift_Target = 90;
	Auton_Drive_Targeted(BACKWARD, 10);
	while(SensorValue[EncoderLiftLeft] < 80) {}
	Auton_Drive_Targeted(FORWARD, 100);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 50);
	Lift_Target = 0;
	Collection(1100);
	Auton_Drive_TurnTo(CLOCKWISE, -1500); // WAS 1290
	Auton_Drive_Targeted(FORWARD,1300,127,2600); // AFTER 2nd cube
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -900); // whacko 700
	Auton_Drive_Targeted(FORWARD,5);
	Collection(700);
	Auton_Drive_Targeted(BACKWARD,50);
	Lift_Target = 45;
	while(SensorValue[EncoderLiftLeft] < 35) {}
	Auton_Drive_Targeted(FORWARD,5);
	Collection(900);
	writeDebugStreamLine("Dropped cube at %i:%2i.%3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD,300);
}
