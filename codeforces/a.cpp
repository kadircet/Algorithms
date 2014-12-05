#include <iostream>
using namespace std;

int l[10];

int main()
{
	int t,c=0,leg;
	for(int i=0;i<6;i++)
	{
		cin >> t;
		if(l[t]==0)
			c++;
		l[t]++;
	}
	
	bool legs=false;
	for(int i=0;i<10;i++)
		if(l[i]>=4)
		{
			legs=true;
			leg=i;
			break;
		}
	
	if(c>3 || !legs)
		cout << "Alien" << endl;
	else
	{
		for(int i=0;i<10;i++)
			if(i==leg)
				continue;
			else if(l[i]>=2)
			{
				cout << "Elephant" << endl;
				return 0;
			}
		
		if(l[leg]==6)
			cout << "Elephant" << endl;
		else
			cout << "Bear" << endl;
	}
	
	return 0;
}

