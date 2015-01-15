#include <iostream>
#define MOD 1000000007ULL
using namespace std;

unsigned long long pow2(long N)
{
	if(N==0)
		return 1;
	
	unsigned long long res = pow2(N/2);
	res = (res*res)%MOD;
	if(N%2)
		res=(res*2)%MOD;
	return res;
}

int main()
{
	int T;
	long N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		unsigned long long res = (MOD+pow2(N+1)-1)%MOD;
		cout << (3+res)%MOD << endl;
	}
	
	return 0;
}

