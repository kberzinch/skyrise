void Auton_Blue_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 85);
	Collection(200);
	Lift_Target = 45; // low post
	while(SensorValue[EncoderLiftLeft] < 30){}
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 410);
	Lift_Target = 0;
	while(SensorValue[EncoderLiftLeft] > 10) {} // LIFT DOWN AFTER 1st cube
	Auton_Drive_TurnTo(CLOCKWISE, -200); // 2nd cube turn
	Auton_Drive_Targeted(FORWARD, 40);
	sleep(300);
	Collection(200);
	Auton_Drive_TurnTo(CLOCKWISE, -600); // TURN TOWARDS 2nd Pole
	Lift_Target = 85;
	Auton_Drive_Targeted(BACKWARD, 10);
	while(SensorValue[EncoderLiftLeft] < 70) {}
	Auton_Drive_Targeted(FORWARD, 100);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 100);
	Auton_Drive_TurnTo(CLOCKWISE, -1250); // WAS 1290
	Lift_Target = 0;
	Collection(1100);
	sleep(100);
	Auton_Drive_Targeted(FORWARD,1220,127,4000); // AFTER 2nd cube
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, -680); // whacko 700
	Auton_Drive_Targeted(FORWARD,5);
	Collection(700);
	Auton_Drive_Targeted(BACKWARD,50);
	Lift_Target = 45;
	while(SensorValue[EncoderLiftLeft] < 35) {}
	Auton_Drive_Targeted(FORWARD,70);
	Collection(900);
	writeDebugStreamLine("Dropped cube at %i:%2i.%3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD,300);
}
