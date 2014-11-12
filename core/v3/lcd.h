/********************************************************/
/*                        lcd.h                         */
/*                         v0.9                         */
/*                                                      */
/* This file was originally developed by:               */
/* Kristaps Berzinch                                    */
/* Programmer for Team 2105A                            */
/* Ware County High School                              */
/* Waycross, Georgia, USA                               */
/*                                                      */
/* Please drop me a line with questions or comments!    */
/* kberzinch@live.com                                   */
/* or on the VEX Forums: WCHSProgrammer                 */
/*                                                      */
/* You can do whatever you want with these files, but   */
/* please leave this and other credits sections intact. */
/*                                                      */
/* Neither I nor Ware County High School is responsible */
/* for any consequences.                                */
/********************************************************/

/********************************************************/
/*                     TWEAKER NOTES                    */
/*                                                      */
/* All of this code is completely safe. If you're       */
/* curious as to why a piece of code is written that    */
/* way, change it! If you still can't figure it out,    */
/* e-mail me. It may very well be a bug (or just my     */
/* personal preference).                                */
/*                                                      */
/* I do plan to put out a second version of this        */
/* header, so report anything you find and I'll give    */
/* you a mention. Again, this code is not competition-  */
/* tested. In fact, I wrote it almost entirely with the */
/* emulator. Use at your own risk.                      */
/*                                                      */
/* I make heavy use of compile-time logic to remove     */
/* unwanted features. It is suggested to leave any #    */
/* statements alone. Read Documentation.txt for         */
/* details.                                             */
/********************************************************/

/* General notes:
The backlight is turned on repeatedly. Needs to be fixed?
*/

// Warning statements to let user know if items were excluded.
// If you know how to make the compiler print infos instead of warnings, let me know!
#ifdef lcd.h
#warning ("Attempted to include lcd.h more than once. Only the first #include has taken effect.")
#warning ("If you already included an lcd_menu.h file, you don't need to #include lcd.h seperately.")
#else
#define lcd.h
#ifdef LCD_NotUsing_Menu
#warning ("LCD_Menu() and related functions and variables have been excluded from this compilation.")
#endif
#ifdef LCD_NotUsing_Prompt
// If the below warning is triggered, you have #define'd LCD_NotUsing_Prompt.
#warning ("LCD_Prompt(...) and related functions and variables have been excluded from this compilation.")
#endif
#ifdef LCD_NotUsing_Display
#warning ("LCD_Display and related functions and variables have been excluded from this compilation.")
#endif

#pragma systemFile // Prevents unused variable warnings

#ifndef LCD_NotUsing_Display
typedef struct {
	bool Paused;
	bool BattA;
	tSensors BattB;
	bool Backup;
} _LCD_Display; // User-facing struct to control LCD_Display task. See documentation.
#endif

#ifndef LCD_NotUsing_Menu
typedef struct {
	string Title;
	string Text;
	byte PrevIndex;
	byte SelectIndex;
	byte NextIndex;
} _LCD_Menu; // Struct stores a single menu item. The LCD struct uses an array of these instances to store a complete menu. Menu builder is responsible for validating the index numbers.
#endif

typedef struct {
#ifndef LCD_NotUsing_Menu
	bool IsFirstLoop;
	byte Index;
	_LCD_Menu Menu[LCD_SizeOfMenu];
#endif
#ifndef LCD_NotUsing_Display
	_LCD_Display Display;
#endif
#ifndef LCD_NotUsing_Display
	long Timer[4];
#endif
} _LCD;

_LCD LCD;

#ifndef LCD_NotUsing_Menu
void LCD_Menu_Define();
bool LCD_Menu_Execute();

void LCD_Menu_Display() {
	displayLCDCenteredString(0,LCD.Menu[LCD.Index].Title);
	displayLCDCenteredString(1,LCD.Menu[LCD.Index].Text);
	if(LCD.Menu[LCD.Index].PrevIndex != LCD.Index) {displayLCDChar(1, 0, 247);}
	if(LCD.Menu[LCD.Index].NextIndex != LCD.Index) {displayLCDChar(1, 15, 246);}
}

void LCD_Menu_Increment(char Direction) {
	switch(Direction)	{
	case -1:
		LCD.Index = LCD.Menu[LCD.Index].PrevIndex;
		break;
	case +1:
		LCD.Index = LCD.Menu[LCD.Index].NextIndex;
		break;
	}
}

void LCD_Menu() {
	LCD_Menu_Define();  // Menu builder is responsible for defining this
	LCD.IsFirstLoop = true;
	LCD.Index = 0;
	LCD.Display.Paused = true;
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	while(true)	{
		if(nLCDButtons != 0 || LCD.IsFirstLoop == true) {
			LCD.IsFirstLoop = false;
			if(nLCDButtons == 1) {LCD_Menu_Increment(-1);}
			if(nLCDButtons == 2) {
				if (LCD_Menu_Execute()) {
					LCD.Display.Paused = false;
					while (nLCDButtons != kButtonNone) {} // Does not exit function until all buttons are released.
					return;
				}
			}
			if(nLCDButtons == 4) {LCD_Menu_Increment(+1);}
			LCD_Menu_Display();
			while (nLCDButtons != kButtonNone) {} // Does not exit function until all buttons are released.
		}
	}
}
#endif

#ifndef LCD_NotUsing_Display
void LCD_Timer_Set(const char Timer, const float Value = 0) {
	LCD.Timer[Timer] = nSysTime - Value;
}

float LCD_Timer_Hours(const char Timer) {
	return (nSysTime - LCD.Timer[Timer]) / 3600000;
}

float LCD_Timer_Mins(const char Timer, const bool SubtractHigherUnit = false) {
	const float Time = (nSysTime - LCD.Timer[Timer]) / 1000;
	if (SubtractHigherUnit)	{
		return (Time - (floor(LCD_Timer_Hours(Timer)) * 3600)) / 60;
		} else {
		return Time / 60;
	}
}

float LCD_Timer_Secs(const char Timer, const bool SubtractHigherUnit = false) {
	const float Time = (nSysTime - LCD.Timer[Timer]) / 1000;
	if (SubtractHigherUnit)	{
		return Time - (floor(LCD_Timer_Mins(Timer)) * 60);
		} else {
		return Time;
	}
}

float LCD_Timer_Msecs(const char Timer, const bool SubtractHigherUnit = false) {
	const float Time = (nSysTime - LCD.Timer[Timer]);
	if (SubtractHigherUnit)	{
		return Time - (floor(LCD_Timer_Secs(Timer)) * 1000);
		} else {
		return Time;
	}
}

void LCD_Timer_WaitUntil(const char Timer, const float Value) {
	while (LCD_Timer_Msecs(Timer) < Value) {
		wait1Msec(1);
	}
}
#endif

#ifndef LCD_NotUsing_Display
task LCD_Display {
	LCD_Timer_Set(0,0);
	LCD.Display.Paused = false;
	char Char;
	char Index;
	char i;
	char j;
	string Text[3];
	Text[0] = "                   ";
	Text[1] = "                   ";
	Text[2] = "                   ";
	char LastProcessedStatus;
	clearLCDLine(0);
	clearLCDLine(1);
	bLCDBacklight = true;
	while (true) {
		for (i = 0; i < (strlen(Text[0]) + strlen(Text[1]) + strlen(Text[2])); i++) {
			setLCDPosition(1, 0);
			for (j = 0; j < 16; j++) {
				if (LCD.Display.BattA) {
					sprintf(Text[0], "Batt A: %1.2fv  ", (float)nImmediateBatteryLevel / (float)1000);
					} else {
					Text[0] = "";
				}
				if (LCD.Display.BattB != -1) {
					sprintf(Text[1], "Batt B: %1.2fv  ", (float)SensorValue[LCD.Display.BattB] / (float)280);
					} else {
					Text[1] = "";
				}
				if (LCD.Display.Backup) {
					sprintf(Text[2], "Backup: %1.2fv  ", (float)BackupBatteryLevel / (float)1000);
					} else {
					Text[2] = "";
				}
				if (!LCD.Display.BattA && LCD.Display.BattB == 0 && !LCD.Display.Backup) {
					Text[0] = "Must define LCD.Dis";
					Text[1] = "play.BattA, BattB, ";
					Text[2] = "and/or Backup. ";
				}
				Char = i + j;
				if ((strlen(Text[0])) > Char) {
					Index = 0;
					} else if((strlen(Text[0]) + strlen(Text[1])) > Char) {
					Index = 1;
					Char -= strlen(Text[0]);
					} else if((strlen(Text[0]) + strlen(Text[1]) + strlen(Text[2])) > Char) {
					Index = 2;
					Char -= strlen(Text[0]) + strlen(Text[1]);
					} else if((strlen(Text[0]) + strlen(Text[1]) + strlen(Text[2]) - 1) < Char) {
					Index = 0;
					Char -= strlen(Text[0]) + strlen(Text[1]) + strlen(Text[2]);
				}
				while(LCD.Display.Paused) {}
				displayNextLCDChar(stringGetChar(Text[Index], Char));
			}
			if(Competition.IsBlue) {
				displayLCDString(0,0,"B");
				} else {
				displayLCDString(0,0,"R");
			}
			if(Competition.AtLoader) {
				displayLCDString(0,1,"A");
				} else {
				displayLCDString(0,1,"F");
			}
			if (bIfiRobotDisabled) {
				displayLCDString(0, 3, "Disabled");
				Competition.Status = 0;
				}	else {
				if (bIfiAutonomousMode) {
					displayLCDString(0, 3, "Auton");
					Competition.Status = 1;
					} else {
					displayLCDString(0, 3, "Driver    ");
					Competition.Status = 2;
				}
			}
			if(LastProcessedStatus != Competition.Status) {
				LCD_Timer_Set(0,0);
				} else {
				displayLCDNumber(0, 11, LCD_Timer_Mins(0), 2);
				displayLCDChar(0, 13, 58);
				displayLCDNumber(0, 14, LCD_Timer_Secs(0,true), -2);
			}
			LastProcessedStatus = Competition.Status;
			while (nLCDButtons != 0) {}
			sleep(200);
		}
	}
}
#endif

#ifndef LCD_NotUsing_Prompt
void LCD_Prompt_Blink(const bool Blink, const string Choice1, const string Choice2, const string Choice3, const char DefaultChoice) {
	switch (Blink) {
	case true:
		switch (DefaultChoice) {
		case 1:
			displayLCDString(1, 0, Choice1);
			break;
		case 2:
			displayLCDCenteredString(1, Choice2);
			displayLCDString(1, 0, Choice1);
			displayLCDString(1, 12, Choice3);
			break;
		case 3:
			displayLCDString(1, 12, Choice3);
			break;
		}
		break;
	case false:
		switch (DefaultChoice) {
		case 1:
			displayLCDString(1, 0, "    ");
			break;
		case 2:
			clearLCDLine(1);
			displayLCDString(1, 0, Choice1);
			displayLCDString(1, 12, Choice3);
			break;
		case 3:
			displayLCDString(1, 12, "    ");
			break;
		}
		break;
	}
}

char LCD_Prompt(const string Prompt1 = " ", const string Prompt2 = "", const string Choice1 = "", const string Choice2 = "OK", const string Choice3 = "", const char DefaultChoice = 0, const char DefaultTimeOut = 0) {
	if (DefaultTimeOut !=0 && DefaultChoice != 0)	{
		LCD_Timer_Set(1);
		LCD_Timer_Set(2);
	}
	LCD.Display.Paused = true;
	bool Blink;
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(1, Choice2);
	displayLCDString(1, 0, Choice1);
	displayLCDString(1, 12, Choice3);
	if (strlen(Prompt1) <= 16) {
		displayLCDString(0, 0, Prompt1);
		while (true) {
			if (DefaultTimeOut !=0 && DefaultChoice != 0) {
				if (LCD_Timer_Secs(1) >= DefaultTimeOut) {LCD.Display.Paused = false;return DefaultChoice;}
				if (LCD_Timer_Msecs(2) >= 250) {
					LCD_Timer_Set(2);
					Blink = !Blink;
					LCD_Prompt_Blink(Blink, Choice1, Choice2, Choice3, DefaultChoice);
				}
			}
			while (LCD_Timer_Msecs(3) <= 250) {
				if (nLCDButtons == 1 && Choice1 != "") {LCD.Display.Paused = false;return 1;}
				if (nLCDButtons == 2 && Choice2 != "") {LCD.Display.Paused = false;return 2;}
				if (nLCDButtons == 4 && Choice3 != "") {LCD.Display.Paused = false;return 3;}
			}
			LCD_Timer_Set(3);
		}
		} else {
		char i;
		char j;
		char Char;
		char Pnum;
		while (true) {
			for (i = 0; i < (strlen(Prompt1) + strlen(Prompt2)); i++) {
				setLCDPosition(0, 0);
				for (j = 0; j < 16; j++) {
					Char = i + j;
					if ((strlen(Prompt1)) > Char) {
						Pnum = 0;
						} else if((strlen(Prompt1) + strlen(Prompt2)) > Char) {
						Pnum = 1;
						Char -= strlen(Prompt1);
						} else if((strlen(Prompt1) + strlen(Prompt2) - 1) < Char) {
						Pnum = 0;
						Char -= strlen(Prompt1) + strlen(Prompt2);
					}
					switch (Pnum) {
					case 0:
						displayNextLCDChar(stringGetChar(Prompt1, Char));
						break;
					case 1:
						displayNextLCDChar(stringGetChar(Prompt2, Char));
						break;
					}
				}
				while (LCD_Timer_Msecs(3) <= 250)	{
					if (nLCDButtons == 1 && Choice1 != "") {LCD.Display.Paused = false;return 1;}
					if (nLCDButtons == 2 && Choice2 != "") {LCD.Display.Paused = false;return 2;}
					if (nLCDButtons == 4 && Choice3 != "") {LCD.Display.Paused = false;return 3;}
				}
				LCD_Timer_Set(3);
				Blink = !Blink;
				LCD_Prompt_Blink(Blink, Choice1, Choice2, Choice3, DefaultChoice);
				if (DefaultTimeOut !=0 && DefaultChoice != 0)	{
					if (LCD_Timer_Secs(1) >= DefaultTimeOut) {LCD.Display.Paused = false;return DefaultChoice;}
				}
			}
		}
	}
}
#endif
#endif
