#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

unsigned long long int mod(long long int x, long long int m)
{
	while(x<0)
		x+=m;
	return x%m;
}

int res(int a,int b,int m)
{
	long long int r=a*a-5*b*b;
	int toMult=1;
	if(r<0L)toMult=2;
	unsigned long long int x=mod(r, m);
	r=x;
	if(gcd(x,m)!=1 || x==0)
		return -1;
	for(int i=1;;i++)
	{
		x=mod(x, m);
		if(x==1)
			return i%2?i*toMulti:i;
		x*=r;
	}
	return -1;
}

int main()
{
	int T,a,b,m;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> a >> b >> m;
		cout << res(a,b,m) << endl;
	}
	
	return 0;
}

