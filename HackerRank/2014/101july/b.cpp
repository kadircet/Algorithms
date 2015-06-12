#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g[100001];
long sum[100001];

int main()
{
	int N, S=0, m=0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> g[i];
		S+=g[i];
		sum[i] = S;
		m = max(m, g[i]);
	}
	
	int x=0;
	for(int i=0;i<N;i++)
	{
		x+=g[i];
		if(x>=m && (S%x)==0)
		{
			bool f=true;
			int t=1;
			for(int j=i+1;j<N;j++)
				if(sum[j]-x*t>x)
				{
					f=false;
					break;
				}
				else if(sum[j]-x*t==x)
					t++;
			if(f)
				cout << x << ' ';
		}
	}
	cout << endl;
	
	return 0;
}

