#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	long long l,r,a,b,c;
	cin >> l >> r;
	
	for(a=l;a<=r;a++)
		for(b=a+1;b<=r;b++)
			for(c=b+1;c<=r;c++)
				if(gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)!=1)
				{
					cout << a << ' ' << b << ' ' << c << endl;
					return 0;
				}
	
	cout << -1 << endl;
	return 0;
}

