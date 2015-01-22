#define BatteryIndicators

tSensors IndicatorBattB;

task BatteryIndicate {
	while(true) {
			if(((float)BackupBatteryLevel / (float)1000) < 8.7) {
				SensorValue[IndicatorBackup] = 1;
				} else {
				SensorValue[IndicatorBackup] = 0;
			}
			if(((float)nImmediateBatteryLevel / (float)1000) < 8.5) {
				SensorValue[IndicatorBattA] = 1;
				} else {
				SensorValue[IndicatorBattA] = 0;
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
	SensorValue[IndicatorBackup] = 0;
	SensorValue[IndicatorBattA] = 0;
	SensorValue[IndicatorBattB] = 0;
	sleep(100);
	SensorValue[IndicatorBattA] = 1;
	sleep(100);
	SensorValue[IndicatorBattA] = 0;
	SensorValue[IndicatorBattB] = 1;
	sleep(100);
	SensorValue[IndicatorBattB] = 0;
	SensorValue[IndicatorBackup] = 1;
	sleep(100);
	SensorValue[IndicatorBackup] = 0;
	sleep(100);
}
