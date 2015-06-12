#include <iostream>
#include <cmath>
using namespace std;

int a[6], y;

double calc(double x)
{
	double res=0, o=x;
	x=1;
	for(int i=5;i>=0;i--)
	{
		res+=x*a[i];
		x*=o;
	}
	
	return res;
}

int main()
{
	for(int i=0;i<6;i++)
		cin >> a[i];
	cin >> y;
	
	double l=0, r=y+1e-6, m;
	while(l+1e-6<r)
	{
		m = (l+r)/2;
		//cout << l << ' ' << r << ' '<< m << ' ' << calc(m) << endl;
		if(abs(calc(m)-y)<=1e-6)
			break;
		else if(calc(m)>y)
			r=m;
		else if(calc(m)<y)
			l=m+1e-6;
	}
	cout.precision(10);
	cout << m << endl;
	
	return 0;
}

