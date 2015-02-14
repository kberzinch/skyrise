void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Auton_Drive_Targeted(BACKWARD, 125);
	Collection(200);
	Lift_Target = 320; // low post
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 310) {}
	MinOverride = false;
	Collection(600);
	Auton_Drive_Targeted(BACKWARD, 550);
	Lift_Target = 0;
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] > 10) {} // LIFT DOWN AFTER 1st cube
	MinOverride = false;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 425); // 2nd cube turn
	ResetDriveEncoders();
	Auton_Drive(FORWARD, 127, 250);
	while(SensorValue[DriveEncoder] < 200) {}
	Collection(200);
	Auton_Drive_Targeted(BACKWARD, 200);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 580); // TURN TOWARDS 2nd Pole
	Lift_Target = 640;
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 630) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD,-15);
	Collection(600);
	Auton_Drive_Targeted(BACKWARD,100);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1290); // WAS 1290
	Lift_Target = 0;
	Collection(1100);
	sleep(100);
	Auton_Drive_Targeted(FORWARD,1230,127,4000); // AFTER 2nd cube
	Auton_Drive_TurnTo(CLOCKWISE,652); // whacko 700
	Auton_Drive_Targeted(FORWARD,65);
	Collection(700);
	Auton_Drive_Targeted(BACKWARD,80);
	Lift_Target = 360;
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] < 350) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD,93);
	Collection(900);
	writeDebugStreamLine("Dropped cube at %i:%2i.%3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD,300);
}
