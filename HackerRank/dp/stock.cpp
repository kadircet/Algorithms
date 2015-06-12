#include <iostream>
using namespace std;

int stock[50001];
int dp[50001];

int main()
{
	int T,N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
		{
			dp[i]=i;
			cin >> stock[i];
		}
		
		for(int i=N-2;i>=0;i--)
			dp[i] = stock[i]>=stock[dp[i+1]]?i:dp[i+1];
		
		long res=0;
		for(int i=0;i<N;i++)
		{
			//cout << stock[i] << " " << stock[dp[i]] << endl;
			res += stock[dp[i]] - stock[i];
		}
		cout << res << endl;
	}
	
	return 0;
}

