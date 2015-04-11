task autonomous {
	/*if(Competition.Auton == 3) {
	Auton_Progskills();
#if defined(_DEBUG)
	AutonDataDump();
#endif
	allMotorsOff();
	stopTask(autonomous);
	}*/
	switch(Competition.AtLoader) {
	case true:
		switch(Competition.IsBlue) {
		case true:
			//Auton_Blue_AtLoader();
			break;
		case false:
			//Auton_Red_AtLoader();
			break;
		}
		break;
	case false:
		switch(Competition.IsBlue) {
		case true:
			//Auton_Blue_Freedom();
			break;
		case false:
			Auton_Red_Freedom();
			break;
		}
		break;
	}
	allMotorsOff();
#if defined(_DEBUG)
	AutonDataDump();
#endif
}
