#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned long long int> x, sum;
	unsigned long long int N,K,t;
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> t;
		x.push_back(t);
	}
	sort(x.begin(), x.end());
	
	sum.push_back(x[0]);
	for(int i=1;i<N;i++)
		sum.push_back(sum.back()+x[i]);
	
	unsigned long long int m=1000000000, res=0;
	/*for(int i=0;i<=N-K;i++)
	{
		res=0;
		int c=K-1;
		for(int j=0;j<K/2;j++)
		{
			res += ((unsigned long long int)c)*(x[K-1-j+i]-x[j+i]);
			c-=2;
			if(res>=m)
				break;
		}
		m = min(res, m);
	}*/
	
	int c=K-1;
	for(int i=0;i<K/2;i++)
	{
		res += ((unsigned long long int)c)*(x[K-1-i]-x[i]);
		c-=2;
	}
	m=res;
	for(int i=1;i<=N-K;i++)
	{
		int s=i,f=i+K-1;
		res += (K-1)*(x[s-1]+x[f]);
		res -= 2*(sum[f-1]-sum[s-1]);
		m=min(res, m);
	}
	
	cout << m << endl;	
	return 0;
}

