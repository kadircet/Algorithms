#include <iostream>
using namespace std;

int N,Q,r;
long long M, f[100001];

long long powm(int b, int e)
{
	if(e==0)
		return 1;
	if(e==1)
		return b%M;
	
	long long root=powm(b, e/2);
	return (root*root)%M*(e%2?b%M:1);
}

long long tot(long long k)
{
	long long res=1;
	if(k==1)
		return 0;
	int c=0;
	for(int i=2;i*i<=k;i++)
	{
		c=0;
		while(k%i==0)
		{
			c++;
			k/=i;
		}
		if(c>0)
			res *= powm(i, c) - powm(i, c-1);
	}
	if(k>1)
		res *= k-1;
	return res;
}

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;
	f[0]=1;
	
	while(T--)
	{
		cin >> N >> M >> Q;	
		for(int i=1;i<=N;i++)
			f[i] = (f[i-1]*powm(i,i))%M;
		long long phiM = tot(M)-1;
		cout << phiM << endl;
	
		for(int i=0;i<Q;i++)
		{
			cin >> r;
			long long res = f[N] * powm(f[r], phiM);
			cout << (f[N] * ( * powm(f[N-r], phiM))%M)%M) << endl;
		}
	}
	return 0;
}

