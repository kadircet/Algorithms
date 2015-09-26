#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

unsigned long long dp[14][13*9+1][2];

int ds(string n)
{
	int res=0;
	for(int i=0;i<n.size();i++)
		res+=n[i]-'0';
	return res;
}

void calc(string n)
{
	while(n.size()<13)
		n = '0'+n;
	
	int ni,nj,nk;
	dp[0][0][1]=1;
	for(int i=0;i<13;i++)
	{
		for(int d=0;d<10;d++)
		{
			for(int j=0;j<13*9+1-d;j++)
			{
				for(int k=0;k<2;k++)
				{
					ni=i+1;
					nj=j+d;
					nk=k&&d==(n[i]-'0');
					if(k && d>n[i]-'0')
						continue;
					dp[ni][nj][nk]+=dp[i][j][k];
				}
			}
		}
	}
}

int main()
{
	unsigned long long int res=0;
	string n,k;
	cin >> n >> k;
	
	calc(n);
	for(int i=1;i<ds(k);i++)
		res+=dp[13][i][0]+dp[13][i][1];
	memset(dp, 0, sizeof(dp));
	calc(k);
	res+=dp[13][ds(k)][0]+1;
	cout << res << endl;
	
	return 0;
}

