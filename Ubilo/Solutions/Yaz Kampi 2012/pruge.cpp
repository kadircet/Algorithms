#include <iostream>
#include <fstream>
using namespace std;

int f(int r, int e)
{
	if(r%2==0)
	{
		if(e<=r)
			return e;
		return (e+r)/2;
	}
	if(e<=r)
		return 0;
	return (e-r+1)/2;
}

unsigned long long int F(int b, int t, int e)
{
	unsigned long long int res=0;
	for(int r=b+1;r<=t;r++)
	{
		res += f(r, e);
		//cout << r << " , " << e << " : " << f(r, e) << endl;
	}
	return res;
	if(b%2==0)
	{
		if(t%2==1)
			return e/2 * 2*(t/2 - b/2 +1) - e/2;
		else
			return e/2 * 2*(t/2 - b/2 +1) - e/2 - f(t, e);
	}
	else
	{
		if(t%2==1)
			return e/2 * 2*(t/2 - b/2 +1) - e/2 - f(b-1, e);
		else
			return e/2 * 2*(t/2 - b/2 +1) - e/2 - f(b-1, e) - f(t, e);
	}
}

int main()
{
	ifstream inp("pruge.gir");
	ofstream oup("pruge.cik");
	int b, t, s, e;
	inp >> s >> b >> e >> t;
	oup << F(b,t,e) - F(b,t,s) << endl;
	return 0;
}

