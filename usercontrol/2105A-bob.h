// ROBOT:  2015A
// DRIVER: Bob

task usercontrol_liftpresets;
int preset_triggered = false;

task usercontrol {
	startTask(usercontrol_liftpresets);
	while(true) {
		// DRIVE
		motor[DriveRearLeft]   =  vexRT[Ch1] - vexRT[Ch3] - vexRT[Ch4];
		motor[DriveFrontLeft]  = -vexRT[Ch1] - vexRT[Ch3] - vexRT[Ch4];
		motor[DriveRearRight]  =  vexRT[Ch1] + vexRT[Ch3] - vexRT[Ch4];
		motor[DriveFrontRight] = -vexRT[Ch1] + vexRT[Ch3] - vexRT[Ch4];

		// PRESET RESET
		if(SensorValue[LiftLimitMinA] == 0 || SensorValue[LiftLimitMinB] == 0) {
			SensorValue[LiftEncoder] = 0;
		}

		// LIFT MANUAL
		if(!preset_triggered) {
			if(vexRT[Btn6U] == 1 && SensorValue[LiftLimitMax] != 0) {
				Auton_Lift(UP);
				} else if(vexRT[Btn6D] == 1 && SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0) {
				Auton_Lift(DOWN);
				} else {
				Auton_Lift();
			}
		}
	}
}

task usercontrol_liftpresets {
	while(true) {
		if(vexRT[Btn7D] ==  1 && SensorValue[LiftLimitMinA] != 0 && SensorValue[LiftLimitMinB] != 0) {
			preset_triggered = true;
			Auton_Lift_Targeted(DOWN,0);
		}
		if(vexRT[Btn7R] == 1) {
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
