task autonomous {
	if(Competition.Auton == 3) {
	Auton_Progskills();
	AutonDataDump();
	stopTask(autonomous);
	}
	switch(Competition.IsBlue) {
	case true:
		Auton_Blue_AtLoader();
		break;
	case false:
		Auton_Red_AtLoader();
		break;
	}
	AutonDataDump();
}
