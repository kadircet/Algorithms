#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int k,x,y,cx,cy;
	cin >> k;
	cx=cy=0;
	for(int i=0;i<k;i++)
	{
		cin >> x >> y;
		if(abs(y-cy-1)>abs(x-cx))
		{
			cout << "NO" << endl;
			return 0;
		}
		cx=x;
		cy=y-1;
	}
	cout << "YES" << endl;
	return 0;
}

