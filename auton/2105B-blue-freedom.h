void Auton_Blue_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted(FORWARD, 80, 80);
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	while(SensorValue[DriveEncoder] < 121) {}
	writeDebugStreamLine("%i",SensorValue[DriveEncoder]);
	Collection(-150);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 70);
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 2000) {}
	if((nSysTime - StartTime) > 2000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -120);
	Collection(800);
	Auton_Drive_Targeted(BACKWARD, 150);
	Auton_Drive_TurnTo(CLOCKWISE, -50); // reduced for battery?
	Lift_Target = 20; // Lift down
	MinOverride = true;
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Collection(1000);
	// WORKS TILL HERE
	Auton_Drive_TurnTo(CLOCKWISE, -670); // Turn for 1st cube
	Auton_Drive_Targeted(FORWARD, 390);
	sleep(300);
	Collection(700);
	Auton_Drive_TurnTo(CLOCKWISE, -1500); // Turn for 2nd
	Auton_Drive_Targeted(FORWARD, 20);
	Collection(300);
	Auton_Drive_TurnTo(CLOCKWISE, -2250); // Turn for pole
	Auton_Drive_Targeted(FORWARD, 60);
	Lift_Target = 350;
	MinOverride = true;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 340) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 125);
	Collection(1000);
	writeDebugStreamLine("Cubes scored: %i:%2i.%-3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD, 80);
}
