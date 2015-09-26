#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

unsigned long long int N,sum;
long long int K[100000];

#define abs(x) (x)<0?-(x):(x)

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> K[i];
		sum+=K[i];
	}
	sum/=N;
	for(int i=0;i<N;i++)
		K[i]-=sum;
	
	unsigned long long int res=0;
	long long int q=0;
	for(int i=0;i<N;i++)
	{
		res+=abs(q);
		q+=K[i];
	}
	cout << res << endl;
	return 0;
}
