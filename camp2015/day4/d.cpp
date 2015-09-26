#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
using namespace std;

int nways[101];

void print3(int n)
{
	cout << n+2 << ' ' << n+1 << ' ' << n << ' ';
}

void print4(int n)
{
	cout << n+2 << ' ' << n+3 << ' ' << n << ' ' << n+1 << ' ';
}

int main()
{
	int n;
	cin >> n;
	nways[3]=1;
	nways[4]=1;
	for(int i=5;i<=n;i++)
		nways[i] = nways[i-3]+nways[i-4];
	
	int i=1;
	cout << nways[n] << endl;
	if(nways[n]!=0)
	{
		while(n%4!=0)
		{
			print3(i);
			n-=3;
			i+=3;
		}
		while(n>0)
		{
			print4(i);
			n-=4;
			i+=4;
		}
	}
	cout << endl;
	return 0;
}

