#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long a[100000];
int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> a[i];
	
	long long added = 0;
	for(int i=1;i<N;i++)
		added += max(0LL, a[i-1]-a[i]);
	cout << added << endl;
	
	return 0;
}

