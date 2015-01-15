#include <iostream>
#define MOD 1000000007LL
using namespace std;

long long T,N,M;

long long powm(long long a, long long b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	long long p = powm(a, b/2);
	return (((p*p)%MOD)*(b%2?a:1))%MOD;
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		if(N==1)
			cout << M << endl;
		else
			cout << ((M*(M-1)%MOD)*powm(M-2, N-2))%MOD << endl;
	}
}

