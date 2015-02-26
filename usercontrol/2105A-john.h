// ROBOT:  2015A
// DRIVER: John\
int preset_triggered = false;
int drivemultiplier = -1;
int dval = 0;
int deadband = 20;
int LastLeft = 0;

task usercontrol {
	//startTask(usercontrol_liftpresets);*/
	while(true) {

		// CONTROL TOGGLE
		if(vexRT[Btn7D] == 1 && LastLeft == 0) {
			drivemultiplier = -drivemultiplier;
			writeDebugStreamLine("toggle to %i", drivemultiplier);
			LastLeft = 1;
			} else if(vexRT[Btn7D] == 0 && LastLeft == 1) {
			LastLeft = 0;
		}

		// DRIVE
		dval = (-vexRT[Ch2] - vexRT[Ch1] - vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveFrontLeft]   = dval < deadband && dval > -deadband ? 0 : dval;
		dval = ( vexRT[Ch2] + vexRT[Ch1] - vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveRearRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] + vexRT[Ch1] - vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveRearLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = ( vexRT[Ch2] - vexRT[Ch1] - vexRT[Ch4] * drivemultiplier) * drivemultiplier;
	motor[DriveFrontRight] = dval < deadband && dval > -deadband ? 0 : dval;

		// PRESET RESET
		if(Lift_TrippedMin()) {
			SensorValue[LiftEncoder] = 0;
		}

		// LIFT MANUAL
		if(!preset_triggered) {
			if(vexRT[Btn5U] == 1 && !Lift_TrippedMax()) {
				Auton_Lift(UP);
				} else if(vexRT[Btn5D] == 1 && !Lift_TrippedMin()) {
				Auton_Lift(DOWN);
				} else {
				Auton_Lift();
			}
		}

		// PNEUMATICS
		/*if(vexRT[Btn6D] == 1) {
			SensorValue[SolenoidB] = 0;
			} else if(vexRT[Btn6U] == 1) {
			SensorValue[SolenoidB] = 1;
		}*/
		if(vexRT[Btn6U] == 1) {
			Claw(OPEN);
			} else if(vexRT[Btn6D] == 1) {
			Claw(CLOSE);
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
