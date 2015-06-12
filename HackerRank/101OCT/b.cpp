#include <iostream>
using namespace std;

unsigned long long dates[50];

int base10(int n, int b)
{
	if(n==0)
		return 0;
	if(n%10>=b)
		return -1;
	
	int q = base10(n/10, b);
	if(q==-1)
		return -1;
	return n%10 + q*b;
}

int main()
{
	int N,m,d;
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> m >> d;
		int q = base10(d, m);
		if(q==-1)
			continue;
		
		dates[q]++;
	}
	
	unsigned long long res=0;
	for(int i=0;i<50;i++)
		res += dates[i]*(dates[i]-1)/2;
	
	cout << res << endl;

	return 0;
}

