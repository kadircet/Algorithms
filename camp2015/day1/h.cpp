#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int w[1000001];

int main()
{
	int N,t,sum=0;
	cin >> N >> t;
	for(int i=0;i<t;i++)
		cin >> w[i];
	for(int i=0;i<t;i++)
	{
		sum+=w[i];
		if(i>3)
			sum-=w[i-4];
		if(sum>N)
		{
			if(i==0)
				cout << 0 << endl;
			else
				cout << i-1 << endl;
			return 0;
		}
	}
	if(sum<=N)
		cout << (t-1) << endl;
	else
		cout << 0 << endl;
	return 0;
}
 
