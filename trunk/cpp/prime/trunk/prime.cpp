#include <iostream.h>

struct prime
{
	int p;
	prime *next;
	prime *prev;
};


int check(int n)
{
	int k, limit;
	
	if (n == 2)
		return 1;
	if (n%2 == 0)
		return 0;
	limit = n / 2;
	for(k = 3; k <= limit; k += 2)
		if (n%k ==0)
			return 0;
	return 1;
}

int main()
{
	int max, temp, ret;
	prime list;
	
	temp = 2;
	ret = 2;
	
	cout << "Please enter the maximum you want this prog to calculate." << endl;
	cout << "#";
	cin >> max;
	
	while(temp <= max)
	{
		if(check(temp))
		{
			ret = temp;
		}
		
		temp++;
	}
	
	cout << "The last prime number was:  " << ret << endl;
	return 0;
}
