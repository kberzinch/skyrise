/********************************************************/
/*                   lcd_menu_blank.h                   */
/*                        v0.9                          */
/*                                                      */
/* This file was originally developed by:               */
/* Kristaps Berzinch                                    */
/* Programmer for Team 2105A                            */
/* Ware County High School                              */
/* Waycross, Georgia, USA                               */
/*                                                      */
/* Please drop me a line with questions or comments!    */
/* kberzinch@live.com                                   */
/* or on the VEX Forums: WCHS Programmer                */
/*                                                      */
/* You can do whatever you want with these files, but   */
/* please leave this and other credits sections intact. */
/*                                                      */
/* Neither I nor Ware County High School is responsible */
/* for any consequences.                                */
/********************************************************/

const char LCD_SizeOfMenu = 4; // MUST be at least 1 to prevent crash

#undef LCD_NotUsing_Menu       // Clear any statements against compiling LCD_Menu.
                               // If you don't want it, why would you include it?

typedef struct {
	bool IsBlue;
	bool AtLoader;
	bool Set;
	char Auton;
	byte Status;
} _Competition;

_Competition Competition;

#include "lcd.h";

void LCD_Menu_Define()
{
	char i;
	for (i = 0; i < LCD_SizeOfMenu; i++)
	{
		LCD.Menu[i].Title = "";
		LCD.Menu[i].Text = "";
		LCD.Menu[i].PrevIndex = i - 1;
		LCD.Menu[i].SelectIndex = -1;
		LCD.Menu[i].NextIndex = i + 1;
	}
	LCD.Menu[0].Title = "Color";
	LCD.Menu[0].Text = "Red";
	LCD.Menu[0].PrevIndex = 0;
	LCD.Menu[0].SelectIndex = 2;

	LCD.Menu[1].Title = LCD.Menu[0].Title;
	LCD.Menu[1].Text = "Blue";
	LCD.Menu[1].SelectIndex = 2;
	LCD.Menu[1].NextIndex = 1;

	LCD.Menu[2].Title = "Start Point";
	LCD.Menu[2].Text = "Autoloader";
	LCD.Menu[2].PrevIndex = 2;

	LCD.Menu[3].Title = LCD.Menu[2].Title;
	LCD.Menu[3].Text = "Interaction";
	LCD.Menu[3].NextIndex = 3;
}

bool LCD_Menu_Execute()
{
	switch(LCD.Index)
	{
	case 0:
		Competition.IsBlue = false;
		break;
	case 1:
		Competition.IsBlue = true;
		break;
	case 2:
		Competition.AtLoader = true;
		break;
	case 3:
		Competition.AtLoader = false;
		break;
	}
	if (LCD.Menu[LCD.Index].SelectIndex == -1)
	{
		return true;
		} else {
		LCD.Index = LCD.Menu[LCD.Index].SelectIndex;
		return false;
	}
}
