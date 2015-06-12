#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

long dp[10000];
string inp[10000];
int N,K;

int main()
{
	cin >> N >> K;
	scanf("%c", dp);
	dp[0] = 0;
	for(int i=0;i<N;i++)
		getline(cin, inp[i]);
	
	for(int i=0;i<N;i++)
	{
		if(i!=0)
			dp[i] = dp[i-1];
		/*if(i>=K)
			dp[i]-=dp[i-K];*/
		for(int j=0;j<inp[i].size()-1;j++)
			if(inp[i][j]==':')
			{
				if(inp[i][j+1]==')')
					dp[i]++;
				else if(inp[i][j+1]=='(')
					dp[i]--;
			}
		//cout << dp[i] << endl;
	}
	
	long res=dp[K-1];
	for(int i=K;i<N;i++)
		if(dp[i]-dp[i-K]>res)
			res = dp[i]-dp[i-K];
	cout << res << endl;
	
	return 0;
}

