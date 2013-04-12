/***************************************************************************
                          Dice.h  -  description
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
	This is the Dice portion of Dungeons and Dragons 3
*/

#include <stdlib.h>
#include <time.h>

int dice(int num)
{
	int temp;
	
	temp = random();
	temp = ((temp%num)+1);
	
	return temp;
}

// Get the highest number of num dice and add them together.
int high1(int num, int side)
{
 	int ret = 0, hobl1, hobl;
 	
 	//TEST
 	//cout << "num = " << num << "  side = " << side << endl;
 	
 	if((num < 100) && (side < 101))
 	{
 		int temp[99], cnt;
 		ret = 0;
 		for(hobl = 0; hobl < num; hobl ++)
 		{
 		 		temp[hobl] = dice(side);
 		 		//TEST
 		 		//cout << "temp[hobl] = " << temp[hobl] << endl;	
 		}
 		
 		//This one may cause some problems.
 		for(hobl = 0; hobl < num; hobl ++)
 		{
 		 		// TEST
 		 		//cout << "New hobl." << endl << endl << endl << endl;
 		 		
 		 		for(hobl1 = (hobl+1); ((hobl1 < num)); hobl1++)
 		 		{
 		 				// TEST
 		 				//cout << "Is " << temp[hobl1] << " < " << temp[hobl] << "?" << endl;
 		 				if(temp[hobl1] < temp[hobl])
 		 				{
 		 					// TEST
 		 					//cout << "Yes it is." << endl;
 		 					hobl1 = 100;
 		 				}
 		 				//end of if loop.
 		 				else
 		 				{
 		 					// TEST
 		 					//cout << "No it isn't." << endl;
 		 				}
 		 				// end of else
 		 				
 		 		}
 		 		// End of For loop.
 		 		
 		 		if(hobl1 == num)
 		 		{
 		 		 	// TEST
 		 		 	//cout << " setting " << temp[hobl] << " to zero." << endl;
 		 		 	//cout << "On temp[" << hobl << "]" << endl;
 		 		 	temp[hobl] = 0;
 		 		 	hobl = 100;
 		 		}
 		}
 		// now we need to sum up the numbers that are left.
		ret = 0;
		cnt = 0; 		
		while(cnt < num)
		{
		 	// TEST
		 	//cout << "ret = " << ret << endl;
		 	ret = (ret+temp[cnt]);
		 	cnt ++;
		 	// TEST
		 	//cout << "ret = " << ret << endl;
		}
	}
	else
	{
	 	cout << "Error, please lower the level of your character so that it's HD is less than 100" << endl;
	 	cout << "and also be sure the HD number is 100 or less." << endl;
	 	ret = 0;
	 	
	}
	// TEST
	//cout << "preparing to return " << ret << endl;
	return ret;
}	
