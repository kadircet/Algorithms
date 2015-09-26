#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

vector<int> primes;
bool isPrime(int n)
{
	if(n==2)
		return true;
	if(n<2 || n%2==0)
		return false;
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true;
}

void genPrimes()
{
	for(int i=0;i<=1000000;i++)
		if(isPrime(i))
			primes.push_back(i);
}

int main()
{
	genPrimes();
	unsigned long long int n;
	cin >> n;
	for(int i=0;i<primes.size();i++)
		if(n%primes[i]==0)
		{
			cout << primes[i] << ' ' << n/primes[i] << endl;
			return 0;
		}
	return 0;
}

