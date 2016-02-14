#include <iostream>
#define MOD 1000000007
using namespace std;

unsigned long long int comb[10001][1001];
unsigned long long int c[101], s[101], fil[101];
unsigned long long int d[101];
unsigned long long int N, S, K, T;
unsigned long long int dp[102][10100];

int main()
{
	comb[0][0]=1;
	for(int i=1;i<=10000;i++)
		for(int j=0;j<=1000;j++)
			if(j==0 || j==i)
				comb[i][j]=1;
			else
				comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
	cin >> N;
	cin >> s[0];
	fil[0]=s[0];
	for(int i=1;i<N;i++)
	{
		cin >> fil[i];
		s[i]=s[i-1]+fil[i];
	}
	S=s[N-1];
	for(int i=0;i<N;i++)
		cin >> c[i];
	T=S;
	unsigned long long int res=comb[T][s[0]];
	T-=s[0];
	for(int i=1;i<N;i++)
	{
		res=(res*comb[T][s[i]-s[i-1]])%MOD;
		T-=s[i]-s[i-1];
	}
	dp[0][0]=1;
	for(int i=1;i<=N;i++)
		for(int j=0;j<=s[i-1];j++)
		{
			dp[i][j]=0;
			for(int k=-100;k<=100;k++)
				if(j+k>=0 && k+fil[i-1]>=0 && k+fil[i-1]<=c[i-1])
					dp[i][j]=(dp[i][j]+(dp[i-1][j+k]*comb[j+k+fil[i-1]][k+fil[i-1]])%MOD)%MOD;
			//cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	res=(res*dp[N][0])%MOD;
	cout << res << endl;
	return 0;
}

