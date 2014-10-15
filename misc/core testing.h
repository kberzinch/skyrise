void ResetDriveEncoders() {
#if defined(_DEBUG)
    writeDebugStreamLine("Drive encoders reset");
#endif
}

void init() {
	// Initializes sensors, anything else that needs to be done in software before autonomous
}

// TBD: Auton manager, automatic claw control task available to start on-demand
// Auton, driver controls in seperate .h files
