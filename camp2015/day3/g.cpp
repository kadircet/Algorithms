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
	long long int n,m,h,f;
	cin >> n >> m >> h >> f;
	long long int mins = (h+7)/8;
	long long int maxf = (n/3)*(m/3);
	long long int maxspace = n*m-8*mins;
	if(mins>maxf || f>maxspace)
		cout << "BAZINGA!" << endl;
	else
	{
		maxf = min((n*m-f)/8,maxf);
		cout << mins << ' ' << maxf << endl;
	}
	
	return 0;
}

