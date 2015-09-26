#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n,m,k,tour=0,i,j,dir=0;
	cin >> n >> m >> k;
	int circ=2*n+2*m-4;
	if(n==m && n==1)
	{
		cout << "1 1" << endl;
		return 0;
	}
	while(k>circ && circ > 0)
	{
		k-=circ;
		tour++;
		n-=2;
		m-=2;
		circ=2*n+2*m-4;
	}
	i=j=1;
	while(k>1)
	{
		if(dir==0)
		{
			if(i==m)
			{
				dir=1;
				continue;
			}
			i++;
		}
		else if(dir==1)
		{
			if(j==n)
			{
				dir=2;
				continue;
			}
			j++;
		}
		else if(dir==2)
		{
			if(i==1)
			{
				dir=3;
				continue;
			}
			i--;
		}
		else if(dir==3)
		{
			if(j==1)
				break;
			j--;
		}
		k--;
	}
	cout << (j+tour) << ' ' << (i+tour) << endl;
	return 0;
}
