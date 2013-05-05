#include <stdlib.h>
#include <iostream.h>

using namespace std;


int cString(char* str[], int cnt, int line, int pos){
	cout << line << "-" << pos << ") ";
	for (int z=3; z < cnt; z++){
		cout << str[z];
		if (z < cnt){
			cout << ' ';
		}
	}

	return 1;
}

int main(int argc, char* argv[] ) {
	int cnt=0;
	
	if (argc < 3){ 
		cout << "use hello <number of times to display> <per line> <String to display>" << '\n';
	}
	else{
		cnt=atoi(argv[1]);
		for (int n=0; n < cnt; n++){
			for (int n2=0;n2<cnt2; n2++){
				cString(argv, argc, n+1,0+1);
				cout << '\n';
			}
		}
	}
}
