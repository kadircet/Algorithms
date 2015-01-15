#include <iostream>
#include <string>
#define MOD 1000000007ULL
using namespace std;

unsigned long long B[1000001], W[1000001], X[1000001];
unsigned long long prefix[1000001], suffix[1000001];
unsigned long long pow2[1000001];
int N,K;
string inp;

int main()
{
	cin >> N >> K;
	cin >> inp;
	
	pow2[0]=1;
	for(int i=1;i<=N;i++)
		pow2[i] = (pow2[i-1]*2)%MOD;
		
	for(int i=0;i<N;i++)
	{
		if(i!=0)
			B[i] = B[i-1], X[i]=X[i-1];
		X[i] += inp[i]=='X';
		if(inp[i]!='W')
			B[i]++;
		else
			B[i]=0;
	}
	
	for(int i=N-1;i>=0;i--)
	{
		W[i] = W[i+1];
		if(inp[i]!='B')
			W[i]++;
		else
			W[i]=0;
	}
	
	prefix[0] = inp[0]=='X'?2:1;
	if(K==1)
		prefix[0] = inp[0]!='B';

	for(int i=1;i<N;i++)
	{
		prefix[i] = (prefix[i-1]*(inp[i]=='X'?2:1))%MOD;
		if(B[i]>=K && (i-K<0 || inp[i-K]!='B'))
			prefix[i] = (prefix[i]-(i>=K+1?prefix[i-K-1]:1)+MOD)%MOD;
	}
	
	suffix[N-1] = inp[N-1]=='X'?2:1;
	if(K==1)
		suffix[N-1] = inp[N-1]!='W';
	
	for(int i=N-2;i>=0;i--)
	{
		suffix[i] = (suffix[i+1]*(inp[i]=='X'?2:1))%MOD;
		if(W[i]>=K && (i+K>=N || inp[i+K]!='W'))
			suffix[i] = (suffix[i]-(i+K+1<N?suffix[i+K+1]:1)+MOD)%MOD;
	}
	
	unsigned long long rightsum=0, res=0, tmp;
	int l=N-2,r=N-1;
	while(l>=0)
	{
		while(l<r)
		{
			if(W[r]>=K && (r+K>=N || inp[r+K]!='W'))
				rightsum = (rightsum+(r+K+1<N?suffix[r+K+1]:1))%MOD;
			r--;
		}
		//cout << l << ' ' << r << ' ' << rightsum << endl;
		tmp = ((l>=K+1?prefix[l-K-1]:1)*rightsum)%MOD;
		if(B[l]>=K && (l-K<0 || inp[l-K]!='B'))
			res = (res+tmp)%MOD;
		if(inp[l]=='X')
			rightsum=(2*rightsum)%MOD;
		l--;
	}
	cout << res << endl;
	
	return 0;
}

