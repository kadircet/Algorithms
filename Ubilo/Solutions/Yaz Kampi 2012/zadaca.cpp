#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

char *format;
char *format1 = "%d\n", *format2="%09d\n";

long long int voidpower(int q, int a, int b)
{
	long double t=q;
	if(t>=1000000000)
	{
		format = format2;
		t = fmod(t,1000000000);
	}
	for(int i=0;i<b;i++)
	{
		t*=a;
		if(t>=1000000000)
		{
			format = format2;
			t = fmod(t,1000000000);
		}
	}
	return (long long int)t;
}

vector<int> generatePrimes()
{
	vector<int> primes;
	primes.push_back(2);
	bool isPrime;
	for(int i=3;i*i<1000000000;i+=2)
	{
		isPrime = true;
		for(int j=0;j<primes.size();j++)
		{
			if(i%primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if(isPrime)
			primes.push_back(i);
	}
	return primes;
}

bool contains(int x, vector<int> asdf)
{
	for(int i=0;i<asdf.size();i++)
		if(asdf[i] == x)
			return true;
	return false;
}

int main()
{
	vector<int> primes = generatePrimes();

	freopen("zadaca.gir","r",stdin);
	FILE* oup = fopen("zadaca.cik", "w");
	long long int q = 1;
	vector<int> number1, number2;
	
	int N,M,c;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> c;
		number1.push_back(c);
	}
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> c;
		number2.push_back(c);
	}
	format = format1;
	
	for(int t=0;t<primes.size();t++)
	{
		int p = primes[t];
		
		int cp, cp1=0, cp2=0;
		for(int i=0;i<number1.size();i++)
		{
			while(number1[i]%p==0)
			{
				number1[i]/=p;
				cp1++;
			}
		}
		
		for(int i=0;i<number2.size();i++)
		{
			while(number2[i]%p==0)
			{
				number2[i]/=p;
				cp2++;
			}
		}
		
		cp = cp1;
		if(cp1>cp2)
			cp=cp2;
		
		q = voidpower(q, p, cp);
	}
	vector<int> leftNumbers;
	for(int i=0;i<number1.size();i++)
		if(number1[i] > 1)
			leftNumbers.push_back(number1[i]);
	for(int j=0;j<number2.size();j++)
		if(number2[j] > 1)
			if(contains(number2[j], leftNumbers))
				q = voidpower(q, number2[j], 1);
	fprintf(oup, format, q);
	fcloseall();
	return 0;
}

