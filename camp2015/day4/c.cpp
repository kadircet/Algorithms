#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
using namespace std;

int main()
{
	long long int x,y;
	long long int t=1;
	cin >> x >> y;
	int res=1,k=0;
	while(t<=y)
	{
		t*=10;
		k++;
	}
	x%=y;
	if(x==0)
	{
		cout << 0 << endl;
		return 0;
	}
	t=10;
	long long int minmod=(x*t)%y, maxmod=(x*t+t+y-1)%y;
	while(k>res && minmod<maxmod)
	{
		if(minmod==0)
			break;
		res++;
		t=(t*10)%y;
		minmod=(x*t)%y;
		maxmod=(x*t+t+y-1)%y;
	}
	cout << res << endl;
	return 0;
}

