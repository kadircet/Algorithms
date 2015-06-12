#include <iostream>
using namespace std;

int N;
double l[200000], r[200000];
int a[200000], b[200000];

int main()
{
	char x;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x;
		a[i] = x-'A';
	}
	for(int i=0;i<N;i++)
	{
		cin >> x;
		b[i] = x-'A';
	}
	
	double res=0;
	for(int i=0;i<'Z'-'A'+1;i++)
	{
		l[0] = r[N-1] = 0;
		for(int j=0;j<N;j++)
		{
			if(j!=0)
				l[j] = l[j-1];
			if(b[j]==i)
				l[j] += j+1;
		}
		for(int j=N-1;j>=0;j--)
		{
			if(j!=N-1)
				r[j] = r[j+1];
			if(b[j] == i)
				r[j] += N-j;
		}
		for(int j=0;j<N;j++)
			if(a[j] == i)
				res += l[j]*(N-j) + ((j<N-1)?r[j+1]*(j+1):0);
	}
	double div = 0;
	for(int i=0;i<N;i++)
		div+= (i+1.0)*(i+1.0);
		
	cout.precision(10);
	cout << (res/div) << endl;
	return 0;
}

