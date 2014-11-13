task autonomous {
	switch(Competition.IsBlue) {
	case true:
		switch(Competition.AtLoader) {
		case true:
			switch(Competition.Auton) {
			case 1:
				Auton_Blue_AtLoader_Pylon();
				break;
			case 2:
				Auton_Blue_AtLoader_Cube();
				break;
			}
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
	LCD.Display.Paused = true;
}
