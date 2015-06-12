#include <iostream>
#define MOD 1000000007
using namespace std;

long long powm(long long a, long long b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(a==1)
		return 1;
	long long p = powm(a, b/2);
	return (((p*p)%MOD)*(b%2?a:1))%MOD;
}
long long N, L;

long long comb(long long a, long long b)
{
	if(b>a)
		return 0;
	if(b>a-b)
		b=a-b;
	if(b==0 || b==a)
		return 1;
	
	long long res=1;
	for(int i=0;i<b;i++)
		res = (res*(a-i)*powm(b-i, MOD-2))%MOD;
	return res;
}

long long fact(long long x)
{
	long long res=1;
	for(int i=1;i<=x;i++)
		res = (res*i)%MOD;
	return res;
}

int main()
{
	cin >> N >> L;
	long long x = 2*N-(L+2*(N-L)+2);
	
	cout << (comb(N-L-1+x, x)*comb(N,L))%MOD*fact(N-L)%MOD << endl;
}
