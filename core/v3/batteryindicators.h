#define BatteryIndicators

task BatteryIndicate {
	while(true) {
		if(((float)BackupBatteryLevel / (float)1000) < 7) {
			SensorValue[BackupBattLEDRed] = 1;
			SensorValue[BackupBattLEDGreen] = 0;
			} else {
			SensorValue[BackupBattLEDRed] = 0;
			SensorValue[BackupBattLEDGreen] = 1;
		}
		if(((float)nImmediateBatteryLevel / (float)1000) < 8) {
			SensorValue[MainBattLEDRed] = 1;
			SensorValue[MainBattLEDGreen] = 0;
			} else {
			SensorValue[MainBattLEDRed] = 0;
			SensorValue[MainBattLEDGreen] = 1;
		}
#ifndef NoPowerExpander
		if(((float)SensorValue[PowerExpander] / (float)280) < 8.5) {
			SensorValue[IndicatorBattB] = 1;
			} else {
			SensorValue[IndicatorBattB] = 0;
		}
#endif
	}
}

void TestIndicators() {
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 1;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 1;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 1;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 1;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 1;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 1;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 1;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 1;
	SensorValue[MainBattLEDRed]     = 1;
	SensorValue[BackupBattLEDGreen] = 1;
	SensorValue[BackupBattLEDRed]   = 1;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 1;
	SensorValue[MainBattLEDRed]     = 1;
	SensorValue[BackupBattLEDGreen] = 1;
	SensorValue[BackupBattLEDRed]   = 1;
	sleep(100);
	SensorValue[MainBattLEDGreen]   = 0;
	SensorValue[MainBattLEDRed]     = 0;
	SensorValue[BackupBattLEDGreen] = 0;
	SensorValue[BackupBattLEDRed]   = 0;
}
