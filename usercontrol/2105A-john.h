// ROBOT:  2015A
// DRIVER: John

task usercontrol_liftpresets;
int preset_triggered = false;
float drivemultiplier = 1;
int dval = 0;
int deadband = 20;

task usercontrol {
	startTask(usercontrol_liftpresets);
	while(true) {
		// DRIVE
		if(vexRT[Btn5D] == 1) {
			drivemultiplier = 0.5;
		} else {
			drivemultiplier = 1;
		}
		dval = vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4] * drivemultiplier;
		motor[DriveRearLeft]   = dval < deadband && dval > -deadband ? 0 : dval;
		dval = -vexRT[Ch1] - vexRT[Ch2] - vexRT[Ch4] * drivemultiplier;
		motor[DriveFrontLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval =  vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4] * drivemultiplier;
		motor[DriveRearRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = -vexRT[Ch1] + vexRT[Ch2] - vexRT[Ch4] * drivemultiplier;
		motor[DriveFrontRight] = dval < deadband && dval > -deadband ? 0 : dval;

		// PRESET RESET
		if(Lift_TrippedMin()) {
			SensorValue[LiftEncoder] = 0;
		}

		// LIFT MANUAL
		if(!preset_triggered) {
			if(vexRT[Btn6U] == 1 && !Lift_TrippedMax()) {
				Auton_Lift(UP);
				} else if(vexRT[Btn6D] == 1 && !Lift_TrippedMin()) {
				Auton_Lift(DOWN);
				} else {
				Auton_Lift();
			}
		}
	}
}

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
