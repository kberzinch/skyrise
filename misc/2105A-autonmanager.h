task autonomous {
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.AtLoader) {
		case true:
			Auton_Blue_AtLoader();
			break;
		case false:
			//Auton_Blue_Freedom();
			break;
		}
		break;
	case false:
		switch(Competition.AtLoader) {
		case true:
			//Auton_Red_AtLoader();
			break;
		case false:
			//Auton_Red_Freedom();
			break;
		}
		break;
	}
	writeDebugStreamLine("Total time: %i:%i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true));
	LCD.Display.Paused = true;
	ResetDriveEncoders();
	writeDebugStreamLine("Autonomous finished");
}
