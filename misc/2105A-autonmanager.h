task autonomous {
	switch(Competition.IsBlue) {
	case true:
		writeDebugStreamLine("Is Blue");
		switch(Competition.AtLoader) {
		case true:
			writeDebugStreamLine("At Autoloader");
			Auton_Blue_AtLoader();
			writeDebugStreamLine("End Function");
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
}
