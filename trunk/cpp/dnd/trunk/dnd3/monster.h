/***************************************************************************
                          monster.h  -  description
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

// Variables.
char list[255][255], filename[255], on = 'y', temp[255], cont = 'y';
FILE *fo, *fo2;
int count = 0, mon, c2 = 0, recount = 0, fcloseall(void);
char tempv[255];
char holdme[25][255];
char flist[255][255];
int q, sel;
int bill, schoice;
int holdnum[3] = {0, 0 , 0};
int X;
int side;
int modif;
int HD = 0;
int r = 0, fcloseall(void);
int x, numomon, n;


int STR2INT(char str)
{
	int in;
	
	switch(str){
		case '0': in = 0;
			break;
		case '1': in = 1;
			break;
		case '2': in = 2;
			break;
		case '3': in = 3;
			break;
		case '4': in = 4;
			break;
		case '5': in = 5;
			break;
		case '6': in = 6;
			break;
		case '7': in = 7;
			break;
		case '8': in = 8;
			break;
		case '9': in = 9;
			break;
		default: in = 0;
	}
	return in;
}

void GListS(int low, int high)
{
	
	int c , c1, test, c2 = 0, tint;
	
	//TEST
	//cout << "low = " << low << " and high = " << high << endl;
	
	//Read all the data presented.
	// Open the list file.
	if((fo = fopen("flist.dir", "r")) != NULL)
	{
		// read in each line individually.
		count = 0;
		while(fgets(temp, sizeof(temp), fo))
		{
			c2 = 0;
			
			list[count] = temp;
			count ++;
		}
		list[(count+1)][0] = '$';
		list[(count+1)][1] = '$';
		list[(count+1)][2] = '$';
		list[(count+1)][3] = '$';
		list[(count+1)][4] = '$';
		list[(count+1)][5] = '$';
		list[(count+1)][6] = '$';
		list[(count+1)][7] = '$';
		
	}
	else
	{
		cout << "ERROR opeining list.dir." << endl << endl;
	}
	fclose(fo);
	
	//Seperate data into a seperate field.
	c = 0;
	while((list[c]) && (c < 255))
	{
		//TEST
		//cout << "filename is: " << list[c] << " -->  ";
		//pause_sc();
		//pause_sc();
		
		// find .mon
		c1 = 0;
		test = 0;
		while((test != 3) && (c1 < 255))
		{
			switch(list[c][c1]){
				case 'm' :
					test = 1;
					break;
				case 'o' :
					if(test == 1)
					{
						test = 2;
					}
					else
					{
						test = 0;
					}
					break;
				case 'n' :
					if(test == 2)
					{
						test = 3;
						
						//TEST
						//cout << "TEST" << endl;
					}
					else
					{
						test = 0;
					}
					break;
				default :
					test = 0;
					break;
			}
				
			//TEST
			//cout << "TEST 2" << endl;
				
			// When test = 3.
			if(test == 3)
			{
				c1 = (c1 + 2);
				
				tint = list[c][c1];
				tint = (tint - 48);
				
				//TEST
				//cout << low << " " << list[c][c1] << " " << high << endl;
				//cout << low << " " << tint << " " << high << endl;
				
				if(((low <= tint) && (tint <= high)) || (list[c][c1] == '*'))
				{
					flist[c2] = list[c];
					//TEST
					//cout << "list[" << c << "] = " << list[c] << endl;
					//pause_sc();
					//pause_sc();
					//cout << "flist[" << c2 << "] = " << flist[c2] << endl;
					
					c2 ++;
					
				}
				//cout << list[c][c1] << endl;
				
			}
			
			// incriment
			c1 ++;
		}
		c++;
	}
	flist[c2][0] = '$';
	flist[c2][1] = '$';
	flist[c2][2] = '$';
	flist[c2][3] = '$';
	flist[c2][4] = '$';
	flist[c2][5] = '$';
	//TEST
	//cout << "HEY! " << flist[c2] << endl;
	
	// Print out the list of monsters available.
	recount = 0;
	
	//TEST
	//cout << "flist[0] is: " << flist[0] << endl;
	
	clear_sc();
	clear_sc();
	int j = 0;
	on = 'y';
	cout << "Monsters you have selected to roll.";
		
	cout << endl << "0.\t" << "Exit";
	//cout << endl << (j+1) <<  ".\t";
	while(on == 'y')
	{
		//TEST
		//cout << "flist[" << j << "][1] = " << flist[j+1][1] << endl;
		
		if(flist[j][0] != '$')
		{
			cout << endl << (j+1) <<  ".\t";
			
			//TEST
			//cout << "in first if statement." << endl;
		}
		
		for(int c = 0;((flist[j][c] != '.') && (c < 255)); c++)
		{
			//TEST
			//cout << "In for statement." << endl;
			
			if((flist[j][c] != '$') && (on == 'y'))
			{
				//TEST
				//cout << "in 2nd if statement." << endl;
				
				cout << flist[j][c];
			}
			else
			{
				//TEST
				//cout << "In else statement." << endl;
				
				on = 'n';
			}
		}
		//TEST
		//cout << "\tj = " << j;
		j++;
	}
	cout << endl << "#";

// END of void GListS(int low, int high)
}

void GListA()
{
	// Open the list file.
	if((fo = fopen("list.dir", "r")) != NULL)
	{
		// read in each line individually.
		count = 0;
		while(fgets(temp, sizeof(temp), fo))
		{
			c2 = 0;
			
			list[count] = temp;
			count ++;
		}
		list[(count)][0] = '$';
		list[(count)][1] = '$';
		list[(count)][2] = '$';
		list[(count)][3] = '$';
		list[(count)][4] = '$';
		list[(count)][5] = '$';
		list[(count)][6] = '$';
		list[(count)][7] = '$';
		
	}
	else
	{
		cout << "ERROR opeining list.dir." << endl << endl;
	}
	fclose(fo);
	//TEST
	//cout << "HELP" << endl;
	
	// Print out the list of monsters available.
	recount = 0;
	
	//TEST
	//cout << "flist[0] is: " << flist[0] << endl;
	
	clear_sc();
	clear_sc();
	int j = 0;
	on = 'y';
	cout << "Monsters you have selected to roll.";
		
	cout << endl << "0.\t" << "Exit";
	//cout << endl << (j+1) <<  ".\t";
	while(on == 'y')
	{
		//TEST
		//cout << "flist[" << j << "][1] = " << flist[j+1][1] << endl;
		
		if(list[j][0] != '$')
		{
			cout << endl << (j+1) <<  ".\t";
			
			//TEST
			//cout << "in first if statement." << endl;
		}
		
		for(int c = 0;((list[j][c] != '.') && (c < 255)); c++)
		{
			//TEST
			//cout << "In for statement." << endl;
			
			if((list[j][c] != '$') && (on == 'y'))
			{
				//TEST
				//cout << "in 2nd if statement." << endl;
				
				cout << list[j][c];
			}
			else
			{
				//TEST
				//cout << "In else statement." << endl;
				
				on = 'n';
			}
		}
		//TEST
		//cout << "\tj = " << j;
		j++;
	}
	cout << endl << "#";

}

void SListS()
{
	// Selection of the monster.
	mon = schoice;
	if(mon == 0)		// if mon is equal to 0.
	{
		cout << "Exiting Monster generation." << endl;
		cont = 'n';
	}
	else
	{
		// transfer the file name.
		int t = 0;
		while(flist[(mon - 1)][t] != '.')
		{
			filename[t] = flist[(mon - 1)][t];
			t++;
		}
		cout << "filename - 1 - + " << filename << endl;
		for(int v = 0; v < 3; v++)
		{
			filename[t] = flist[(mon - 1)][t];
			t++;
		}
		//TEST
		//cout << "filename = " << filename << "." << endl;
		
		filename[t] = flist[(mon - 1)][t];
		t++;
		
		while(filename[t])
		{
			filename[t] = 0;
			t++;
		}
		
		//TEST
		//cout << "filename = " << filename << "." << endl;
		// Open the actual file.
		if((fo2 = fopen(filename, "r")) != NULL)
		{
			clear_sc();
			// open the monsters file.
			// Begin by printing out the name of the beast.
			bill = 0;
			while(filename[bill] != '.')
			{
				cout << filename[bill];
				bill ++;
			}
			cout << endl;
			
			// Gather pertinant information.
			q = 0;
			while(fgets(tempv, sizeof(tempv), fo2))
			{
				holdme[q] = tempv;
				q++;
			}
			for(int z = 0; z <= q ; z++)
			{
				cout << holdme[z];
			}
			
			// Divide pertinant information.
			// remove label.
			HD = 0;
			r = 0;
			while(holdme[1][r] != ':')
			{
				r++;
			}
			r++;
			x = 0;
			
			while(holdme[1][r] == ' ')
			{
				r++;
			}
			
			//  Get the number of times to roll the die.
			X = 0;
			while(holdme[1][r] != 'd')
			{
				X = (X*10);
				X = (X + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << X << endl;
			
			side = 0;
			// How many sides to the die.
			while(holdme[1][r] != '+')
			{
				side = (side*10);
				side = (side + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << side << endl;
			
			modif = 0;
			// How much to add on to total.
			while((holdme[1][r] != ' ') && (holdme[1][r]) && (holdme[1][r] != '\n'))
			{
				modif = (modif*10);
				modif = (modif + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << modif << endl;
			
			// How many?
			cout << endl << endl << "How many ";
			
			// Print out the name of the beast.
			bill = 0;
			while(filename[bill] != '.')
			{
				cout << filename[bill];
				bill ++;
			}
			cout << "s would you like?" << endl;
			cout << "#";
			cin >> numomon;
			cout << endl << endl;
			
			n = 1;
			for(int v = 0; v < numomon; v++, n++)
			{
				HP = 0;
				
				//TEST
				//cout << endl << "HP = " << HP << endl;
				//cout << "side = " << side << endl;
				//cout << "X = " << X << endl;
				//cout << "modif = " << modif << endl;
				
				for(int k = 0; k < X; k++)
				{
					HP = (HP + dice(side));
					//TEST
					//cout << "\t HP = " << HP << endl;
				}
				HP = (HP + modif);
				cout << HP << "\t";
				
				if(n == 15)
				{
					n = 0;
					cout << endl << endl << endl << endl;
				}
				
			}
			cout << endl;
			
			
			// close the file only if it opens.
			fclose(fo2);
			
			// Clean out filename before moving on
			
		}
		// in case of emergency.
		else
		{
			cout << "Error! Exiting Monster generation." << endl;
			cont = 'n';
			fclose(fo2);
		}
		pause_sc();
		pause_sc();
	}
// End of void SListS()
}
void SList()
{
	//TEST
	//cout << "HELP" << endl;
	
	// Selection of the monster.
	if(mon == 0)		// if mon is equal to 0.
	{
		cout << "Exiting Monster generation." << endl;
		cont = 'n';
	}
	else
	{
		// transfer the file name.
		int t = 0;
		while(list[(mon - 1)][t] != '.')
		{
			filename[t] = list[(mon - 1)][t];
			t++;
		}
		cout << "filename - 1 - + " << filename << endl;
		for(int v = 0; v < 3; v++)
		{
			filename[t] = list[(mon - 1)][t];
			t++;
		}
		//TEST
		//cout << "filename = " << filename << "." << endl;
		
		filename[t] = list[(mon - 1)][t];
		t++;
		
		while(filename[t])
		{
			filename[t] = 0;
			t++;
		}
		
		//TEST
		//cout << "filename = " << filename << "." << endl;
		// Open the actual file.
		if((fo2 = fopen(filename, "r")) != NULL)
		{
			clear_sc();
			// open the monsters file.
			// Begin by printing out the name of the beast.
			bill = 0;
			while(filename[bill] != '.')
			{
				cout << filename[bill];
				bill ++;
			}
			cout << endl;
			
			// Gather pertinant information.
			q = 0;
			while(fgets(tempv, sizeof(tempv), fo2))
			{
				holdme[q] = tempv;
				q++;
			}
			for(int z = 0; z <= q ; z++)
			{
				cout << holdme[z];
			}
			
			// Divide pertinant information.
			// remove label.
			HD = 0;
			r = 0;
			while(holdme[1][r] != ':')
			{
				r++;
			}
			r++;
			x = 0;
			
			while(holdme[1][r] == ' ')
			{
				r++;
			}
			
			//  Get the number of times to roll the die.
			X = 0;
			while(holdme[1][r] != 'd')
			{
				X = (X*10);
				X = (X + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << X << endl;
			
			side = 0;
			// How many sides to the die.
			while(holdme[1][r] != '+')
			{
				side = (side*10);
				side = (side + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << side << endl;
			
			modif = 0;
			// How much to add on to total.
			while((holdme[1][r] != ' ') && (holdme[1][r]) && (holdme[1][r] != '\n'))
			{
				modif = (modif*10);
				modif = (modif + (STR2INT(holdme[1][r])));
				r++;
				
			}
			//cout << modif << endl;
			
			// How many?
			cout << endl << endl << "How many ";
			
			// Print out the name of the beast.
			bill = 0;
			while(filename[bill] != '.')
			{
				cout << filename[bill];
				bill ++;
			}
			cout << "s would you like?" << endl;
			cout << "#";
			cin >> numomon;
			cout << endl << endl;
			
			n = 1;
			for(int v = 0; v < numomon; v++, n++)
			{
				HP = 0;
				
				//TEST
				//cout << endl << "HP = " << HP << endl;
				//cout << "side = " << side << endl;
				//cout << "X = " << X << endl;
				//cout << "modif = " << modif << endl;
				
				for(int k = 0; k < X; k++)
				{
					HP = (HP + dice(side));
					//TEST
					//cout << "\t HP = " << HP << endl;
				}
				HP = (HP + modif);
				cout << HP << "\t";
				
				if(n == 15)
				{
					n = 0;
					cout << endl << endl << endl << endl;
				}
				
			}
			cout << endl;
			
			
			// close the file only if it opens.
			fclose(fo2);
			
			// Clean out filename before moving on
			
		}
		// in case of emergency.
		else
		{
			cout << "Error! Exiting Monster generation." << endl;
			cont = 'n';
			fclose(fo2);
		}
		pause_sc();
		pause_sc();
	}
}

void CR()
{
	int low = 0, high = 100;
	
	clear_sc();
	clear_sc();
	
	cout << "What CR rating monsters would you like to see?" << endl;
	cout << "Lowest #";
	cin >> low;
	cout << endl << "Highest #";
	cin >> high;
	
	GListS(low, high);
	cin >> schoice;
	SListS();
}

void Monster()
{
	// declarations
	cont = 'y';
	while(cont == 'y')
	{
		// Start with a clear screen.
		clear_sc();
	
		
		//Choose how you want to view monsters.
		cout << "How would you like to select monsters?" << endl;
		cout << "0. Exit." << endl;
		cout << "1. All monsters." << endl;
		cout << "2. By Encounter Rating." << endl;
		cout << "#";
		cin >> sel;
		
		if(sel == 0)
		{
			cont = 'n';
		}
		else if(sel == 1)
		{
			GListA();
			//TEST
			//cout << "HELP" << endl;
			//cout << mon << endl;
			
			cin >> mon;
			
			//TEST
			cout << "HELP" << endl;
			SList();
		}
		
		else if(sel == 2)
		{
			CR();
		}	
	}
}
