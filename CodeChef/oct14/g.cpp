#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int T,a,b,k,q;
string s,w;
int S,W,N;
int dp[102][102];

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> s >> w;
		cin >> a >> b >> k;
		if(k==0)
		{
			if(s==w || a==0 || (b==0 && s.size()==w.size()))
				cout << 0 << endl;
			else
				cout << -1 << endl;
			continue;
		}
		if(a==0)
		{
			cout << 0 << endl;
			continue;
		}
		
		q=k/a;
		S = max((int)s.size(), q);
		W = max((int)w.size(), q);
		N = max(S, W);
		dp[0][0] = 0;
		for(int i=0;i<=q;i++)
			dp[0][i]=dp[i][0]=i*a;
		
		for(int i=1;i<=q;i++)
			for(int j=1;j<=q;j++)
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1])+a, dp[i-1][j-1]+(s[i-1]!=w[j-1]?b:0));
		
		for(int j=0;j<N-q;j++)
		{
			for(int i=0;i<q;i++)
			{
				dp[i][q] = min(min(dp[i][q]+(s[i+j]!=w[q+j]?b:0), dp[i+1][q]+a), i>0?dp[i-1][q]+a:1000000);
				dp[q][i] = min(min(dp[q][i]+(s[q+j]!=w[i+j]?b:0), dp[q][i+1]+a), i>0?dp[q][i-1]+a:1000000);
			}
			dp[q][q] = min(min(dp[q][q]+(s[q+j]!=w[q+j]?b:0), dp[q][q-1]+a), dp[q-1][q]+a);
		}
		
		/*for(int i=0;i<=q;i++, cout << endl)
			for(int j=0;j<=q;j++)
				cout << dp[i][j] << ' ';
		cout << "------------------" << endl;*/
		a=min((int)s.size()+max((int)w.size()-q,0), q);
		b=min(q, (int)w.size());
		if(dp[a][b]<=k)
			cout << dp[a][b] << endl;
		else
			cout << -1 << endl;
	}
	
	return 0;
}

