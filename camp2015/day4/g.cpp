#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#define abs(x) ((x)>0?(x):(-(x)))
#define sqrt(x) sqrt2(x)
using namespace std;

struct disk
{
	double a,b,c,d;
} sun, moon;

double dist(double t)
{
	return (sun.a*t+sun.b-moon.a*t-moon.b)*(sun.a*t+sun.b-moon.a*t-moon.b)+
			(sun.c*t+sun.d-moon.c*t-moon.d)*(sun.c*t+sun.d-moon.c*t-moon.d);
}

double sqrt2(double x)
{
	double l=0,r=x+1,m;
	while(l+1e-10<r)
	{
		m=(l+r)/2;
		if(m*m>x)
			r=m;
		else
			l=m;
	}
	return l;
}

int main()
{
	cin >> sun.a >> sun.b >> sun.c >> sun.d;
	cin >> moon.a >> moon.b >> moon.c >> moon.d;
	
	double l=0,r=10000,m1,m2;
	while(true)
	{
		m1=l+(r-l)/3;
		m2=r-(r-l)/3;
		if(abs(l-r)<1e-7)
		{
			l=(l+r)/2;
			break;
		}
		if(dist(m1)>dist(m2))
			l=m1;
		else
			r=m2;
	}
	
	double tmin = l;
	if(dist(tmin)-4>=-1e-7 || tmin-1000>-1e-7)
		cout << "0.00" << endl;
	else
	{
		double alp;
		if(abs(dist(tmin))<=1e-7)
			alp = 100.0;
		else
		{
			alp = acos(sqrt(dist(tmin))/2);
			alp = 2*alp-sqrt(dist(tmin))/2*sqrt(4-dist(tmin));
			alp = alp*100.0/M_PI;
		}
		
		if(alp<=1e-6)
		{
			cout << "0.00" << endl;
			return 0;
		}
		
		double l=0,r=tmin,m;
		while(l+1e-7<r)
		{
			m=(l+r)/2;
			if(dist(m)>4)
				l=m;
			else
				r=m;
		}
		l=(l+r)/2;
		cout << fixed;
		cout << alp << endl << l << ' ' << tmin+(tmin-l) << ' ' << tmin << endl;
	}
}

