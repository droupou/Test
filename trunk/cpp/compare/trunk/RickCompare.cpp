
#include <stdio.h>
#include <string.h>
#include <iostream.h>

const int MAX = 23;

int HashIt(char* str)
{
    int Count = 1, total = 0;
    char tmp;

    while(Count <= strlen(str))
    {
        tmp = str[Count++];
	switch(tmp) {
	   case 'a': total =+ 1;
	             break;
	   case 'b': total =+ 2;
	             break;
	   case 'c': total =+ 3;
	             break;
	   case 'd': total =+ 4;
	             break;
	   case 'e': total =+ 5;
	             break;
	   case 'f': total =+ 6;
	             break;
	   case 'g': total =+ 7;
	             break;
	   case 'h': total =+ 8;
	             break;
	   case 'i': total =+ 9;
	             break;
	   case 'j': total =+ 10;
	             break;
	   case 'k': total =+ 11;
	             break;
	   case 'l': total =+ 12;
	             break;
	   case 'm': total =+ 13;
	             break;
	   case 'n': total =+ 14;
	             break;
	   case 'o': total =+ 15;
	             break;
	   case 'p': total =+ 16;
	             break;
	   case 'q': total =+ 17;
	             break;
	   case 'r': total =+ 18;
	             break;
	   case 's': total =+ 19;
	             break;
	   case 't': total =+ 20;
	             break;
	   case 'u': total =+ 21;
	             break;
	   case 'v': total =+ 22;
	             break;
	   case 'w': total =+ 23;
	             break;
	   case 'x': total =+ 24;
	             break;
	   case 'y': total =+ 25;
	             break;
	   case 'z': total =+ 26;
	             break;
	   case 'A': total =+ 27;
	             break;
	   case 'B': total =+ 28;
	             break;
	   case 'C': total =+ 29;
	             break;
	   case 'D': total =+ 30;
	             break;
	   case 'E': total =+ 31;
	             break;
	   case 'F': total =+ 32;
	             break;
	   case 'H': total =+ 33;
	             break;
	   case 'I': total =+ 34;
	             break;
	   case 'J': total =+ 35;
	             break;
	   case 'K': total =+ 36;
	             break;
	   case 'L': total =+ 37;
	             break;
	   case 'M': total =+ 38;
	             break;
	   case 'N': total =+ 39;
	             break;
	   case 'O': total =+ 40;
	             break;
	   case 'P': total =+ 41;
	             break;
	   case 'Q': total =+ 42;
	             break;
	   case 'R': total =+ 43;
	             break;
	   case 'S': total =+ 44;
	             break;
	   case 'T': total =+ 45;
	             break;
	   case 'U': total =+ 46;
	             break;
	   case 'V': total =+ 47;
	             break;
	   case 'W': total =+ 48;
	             break;
	   case 'X': total =+ 49;
	             break;
	   case 'Y': total =+ 50;
	             break;
	   case 'Z': total =+ 51;
	             break;
	}
    }
    // test line
    cout << total << " is the total so far." << endl;
    
    //if(total <= 1184) 
    //    return 0;
    //else
        return total % MAX;
}


int main(int argc, char* argv[] )
{
    int count, c2, hsh, HashTable[256][256];
    char temp[255];
    FILE *input, *output;

    if(argc < 2)
    {
        cout << "RickCompare.exe file1 file2" << endl;
    }
    else
    {
        cout << argc << "  --  " << endl;
	
	count = 1;
        while(count < argc)
        {
            cout << count << " is the count variable." << endl;
	    
	    if((input = fopen(argv[count], "r")) != NULL)
            {
                c2 = 0;
		while(fgets(temp, sizeof(temp), input))
                {
                   cout << c2++ << " is the c2 variable." << endl;
		   
		   hsh = HashIt(temp);
                   if((output = fopen(strcat(intostr(hsh), ".hsh"), "a")) != NULL)
                   {
                       fputs(temp, output);
		       cout << "Put " << temp << " into " << hsh << ".hsh." << endl;
                   }
                   else
                   {
                       cerr << "Error! Cannot open " << hsh << ".hsh file." << endl;
                   }
                }
            }
            else
            {
                cerr << "Error! " << argv[count] << " not found!" << endl;
            }
            count++;
        }
    }
}
