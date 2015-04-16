// ROBOT:     2015A
// DRIVER:    John
// LIFT:      Btn6
// DRIVEFW:   Ch2
// DRIVELR:   Ch4
// DRIVETURN: Ch1
// CUBES:     Momentary Btn5D to release
// PYLONS:    Momentary Btn5U to toggle
int drivemultiplier = 1;
int dval = 0;
int deadband = 20;

task usercontrol {
	while(true) {
		// DRIVE
		dval = -(vexRT[Ch2] + vexRT[Ch4]) * drivemultiplier;
	motor[DriveFrontLeft] = dval < deadband && dval > -deadband ? 0 : dval;
		dval =  (vexRT[Ch2] - vexRT[Ch4]) * drivemultiplier;
	motor[DriveFrontRight] = dval < deadband && dval > -deadband ? 0 : dval;
		dval = -(vexRT[Ch2] + vexRT[Ch4]) * drivemultiplier;
	motor[DriveRearLeft] = dval < deadband && dval > -deadband ? 0 : dval;
		dval =  (vexRT[Ch2] - vexRT[Ch4]) * drivemultiplier;
	motor[DriveRearRight] = dval < deadband && dval > -deadband ? 0 : dval;
		motor[DriveCenterA] = vexRT[Ch1];//vexRT[Ch1] < deadband && vexRT[Ch1] > -deadband ? 0 : vexRT[Ch1];
		motor[DriveCenterB] = vexRT[Ch1];//vexRT[Ch1] < deadband && vexRT[Ch1] > -deadband ? 0 : vexRT[Ch1];
		// LIFT MANUAL
		if(vexRT[Btn6U] == 1 && !Lift_TrippedMax()) {
			IsStabilizerRunning = false;
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1) {
			IsStabilizerRunning = false;
			if(Lift_TrippedMin()) {
				Auton_Lift(DOWN, 25, 0, true);
				} else {
				Auton_Lift(DOWN, 127, 0, true);
			}
			} else {
			if(!IsStabilizerRunning) {
				Set_Lift_Target();
				startTask(Lift_Stabilizer_Left);
				startTask(Lift_Stabilizer_Right);
			}
		}
		SensorValue[SolenoidCubes] = !vexRT[Btn5D];
		SensorValue[SolenoidPylons] = vexRT[Btn5U];
	}
}
