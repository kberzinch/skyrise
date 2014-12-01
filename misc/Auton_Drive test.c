if(vexRT[Btn7U] == 1) {
	Auton_Drive(FORWARD);
	} else if(vexRT[Btn7D] == 1) {
	Auton_Drive(BACKWARD);
	} else if(vexRT[Btn7L] == 1) {
	Auton_Drive(LEFT);
	} else if(vexRT[Btn7R] == 1) {
	Auton_Drive(RIGHT);
	} else if(vexRT[Btn8L] == 1) {
	Auton_Drive(COUNTERCLOCKWISE);
	} else if(vexRT[Btn8R] == 1) {
	Auton_Drive(CLOCKWISE);
	} else {
	Auton_Drive(STOP);
}
