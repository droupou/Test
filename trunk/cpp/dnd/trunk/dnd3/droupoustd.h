/***************************************************************************
                          droupoustd.h  -  description
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

/***************************************************************************
 *	This is my own Standard Library.																			 *
 *	                                                                       *
 *	you can:                                                               *
 *	                                                                       *
 *	pause the screen using pause_sc().                                     *
 *	clear the screen useing clear_sc().                                    *
 ***************************************************************************/


#include <unistd.h>
#include <fcntl.h>

void pause_sc()
{
	char null_string1[50];
	cin.getline(null_string1, sizeof(null_string1), '\n');
	return;
}

void clear_sc()
{
		cout << "\033[2J\033[100A" << endl;	// This clears the screen and starts at the top.
		return;
}
