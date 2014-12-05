#include <iostream>
#include <vector>
using namespace std;

unsigned long dp[5][30];

unsigned long trailzero(int p)
{
	return p%2;
}

int main()
{
	dp[1][0] = 1;
	
	for(int i=1;i<30;i++)
		dp[1][i] = dp[1][i-1]*(3+(trailzero(i-1)?-2:2))+(trailzero(i)?-2:2);
	
	for(int i=2;i<5;i++)
		for(int j=0;j<30;j++)
			dp[i][j] = dp[1][j]*(i/2+i%2+(trailzero(j)?-i/2:i/2));
	
	int T;
	unsigned long n;	
	
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		vector<int> base5;
		
		cin >> n;
		unsigned long x=n;
		while(n>0)
		{
			base5.push_back(n%5);
			n/=5;
		}
		n=x;
		
		unsigned long res=0;
		int sign = 1;
		for(int i=base5.size()-1;i>=0;i--)
		{
			if(base5[i]==0)
				continue;
			
			res += dp[base5[i]][i]*sign;
			sign = (trailzero(i)*base5[i])%2?-1:1;
		}
		cout << "Test " << t << ": " << ((res+n)/2+1) << endl;
	}
	return 0;
}

