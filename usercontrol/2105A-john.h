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
	startTask(PylonLock);
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
		motor[DriveCenter] = vexRT[Ch1] < deadband && vexRT[Ch1] > -deadband ? 0 : vexRT[Ch1];

		// LIFT MANUAL
		if(vexRT[Btn6U] == 1 && !Lift_TrippedMax()) {
			IsStabilizerRunning = false;
			Auton_Lift(UP);
			} else if(vexRT[Btn6D] == 1 && !Lift_TrippedMin()) {
			IsStabilizerRunning = false;
			Auton_Lift(DOWN);
			} else {
			if(!IsStabilizerRunning) {
				Set_Lift_Target();
				startTask(Lift_Stabilizer_Left);
				startTask(Lift_Stabilizer_Right);
			}
		}
		SensorValue[SolenoidCubes] = !vexRT[Btn5D];
		SensorValue[SolenoidPylons] = vexRT[Btn5U];
		if(vexRT[Btn7L] == 1) {
			Pylon_Target = 1000;
			} else if(vexRT[Btn7R] == 1) {
			Pylon_Target = 3000;
			} else {
			Pylon_Target = 1950;
		}
	}
}
