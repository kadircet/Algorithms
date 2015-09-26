#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int n,g,k,s;
	cin >> n >> g;
	s=g;
	for(int i=1;i<n;i++)
	{
		cin >> k;
		g=gcd(g,k);
		s+=k;
	}
	cout << (s/g) << endl;
	return 0;
}


