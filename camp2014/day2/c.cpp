#include <iostream>
#include <cmath>
using namespace std;

unsigned long long a[20];
unsigned long long d(unsigned long long a)
{
	unsigned long long res=0;
	while(a>0)
		a/=10, res++;
	return res;
}

unsigned long long middle(unsigned long long b)
{
	unsigned long long res=b;
	unsigned long long c=d(b)-1;
	res%=(unsigned long long)pow(10.0, (double)c);
	
	return res/10;
}

unsigned long long f(unsigned long long b)
{
	if(b<10)
		return b;
	unsigned long long res=0,c=b;
	res += a[d(b)-1];
	
	while(b>=10)
		b/=10;
	unsigned long long first=b%10;
	
	res += middle(c);
	if(first!=1 && d(c)>=2)
		res += (first-1)*(unsigned long long)pow(10.0, (double)d(c)-2);
	if(c%10>=first)
		res++;
		
	return res;
}

int main()
{
	unsigned long long int l,r;
	cin >> l >> r;
	
	a[1]=a[2]=9;
	for(int i=3;i<20;i++)
		a[i]=a[i-1]*10;
	
	for(int i=2;i<20;i++)
		a[i]+=a[i-1];
	
	cout << (f(r) - f(l-1)) << endl;
	
	return 0;
}



