task autonomous {
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
	allMotorsOff();
	AutonDataDump();
}
