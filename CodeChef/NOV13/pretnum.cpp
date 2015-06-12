#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*map<long long, int> divs;
int nDiv(long long n)
{
	if(n==1)
		return 1;
	if(divs.find(n)!=divs.end())
		return divs[n];
	
	long long N = n;
	int res=1,t;
	for(long long i=2;i*i<=N;i++)
	{
		t=0;
		while(n%i==0)
		{
			n/=i;
			t++;
		}
		res*=t+1;
		
		t=0;
		while(n%(N/i)==0)
		{
			n/=N/i;
			t++;
		}
		res*=t+1;
	}
	if(res==1)
		res=2;
	return divs[N]=res;
}*/
vector<int> primes;
bool isPrime(long long n)
{
	if(binary_search(primes.begin(), primes.end(), n))
		return true;
	if(n<2||n%2==0)
		return false;

	for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++)
		if(n%primes[i]==0)
			return false;
	
	primes.push_back(n);
	return true;
}

bool isPrimeDiv(long long n)
{
	if(n==2)
		return true;
	if(n==1)
		return false;
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++)
		if(n%primes[i]==0)
		{
			int count=0;
			while(n%primes[i]==0)
				n/=primes[i],count++;
			if(n==1)
				return isPrime(count+1);
			return false;
		}
	
	return true;
}

int main()
{
	primes.push_back(2);
	for(int i=3;i<1000000;i+=2)
		isPrime(i);
	cout << primes.size() << endl;
	
	int T;
	cin >> T;
	while(T--)
	{
		long long L,R;
		cin >> L >> R;
		int res=0;
		for(;L<=R;L++)
		{
			//res += isPrime(nDiv(L));
			
			if(L%100000==0)//isPrimeDiv(L))
				cout << L << ':' << res << endl;
			res += isPrimeDiv(L);
		}
		cout << res << endl;
	}
	
	return 0;
}

