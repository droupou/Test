/***************************************************************************
                          human.h  -  description
                             -------------------
    begin                : Mon Mar 26 2001
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
  	Weapons --
  	This is the function for the selection of Simple Weapons. Including:
  	(1) Gauntlet
  	(2) Strikes
  	(3) Dagger
  	(4) Spiked Gauntlet
  	(5) Light Mace
  	(6) Sickle
  	(7) Club Halfspear
  	(8) Heavy Mace
  	(9) Morningstar
  	(10) Quarterstaff
  	(11) Shortspear
  	(12) Light Crossbow
  	(13) Dart
  	(14) Sling
  	(15) Heavy Crossbow
  	(16) Javelin
  	(17) Throwing Axe
  	(18) Light Hammer
  	(19) Handaxe
  	(20) Sap
  	(21) Short Sword
  	(22) Battleaxe
  	(23) Longsword
  	(24) Heavy Pick
  	(25) Rapier
  	(26) Scimitar
  	(27) Trident
  	(28) War Hammer
  	(29) Falchion
  	(30) Greataxe
  	(31) Greatclub
  	(32) Greatsword
  	(33) Scythe
  	(34) Short Bow
  	(35) Composite Short bow
  	(36) Longbow
  	(37) Composite Longbow
  	(38) Kukri
  	(39) Kama
  	(40) Nunchaku
  	(41) Siangham
  	(42) Bastard Sword
  	(43) Dwarven Waraxe
  	(44) Orc double Axe
  	(45) Spiked Chain
  	(46) Hand Crossbow
  	(47) Shuriken
  	(48) Whip
  	(49) Net
  	(50) Magical Weapon
*/


/*
	This file contains all (Theoretically) human Classes used by a DM.
*/

int trh = 0, NStat[2][100], select1, level, load[7][100], HP = 0, WeapPick = 0, cnt1 = 0;
char Temp[50], Stat[6][4] = { "Str", "Dex", "Con", "Int", "Wis", "Cha"};

// types
char Class_O[6][255] = {"Pesant         ", "Fighter/Paladin", "Cleric         ", "Wizard/Sorcerer", "Theif/Assasin  ", "Barbarian      "};
char Race_O[7][255] =  {"Dwarven        ", "Elvin          ", "Human          ", "Halfling       ", "Gnome          " , "Half-Orc      ", "Half-Elf       "};
 		

/*
	CharPool will consist of: CharPool[x][y][z] such that:
		x = the character number available referenced.
		y = the stat type.
			1		class
			2		race
			3		level
			4		strength
			5		dexterity
			6		constitution
			7		intelligence
			8		wisdom
			9		charisma
			10	HP
			11	AC
			12	Weapon
	
*/
int CharPool[99][13];
		
int Race()
{
	int holdR;
	cout << "What Race would you like it (them) to be?" << endl;
	cout << "1. Dwarven." << endl;
	cout << "2. Elvin." << endl;
	cout << "3. Human." << endl;
	cout << "4. Halfling." << endl;
	cout << "5. Gnome." << endl;
	cout << "6. Half-Orc." << endl;
	cout << "7. Half-Elf." << endl;
	cout << "#";
	cin >> holdR;
	cout << endl;
	
	return holdR;
	
}

int Class()
{
 	// TEST
 	// int CRAP;
 	
 	cout << "What type of NPC would you like to make?" << endl << endl;
	cout << "1.	Pesant." << endl;
	cout << "2.	Fighter/Paladin." << endl;
	cout << "3.	Cleric." << endl;
	cout << "4.	Wizard/Sorcerer." << endl;
	cout << "5.	Theif/Assasin." << endl;
	cout << "6.	Barbarian." << endl;
	cout << "#";
	cin >> select1;
	
	// TEST
	//cout << "returning " << select1 << endl;
	//cin >> CRAP;
	
	return select1;
	
}

// Print out the Characters one by one.  Only allow X number to be printed across.
void PrintChar(int CharPool[99][13])
{
 		
 		// Variable declarations
 		int count1 = 0, four = 0, offsety = 0, offsetx = 2;
 		
 		// Start off with a clear screen
 		clear_sc();
 		clear_sc();
 		
 		// Print out the Characters
  	//while((CharPool[count1][1]>0) && (CharPool[count1][1]<50))
  	while(count1 < cnt1)
  	{
  		// Print out the first line.  All of the Classes.
  		cout << "\033[" << offsetx << ";" << offsety << "H";
  		cout << " Class:\t" << Class_O[((CharPool[count1][1])-1)];
  		cout << endl;
  		
  		// Print out the second line. All of the Races.
  		cout << "\033[" << offsety << "C";
  		cout << "Race:\t" << Race_O[((CharPool[count1][2])-1)];
  		cout << endl;
  		
  		// Print out the third line.  All of the Levels.
  		cout << "\033[" << offsety << "C";
  		cout << "Level:\t" << CharPool[count1][3];
  		cout << endl;
  		
  		//Print out the fourth line.  All of the Strength.
  		cout << "\033[" << offsety << "C";
  		cout << "Str: \t" << CharPool[count1][4];
  		cout << endl;
  		
  		//Print out the fifth line.  All of the Dexterity.
  		cout << "\033[" << offsety << "C";
  		cout << "Dex: \t" << CharPool[count1][5];
  		cout << endl;
  		
  		//Print out the sixth line.  All of the Constitution.
  		cout << "\033[" << offsety << "C";
  		cout << "Con: \t" << CharPool[count1][6];
  		cout << endl;
  		
  		//Print out the seventh line.  All of the Intelligence.
  		cout << "\033[" << offsety << "C";
  		cout << "Int: \t" << CharPool[count1][7];
  		cout << endl;
  		
  		//Print out the eighth line.  All of the Wisdom.
  		cout << "\033[" << offsety << "C";
  		cout << "Wis: \t" << CharPool[count1][8];
  		cout << endl;
  		
  		//Print out the ninth line.  All of the Charisma.
  		cout << "\033[" << offsety << "C";
  		cout << "Cha: \t" << CharPool[count1][9];
  		cout << endl;
  		
  		//Print out the tenth line.  All of the Hitpoints.
  		cout << "\033[" << offsety << "C";
  		cout << "HP:  \t" << CharPool[count1][10];
  		cout << endl;
  		
  		//Print out the eleventh line.  All of the Armor Class.
  		cout << "\033[" << offsety << "C";
  		cout << "AC:  \t" << CharPool[count1][11];
  		cout << endl;
  		
  		char Weapon_O[51][255] = {"Gauntlet (1d3)", "Unarmed Strikes (1d3)", "Dagger (1d4)", "Spiked Gauntlet (1d4)", "Light Mace (1d4)", "Sickle (1d6)", "Club (1d6)", "Heavy Mace (1d8)", "Morningstar (1d8)", "Quarterstaff (1d6/1d6)", "Shortspear(1d8)", "Light Crossbow (1d8)", "Dart (1d4)", "Sling (1d4)", "Heavy Crossbow (1d10)", "Javelin (1d6)", "Throwing Axe (1d6)", "Light Hammer (1d4)", "Handaxe (1d6)", "Sap (1d6)", "Short Sword (1d6)", "Battleaxe (1d8)", "Longsword (1d8)", "Heavy Pick (1d6)", "Rapier (1d6)", "Scimitar (1d6)", "Trident (1d8)", "War Hammer (1d8)", "Falchion (2d4)", "Greataxe (1d12)", "Greatclub (1d10)", "Greatsword (2d6)", "Scythe (2d4)", "Short Bow (1d6)", "Composite Short Bow (1d6)", "Longbow (1d8)", "Composite Longbow (1d8)", "Kukri (1d4)", "Kama (1d6)", "Nunchaku (1d6)", "Siangham (1d6)", "Bastard Sword (1d10)", "Dwarven Waraxe (1d10)", "Orc Double Axe (1d8/1d8)", "Spiked Chain (2d4)", "Hand Crossbow (1d4)", "Shuriken (1)", "Whip (1d2)", "Net (Holds Character)", "Magical Weapon (See DM Guide.)", "Halfspear (1d6)"};
  		
  		//Print out the twelveth line.  All of the Weapon.
  		cout << "\033[" << offsety << "C";
  		cout << "Weapon: " << Weapon_O[((CharPool[count1][12])-1)];
  		cout << endl;
  		
  		// end the loop with a couple of returns and an increment on the count1.
  		count1 ++;
  		
  		// Start the next row.
  		cout << "\033[" << offsetx << ";" << offsety << "H";
  		
  		offsety = (offsety + 40);
  		four ++;
  		if(four == 3)
  		{
  		 	cout << endl;
  		 	four = 0;
  		 	offsety = 0;
  		 	offsetx = (offsetx + 15);
  		}
  		
  	}
 		for(int c = 0; c < count1; c++)
 		{
 		 	for( int c1 = 0; c1 < 12; c1 ++)
 		 	{
 		 	 	CharPool[c][c1] = 0;
 		 	}
 		}
  	// End Print out the Characters
  	
}

void GNPC()
{
	// variables that are only used in this section.
	int num = 0, rand, Class_h, Race_h, Level_h;
	char cont = 'y';
	
start:
	// continue untill user asks for 0 NPC's.
 	while(cont == 'y')
	{
   	
   	// Take it by groupings.
  	cout << endl << "What is the first type going to be?" << endl;	
  	Class_h = Class();
  	Race_h = Race();
  	 	 	
  	// level
  	cout << "What level would you like this group to be?" << endl;
  	cin >> Level_h;
  	 	 	
  	
   	// TEST
  	// cout << "cnt1 = " << cnt1 << endl;
  		
  	//Get the number of NPC's.
  	cout << "How many NPC's would you like in this group?" << endl;
		cin >> num;
		num = (num + cnt1);
		
 	 	for(; cnt1 < num;cnt1 ++)
	 	 	{
	 	 			// Store creatures class.
	 	 			CharPool[cnt1][1] = Class_h;
	 	 			// TEST
	 	 			//cout << "character type: " << Class_O[((CharPool[cnt1][1])-1)] << endl;
  	 	 			
	 	 			// Store creatures race.
	 	 			CharPool[cnt1][2] = Race_h;
  	 	 			
	 	 			//Store creatures level.
	 	 			CharPool[cnt1][3] = Level_h;
  	 	 			
	 	 			//Get base abilities.
	 	 			for(int tsr = 4; tsr < 10; tsr ++)
	 	 			{
	 	 				CharPool[cnt1][tsr] = (high1(4,6));
	 	 			}
  	 	 			
	 	 			// Get HP based upon the Class_h value.
	 	 			// Just another line to bring attention to this area.
	 	 			if(Class_h == 1)
	 	 			{
	 	 			 	//Pesant
	 	 			 	CharPool[cnt1][10] = 0;
	 	 			 	for(int sag = 0; sag < Level_h; sag ++)
	 	 			 	{
	 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(3));
	 	 			 	}
	 	 			}
	 	 			else if (Class_h == 2)
	 	 			{
	 	 			 	//Fighter/Paladin
	 	 			 	CharPool[cnt1][10] = 0;
	 	 			 	for(int sag = 0; sag < Level_h; sag ++)
	 	 			 	{
	 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(10));
	 	 			 	}
	 	 			}
	 	 			else if(Class_h == 3)
	 	 			{
	 	 			 	//Cleric
	 	 			 	CharPool[cnt1][10] = 0;
	 	 			 	for(int sag = 0; sag < Level_h; sag ++)
	 	 			 	{
	 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(8));
	 	 			 	}
	 	 			}
	 	 			else if(Class_h == 4)
	 	 			{
	 	 			 	//Wizard/Sorcerer
	 	 			 	CharPool[cnt1][10] = 0;
	 	 			 	for(int sag = 0; sag < Level_h; sag ++)
	 	 			 	{
	 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(4));
	 	 			 	}
	 	 			}
	 	 			else if(Class_h == 5)
	 	 			{
		 	 			 	//Theif/Assasin.
		 	 			 	CharPool[cnt1][10] = 0;
		 	 			 	for(int sag = 0; sag < Level_h; sag ++)
		 	 			 	{
		 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(6));
		 	 			 	}
		 	 			}
		 	 			else if(Class_h == 6)
		 	 			{
		 	 			 	//Barbarian
		 	 			 	CharPool[cnt1][10] = 0;
		 	 			 	for(int sag = 0; sag < Level_h; sag ++)
		 	 			 	{
		 	 			 		CharPool[cnt1][10] = (CharPool[cnt1][10]+dice(12));
		 	 			 	}
		 	 			}
		 	 			else
		 	 			{
		 	 			 	cout << "Your class was inappropriately selected.  Please select it again." << endl;
		 	 			 	//Class_h = Class();
		 	 			 	goto start;
		 	 			}
  			 	 			
		 	 			// Now to get the Armor Class.
		 	 			CharPool[cnt1][11] = 10;
		 	 			rand = dice(15);
		 	 			switch(rand)
		 	 			{
		 	 				    case 1:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 1);
		 	 				    	break;
		 	 				    case 2:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 2);
		 	 				    	break;
		 	 				    case 3:
		 	 				    case 5:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 3);
		 	 				    	break;
		 	 				    case 4:
		 	 				    case 6:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 4);
		 	 				    	break;
		 	 				    case 7:
		 	 				    case 8:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 5);
		 	 				    	break;
		 	 				    case 9:
		 	 				    case 10:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 6);
		 	 				    	break;
		 	 				    case 11:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 7);
		 	 				    	break;
		 	 				    case 12:
		 	 				    	CharPool[cnt1][11] = (CharPool[cnt1][11] + 8);
		 	 				    	break;
		 	 			}
  					
  					CharPool[cnt1][12] = dice(50);
  							
  							
		 	 	}
  			 	 	
		//}		
  			
 		cout << "Do you wish to roll another NPC?" << endl;
 		cin >> cont;
  	
 		// TEST
  	//cout << "cont = " << cont << endl;
  	
  }
	// End while statement.
	
	// Print out the Characters.
 	PrintChar(CharPool);
}
 	
