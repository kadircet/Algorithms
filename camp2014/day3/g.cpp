#include <iostream>
#include <set>
#define INF 1000010
using namespace std;

int dp[1000010];
int N,M,K;
int unr[1010];
multiset<int> steps;
multiset<int>::iterator it;

int main()
{
	cin >> N >> M >> K;
	for(int i=0;i<K;i++)
	{
		cin >> unr[i];
		dp[unr[i]] = INF;
	}
	
	if(dp[N]==INF)
	{
		cout << "Dark side is calling you, young padawan..." << endl;
		return 0;
	}
	
	long best=0,pos=1;
	dp[1] = 0;
	steps.insert(0);
	for(int i=2;i<=N;i++)
	{
		//cout << i << ' ' << best << endl;
		if(dp[i]==0)
		{
			dp[i] = best+1;
			steps.insert(dp[i]);
		}
		if(i>M && dp[i-M]!=INF)
		{
			steps.erase(steps.find(dp[i-M]));
			if(steps.size()==0)
			{
				cout << "Dark side is calling you, young padawan..." << endl;
				return 0;
			}
			best = *steps.begin();
		}
	}
	cout << dp[N] << endl;
	return 0;
}
