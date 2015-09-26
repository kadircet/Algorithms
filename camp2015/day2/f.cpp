#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
	double r1,r2,l,alp,low=0,up=M_PI/2.,mid,tmp;
	cin >> r1 >> r2 >> l;
	cout << fixed;
	if(r1==r2)
	{
		cout << setprecision(6) << (l/2.-M_PI*r1) << endl;
		return 0;
	}
	if(r1<r2)
		swap(r1,r2);
	l/=2.;
	while(low+1e-12<up)
	{
		mid=(low+up)/2.;
		tmp = (M_PI-mid)*r1+mid*r2+(r1-r2)*tan(mid);
		if(tmp+1e-12>l)
			up=mid;
		else
			low=mid;
	}
	alp=low;
	cout << setprecision(6) << ((r1-r2)/cos(alp)) << endl;
	return 0;
}

