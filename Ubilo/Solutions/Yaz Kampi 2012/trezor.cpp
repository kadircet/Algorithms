#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int A, B, L;
vector<int> divisors[4001];

vector<int> uni(vector<int> a, vector<int> b)
{
	vector<int> ret;
	for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
		for(vector<int>::iterator jt = b.begin(); jt != b.end(); jt++)
			if( *it == *jt )
            	ret.push_back(*it);
            else
            	ret.push_back(*it * *jt);
            	
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    
    return ret;
}

long long int canSee(vector<int> a)
{
	long long int ret = 0;
	int n=a.size();
	for(int mask=1; mask<(1<<n); mask++)
	{
		int x = 1;
		int bits = 0;
		for(int i=0;i<n;i++)
			if((mask>>i)&1)
			{
				x = x/gcd(x, a[i])*a[i];
				bits++;
			}
			
		if(bits&1)ret+=L/x;
		else ret-=L/x;
   }
   return ret;
}

void generateDivisors()
{
	for(int i=1;i<=4000;i++)
	{
		int x=i;
		for(int d=2;d*d<=x;d++)
		{
			if(x%d==0)
			{
				while(x%d==0)x/=d;
				divisors[i].push_back(d);
			}
		}
		if(x>1)divisors[i].push_back(x);
	}
}

int main()
{
	ifstream inp("trezor.gir");
	ofstream oup("trezor.cik");
	generateDivisors();
	long long int sn=0, s=0, sp=0;
	
	inp >> A >> B >> L;
	
	for(int i=0;i<=(A+B)/2;i++)
	{
		long long int a = i == 0 ? L-1 : canSee(divisors[i]);
		long long int b = canSee(divisors[A+B-i]);
		long long int c = i == 0 ? b : canSee(uni(divisors[i], divisors[A+B-i]));

		int todoub = (2*i == (A+B)) ? 1 : 2;
		
		sp += todoub*c;
		s += todoub*(a + b - 2*c);
		sn += todoub*(L-a-b+c);
	}
	
	oup << sp << endl << s << endl << sn << endl;
	return 0;
}

