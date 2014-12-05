#include <iostream>
#include <map>
#define MOD 1000000007LL
using namespace std;

long long dp[1024][1024];
long long C[1024];
map<int, int> rank;
long long powt[100001];

long long powm(int b, int e)
{
	if(powt[b]!=0)
		return powt[b];
		
	if(e==0)
		return 1;
	if(e==1)
		return b%MOD;
	
	long long res=powm(b, e/2);
	return powt[b]=(res*res)%MOD*(e%2?b:1)%MOD;
}

bool islucky(int n)
{
	while(n>0)
	{
		if(n%10!=4 && n%10!=7)
			return false;
		n/=10;
	}
	
	return true;
}

long long combt[100001];
long long comb(long long n, long long r)
{
	if(r==0)
		return 1;
	if(r>n-r)
		return combt[r]=comb(n, n-r);
	if(combt[r])
		return combt[r];
	if(r>0 && combt[r-1])
		return combt[r]=(combt[r-1]*(n-r+1))%MOD*(powm(r, MOD-2))%MOD;
	
	long long res=1;
	for(int i=0;i<r;i++)
		res = ((res*(n-i))%MOD*(powm(r-i, MOD-2)))%MOD;
	return combt[r]=res;
}

int main()
{
	int n,k,t;
	cin >> n >> k;
	
	int c=0,tot=0;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(islucky(t))
		{
			if(rank.find(t)==rank.end())
				rank[t]=c++;
			
			C[rank[t]]++;
			tot++;
		}
	}
	
	dp[0][0] = 1;
	for(int i=1;i<=c;i++)
		for(int j=0;j<=i;j++)
			dp[i][j] = (dp[i-1][j] + (j>0?(dp[i-1][j-1]*C[i-1])%MOD:0))%MOD;
	
	C[0] = 1;
	for(int i=1;i<=c;i++)
		C[i]=dp[c][i];
	
	long long res=0;
	t = n-tot;
	n = 1;
	for(int i=min(c, k);i>=0;i--)
	{
		if(k-i>t)
			break;
		
		n = comb(t, k-i);
		//cout << t << ' ' << k-i << ' ' << n << endl;
		res = (res + C[i]*n)%MOD;
	}
	cout << res << endl;
	return 0;
}
