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
int a[101];
bool used[80000];

bool isPrime(int n)
{
	for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++)
		if(n%primes[i]==0)
			return false;
	return true;
}

void genPrimes()
{
	primes.push_back(2);
	for(int i=3;i<1000000;i+=2)
		if(isPrime(i))
			primes.push_back(i);
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

unsigned long long int lcm(int a, int b)
{
	unsigned long long int res=a;
	res=res/gcd(a,b)*b;
	return res;
}

int main()
{
	//genPrimes();
	int n,tmp,pos=0;
	cin >> n;
	for(int i=0;i<=n;i++)
		a[i]=1;
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
		{
			cin >> tmp;
			a[i-1]=lcm(a[i-1], tmp);
			a[j]=lcm(a[j], tmp);
		}
		
	/*for(int i=0;i<primes.size();i++)
		for(int j=0;j<n;j++)
			if(gcd(primes[i], a[j])>=a[j])
				used[i]=true;*/
	
	cout << a[0];	
	for(int i=1;i<n;i++)
	{
		if(a[i-1]>=a[i])
		{
			pos=2;
			while(a[i]*pos<=a[i-1])
				pos++;
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				if(gcd(a[i]*pos,a[j])!=gcd(a[i],a[j]))
				{
					pos++;
					j=-1;
				}
			}
			a[i]*=pos;
		}
		cout << ' ' << a[i];
	}
	cout << endl;
	return 0;
}
