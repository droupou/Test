/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Mon Mar 26 20:50:48 CST 2001
    copyright            : (C) 2001 by Droupou
    email                : droupou@abyss.cowboy.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/*
	This is a Dungeon and Dragons Program for the 3rd Edition D&D.
	This program will roll up characters.
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdlib.h>
#include <iostream.h>
#include <stdio.h>
#include "Dice.h"
#include "droupoustd.h"
#include "human.h"
#include "monster.h"

//i = dice(k);

void RDice()
{
	// Declarations
	int d = 1;
	int r;
	int t;
	
	while(d != 0)
	{
		cout << "What Sided Die would you like to roll? (0 to quit)" << endl << endl;
		cout << "#";
		cin >> d;
		
		if(d != 0)
		{
			cout << "How man times would you like to roll the dice?" << endl;
			cout << "#";
			cin >> t;
			clear_sc();
			for(int c = 0; c < t; c++)
			{
				r = dice(d);
				cout << r << endl;
			}
			
			pause_sc();
			pause_sc();
			clear_sc();
		}
	}
}


int main()
{
	// Declaration of variables.
	int choice, rndscr;
	
	//Start with a clear screen.
	clear_sc();
	clear_sc();
	
	// Get random input to start the whole thing off.
	cout << "Please input a random number." << endl << "#";
	cin >> rndscr;
	cout << endl;
	dice(rndscr);
	// Main Page
	
	while(choice != 0)
	{
		cout << "Please choose from the following menu:" << endl << endl;
		cout << "0.	Exit." << endl;
		cout << "1.	Roll Dice." << endl;
		cout << "2.	Generate NPC." << endl;
		cout << "3.	Generate Monster." << endl;
		
		cout << "#";
		cin >> choice;
		cout << endl;
		
		if(choice == 0)
		{
			clear_sc();
			cout << "Goodbye!" << endl;
		}
		else if(choice == 1)
		{
			RDice();
			clear_sc();
		}
		else if(choice == 2)
		{
			GNPC();
			pause_sc();
			pause_sc();
			clear_sc();
		}
		else if(choice ==3)
		{
			Monster();
			clear_sc();
		}
		else
		{
			cout << "ERROR!!!" << endl;
			pause_sc();
			pause_sc();
			clear_sc();
		}
	}
   return 0;
}
