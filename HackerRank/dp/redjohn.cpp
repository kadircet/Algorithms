#include <iostream>
using namespace std;

int dp[41];
int primes[220000];

bool isPrime(int n)
{
	if(n==2)
		return true;
	if(n%2==0 || n<2)
		return false;
	
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
			
	return true;
}

int main()
{
	dp[0]=dp[1]=dp[2]=dp[3]=1;
	for(int i=4;i<41;i++)
		dp[i]=dp[i-1]+dp[i-4];
	
	primes[0]=0;
	for(int i=1;i<220000;i++)
		primes[i]=primes[i-1]+isPrime(i);

	int T,N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << primes[dp[N]] << endl;
	}
	
	return 0;
}
