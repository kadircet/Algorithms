#include <iostream>
#define MOD 1000000007
using namespace std;

unsigned long long int comb[10001][1001];
unsigned long long int c[101], s[101], fil[101];
unsigned long long int d[101];
unsigned long long int N, S, K, T, cnt;
unsigned long long int dp[102][10100];
int curperm[101];

void printperm()
{
	for(int i=0;i<N;i++)
		cout << curperm[i] << ' ';
	//cout << endl;
}

void gen(int cur, int sum)
{
	if(cur>0 && sum>s[cur-1])
		return;
	if(cur==N)
	{
		if(sum!=s[N-1])
			return;
		//printperm();
		T=s[0];
		unsigned long long int res=comb[T][curperm[0]];
		T+=fil[1]-curperm[0];
		for(int i=1;i<N;i++)
		{
			res=(res*comb[T][curperm[i]])%MOD;
			T+=fil[i+1]-curperm[i];
		}
		//cout << res << endl;
		cnt=(cnt+res)%MOD;
		return;
	}
	for(int i=0;i<=d[cur];i++)
	{
		curperm[cur]=i;
		gen(cur+1, sum+i);
	}
}

int main()
{
	comb[0][0]=1;
	comb[1][0]=1;
	comb[1][1]=1;
	for(int i=2;i<=10000;i++)
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
	for(int i=0;i<N;i++)
	{
		d[i] = min(c[i], s[i]);
		K+=d[i];
	}
	K=K-S;
	T=S;
	unsigned long long int res=comb[T][s[0]];
	T-=s[0];
	for(int i=1;i<N;i++)
	{
		res=(res*comb[T][s[i]-s[i-1]])%MOD;
		T-=s[i]-s[i-1];
	}
	gen(0, 0);
	res=(res*cnt)%MOD;
	cout << res << endl;
	return 0;
}

