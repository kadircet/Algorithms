#include <iostream>
#include <iomanip>
using namespace std;

long long count[1<<20];
int n, tG[21];
string inp[50];

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> inp[i];
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int mask=0;
			for(int k=0;k<inp[i].size();k++)
				if(inp[i][k] == inp[j][k])
					mask |= 1<<k;
			count[mask] |= 1LL<<i | 1LL<<j;
		}
		
	for(int mask=(1<<inp[0].size())-1;mask;mask--)
		for(int i=0;i<inp[0].size();i++)
			if(mask&(1<<i))
				count[mask ^ (1<<i)] |= count[mask];
				
	long double ans=0;
	for(int mask=0;mask<(1<<inp[0].size());mask++)
	{
		int moves = __builtin_popcount(mask) + 1;
		for(int i=0;i<inp[0].size();i++)
			tG[moves]+=__builtin_popcount(count[mask] ^ count[mask | (1<<i)]);
	}
	
	for(int i=1;i<=inp[0].size();i++)
	{
		long double val = tG[i] * i;
		for(int j=0;j<i-1;j++)
			val *= (long double)(i-1-j)/(long double)(inp[0].size()-j);
		ans += val/(inp[0].size()-i+1);
	}
	ans /= 1.0*n;
	
	cout << fixed << setprecision(15) << ans << endl;
	
	return 0;
}

