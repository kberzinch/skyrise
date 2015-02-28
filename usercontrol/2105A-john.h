// ROBOT:  2015A
// DRIVER: John
int preset_triggered = false;
int drivemultiplier = 1;
int dval = 0;
int deadband = 20;
bool autoninprogress = false;

task usercontrol {
	//startTask(usercontrol_liftpresets);*/
	while(true) {
		// DRIVE
	if(!autoninprogress) {
		dval = (-vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveFrontLeft]   = dval < deadband && dval > -deadband ? 0 : dval;
		dval = ( vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveRearRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveRearLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = ( vexRT[Ch2] - vexRT[Ch1] + vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveFrontRight] = dval < deadband && dval > -deadband ? 0 : dval;
}
		// MACRO
		if(vexRT[Btn7U] == 1 && vexRT[Btn7L] == 1) {
			Competition.IsBlue = true;
			startTask(autonomous);
			autoninprogress = true;
		}
		if(vexRT[Btn7R] == 1) {
			stopTask(autonomous);
			autoninprogress = false;
		}

		// PRESET RESET
		if(Lift_TrippedMin()) {
			SensorValue[LiftEncoder] = 0;
		}

		// LIFT MANUAL
	if(!autoninprogress) {
		if(!preset_triggered) {
			if(vexRT[Btn5U] == 1 && !Lift_TrippedMax()) {
				Auton_Lift(UP);
				} else if(vexRT[Btn5D] == 1 && !Lift_TrippedMin()) {
				Auton_Lift(DOWN);
				} else {
				Auton_Lift();
			}
		}
	}

		// PNEUMATICS
		/*if(vexRT[Btn6D] == 1) {
		SensorValue[SolenoidB] = 0;
		} else if(vexRT[Btn6U] == 1) {
		SensorValue[SolenoidB] = 1;
		}*/
		if(vexRT[Btn6U] == 1) {
			Claw(CLOSE);
			} else if(vexRT[Btn6D] == 1) {
			Claw(OPEN);
		}
	}
}
/*
task usercontrol_liftpresets {
while(true) {
if(vexRT[Btn8D] ==  1 && !Lift_TrippedMin()) {
preset_triggered = true;
Auton_Lift_Targeted(DOWN,0);
}
if(vexRT[Btn8R] == 1) {
preset_triggered = true;
if(SensorValue[LiftEncoder] < -400) {
Auton_Lift_Targeted(DOWN,400);
Auton_Lift(UP,63,100);
} else {
Auton_Lift_Targeted(UP,250);
}
}
preset_triggered = false;
}
}
*/
