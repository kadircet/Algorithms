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

int dp[101][101];

int main()
{
	int K,n,B,P;
	int s[101], c[101], p[101];
	cin >> K;
	for(int t=0;t<K;t++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n >> B >> P;
		for(int i=0;i<n;i++)
			cin >> s[i] >> c[i] >> p[i];
			
		for(int i=0;i<n;i++)
			for(int j=B-c[i];j>=0;j--)
				for(int k=P-p[i];k>=0;k--)
					dp[j+c[i]][k+p[i]] = max(dp[j+c[i]][k+p[i]], s[i] + dp[j][k]);
					
		int best=dp[0][0];
		for(int i=0;i<=B;i++)
			for(int j=0;j<=P;j++)
				best=max(best, dp[i][j]);
		cout << best << endl;
	}
	return 0;
}

 
