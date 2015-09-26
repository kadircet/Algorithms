#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

unsigned long long int dp[31];

int main()
{
	int n;
	cin >> n;
	dp[0]=0;
	dp[1]=6;
	dp[2]=20;
	for(int i=3;i<=n;i++)
		dp[i]=dp[i-1]*2+dp[i-2]*4+(1<<i);
	cout << dp[n] << endl;
	return 0;
}

