#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

unsigned long long int fact[21];

int main()
{
	fact[0]=1;
	for(int i=1;i<21;i++)
		fact[i]=fact[i-1]*i;
	int n,sum,m[10];
	sum=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> m[i];
		sum+=m[i];
	}
	unsigned long long int res=fact[sum];
	for(int i=0;i<n;i++)
		res/=fact[m[i]];
	cout << res << endl;
	return 0;
}
