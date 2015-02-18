// Watchdog timers on lift
void Auton_Red_Freedom() {
	startTask(Lift_Stabilizer_Left);
	startTask(Lift_Stabilizer_Right);
	Collection(200);
	Auton_Drive_Targeted_PID(FORWARD, -125);
	Collection(-150);
	Auton_Drive_TurnTo(CLOCKWISE, -80); // -220, -160 (or thereabouts) works well usually
	Lift_Target = 575;
	MinOverride = true;
	long StartTime = nSysTime;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 565 && (nSysTime - StartTime) < 3000) {}
	if((nSysTime - StartTime) < 3000)
		writeDebugStreamLine("timed out");
	MinOverride = false;
	Auton_Drive_Targeted_PID(FORWARD, -100, 127, 10);//100
	//1sec pause?
	Collection(1000);
	Auton_Drive_Targeted_PID(BACKWARD, -100);
	Lift_Target = 20; // Lift down
	MinOverride = true;
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800);
	Auton_Drive(CLOCKWISE, 100);
	while(SensorValue[EncoderLiftLeft] > 30) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 350);
	sleep(250);
	Collection(700);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 1400);
	Auton_Drive_Targeted(FORWARD, 5);
	Collection(300);
	Auton_Drive_TurnTo(COUNTERCLOCKWISE, 2450);
	Auton_Drive_Targeted(FORWARD, 60);
	Lift_Target = 350;
	MinOverride = true;
	while(((SensorValue[EncoderLiftLeft] + SensorValue[EncoderLiftRight]) / 2) < 340) {}
	MinOverride = false;
	Auton_Drive_Targeted(FORWARD, 30);
	Collection(1000);
	writeDebugStreamLine("Cubes scored: %i:%2i.%-3i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true),LCD_Timer_Msecs(0,true));
	Auton_Drive_Targeted(BACKWARD, 50);
}
