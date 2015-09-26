#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#define MOD 1000000000
using namespace std;

struct bigint
{
	unsigned long long int a[20];
};

void add(bigint &a, unsigned long long int b)
{
	int i=1;
	a.a[0]+=b;
	unsigned long long int h=a.a[0]/MOD;
	a.a[0]%=MOD;
	while(h>0)
	{
		a.a[i]+=h;
		h=a.a[i]/MOD;
		a.a[i++]%=MOD;
	}
}

void add(bigint &a, bigint b)
{
	int i=0;
	unsigned long long int h=0;
	while(i<20)
	{
		a.a[i]+=b.a[i]+h;
		h=a.a[i]/MOD;
		a.a[i++]%=MOD;
	}
}

bigint mult(bigint a, unsigned long long int b)
{
	int i=1;
	unsigned long long int h=0;
	a.a[0]*=b;
	h=a.a[0]/MOD;
	a.a[0]%=MOD;
	while(i<20)
	{
		a.a[i]=a.a[i]*b+h;
		h=a.a[i]/MOD;
		a.a[i++]%=MOD;
	}
	
	return a;
}

void print(bigint a)
{
	for(int i=19;i>=0;i--)
		cout << a.a[i];
	cout << endl;
}

bigint dp[51][51];
unsigned long long int transc[51][51];

int main()
{
	int k,n,r;
	int s,f;
	string l;
	cin >> k >> n >> r;
	for(int i=0;i<r;i++)
	{
		cin >> s >> f >> l;
		transc[s][f]++;
	}
	dp[0][1].a[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int q=1;q<=k;q++)
				add(dp[i][j], mult(dp[i-1][q], transc[q][j]));
	int i=19;
	while(dp[n][1].a[i]==0 && i>0)i--;
	cout << dp[n][1].a[i--];
	for(;i>=0;i--)
	{
		cout.width(9);
		cout.fill('0');
		cout << right << dp[n][1].a[i];
	}
	cout << endl;
	return 0;
}

