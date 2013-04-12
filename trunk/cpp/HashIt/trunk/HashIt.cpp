
#include <stdio.h>
#include <string.h>
#include <iostream.h>

const int MAX = 189;

/************************************************
 * Concept:  Break the data up more evenly so	*
 *    that each instance of a hash will have	*
 *    fewer data members to search through.  	*
 *						*
 * Example:  Old hash would total 54.  New hash *
 *    will seperate it into (32, 22) or (31, 23)*
 *    or (22,32).  Each instance will have its  *
 *    own file with fewer "sister" results.  	*
 *    The file resulting in (x, y) would be	*
 *    saved as ./Hash/x/y.txt.			*
 *						*
 * Proof:  In theory the time to break the 	*
 *    numbers down should take the same amount 	*
 *    of time.  The creation of directories and *
 *    files needs to be factored in, however as *
 *    each file will have less items in it 	*
 *    saving the time to go through each file.  *
 ************************************************
int* HashIt2(char* str)
{
    char* Hsh1, Hsh2;
    int* answer;
    
    Hsh1 = Left(str, .5*strlen(str));
    Hsh2 = Right(str, strlen(str) - .5 * strlen(str));
    
    answer[1] = HashIt(Hsh1);
    answer[2] = HashIt(Hsh2);
    
    return answer;
}
/*  */

int HashIt(char* str)
{
    int Count = 1, total = 0;

    while(Count <= strlen(str))
        total =+ str[Count++];

    if(total <= 1184) 
        return 0;
    else
        return total % MAX;
}

int main(int argc, char* argv[] )
{
    int count = 1, final = 0;
    
    if(argc <= 1)
    {
        cout << "Format HashIt <string variables>" << endl;
	return 0;
    }

    while(count <= argc)
        final =+ HashIt(argv[count++]);

    cout << "Final value is: " << final << endl;
    return 0;
}

