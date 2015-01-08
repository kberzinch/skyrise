void Auton_Blue_Freedom() {
	Collection(-127);
	sleep(800);
	Collection();
	Auton_Drive(FORWARD);
	sleep(600);
	Collection(127);
	sleep(1000);
	Auton_Drive();
	sleep(1000);
}
