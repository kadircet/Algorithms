#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> primes;
map<long long, int> count;
int primacity(long long n)
{
	for(long long i=2;i*i<=n;i++)
		if(n%i==0)
		{
			primes.push_back(i);
			count[i]=0;
			while(n%i==0)
				n/=i,count[i]++;
		}
	if(n>1)
	{
		primes.push_back(n);
		if(count.find(n)==count.end())
			count[n]=0;
		count[n]++;
	}
		
	return primes.size();
}

int main()
{
	long long q;
	cin >> q;
	int p = primacity(q);
	if(p==0 || primes[0]==q)
		cout <<"1\n0\n";
	else if((p==1 && count[primes[0]]==2 && primes[0]*primes[0]==q) || (p==2 && primes[0]*primes[1]==q))
		cout << "2\n";
	else
	{
		cout << "1\n";
		if(p==1)
			cout << primes[0]*primes[0] << endl;
		else
			cout << primes[0]*primes[1] << endl;
	}
	
	return 0;
}

