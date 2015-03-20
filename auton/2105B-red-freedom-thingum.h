void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125);
	Collection(-150);
	Auton_Drive_TurnTo(CLOCKWISE, -150); // Needs to be lower
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 90);
	Collection(800);
	Auton_Drive_Targeted(BACKWARD, 170); //170
	Collection(1000);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 20);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	Auton_Drive_TurnTo_PID(COUNTERCLOCKWISE, 1025, 127, 5, 1000);
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 380);
	sleep(250);
	Collection(700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1400); // Needs to be higher
	Auton_Drive_Targeted(FORWARD, 5);
	Collection(300);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 2375); // Lower
	Auton_Drive_Targeted(FORWARD, 50);
	Lift_Target = 350;
	MinOverride = true;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 340) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 70);
	Collection(1000);
	writeDebugStreamLine("Cubes scored: %i:%2i.%-3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD, 50);
}
