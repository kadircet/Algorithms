#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
using namespace std;

vector<int> primes;

bool isPrime(int n)
{
	if(n==2)
		return true;
	if(n<2 || n%2==0)
		return false;
	for(int i=3;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

void genPrimes()
{
	for(int i=0;i*i<=1000000000;i++)
		if(isPrime(i))
			primes.push_back(i);
}

int inverse(int a, int n)
{
	int t,r,nt,nr,q;
	t=0, r=n, nr=a, nt=1;
	while(nr!=0)
	{
		int tmp=t;
		q = r/nr;
		t = nt;
		nt = tmp-q*nt;
		
		tmp = r;
		r=nr;
		nr=tmp-q*nr;
	}
	while(t<0)
		t+=n;
	return t;
}

unsigned long long powM(unsigned long long a, unsigned long long b, unsigned long long m)
{
	unsigned long long res=1;
	if(b==0)
		return res;
	while(b>1)
	{
		if(b&1)
			res=(res*a)%m;
		b>>=1;
		a=(a*a)%m;
	}
	return (res*a)%m;
}

int main()
{
	int K,n,e,c,p,q,phi;
	cin >> K;
	genPrimes();
	for(int t=0;t<K;t++)
	{
		cin >> n >> e >> c;
		for(int i=0;i<primes.size();i++)
			if(n%primes[i]==0 && isPrime(n/primes[i]))
			{
				p=primes[i];
				q=n/primes[i];
				break;
			}
		phi=(p-1)*(q-1);
		cout << powM(c,inverse(e,phi),n) << endl;
	}
	return 0;
}

 
