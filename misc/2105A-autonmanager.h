task autonomous {
	if(Competition.Auton == 3) {
	Auton_Progskills();
}
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.AtLoader) {
		case true:
			Auton_Blue_AtLoader();
			break;
		case false:
			Auton_Blue_Freedom();
			break;
		}
		break;
	case false:
		switch(Competition.AtLoader) {
		case true:
			Auton_Red_AtLoader();
			break;
		case false:
			Auton_Red_Freedom();
			break;
		}
		break;
	}
	writeDebugStreamLine("Autonomous finished");
	writeDebugStreamLine(" - Total time: %i:%i",LCD_Timer_Mins(0),LCD_Timer_Secs(0,true));
	writeDebugStreamLine(" - Batt A   %1.2fv", (float)nImmediateBatteryLevel / (float)1000);
#ifndef NoPowerExpander
	writeDebugStreamLine(" - Batt B   %1.2fv", (float)SensorValue[PowerExpander] / (float)280); // TBD: Verify magic number
#endif
	writeDebugStreamLine(" - Backup   %1.2fv", (float)BackupBatteryLevel / (float)1000);
	LCD.Display.Paused = true;
	ResetDriveEncoders();
}
