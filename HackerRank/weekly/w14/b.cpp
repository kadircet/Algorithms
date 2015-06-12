#include <iostream>
using namespace std;

int main()
{
	int T;
	unsigned long long int N,res,K,l,r,arr[200000];
	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		res = N*(N+1)/2;
		for(int i=0;i<N;i++)
			cin >> arr[i];
		l=r=0;
		while(r<N)
		{
			if(arr[r]<=K)
				r++;
			else
			{
				res-=(r-l)*(r-l+1)/2;
				r++;
				l=r;
			}
		}
		if(l<r)
			res-=(r-l)*(r-l+1)/2;
		cout << res << endl;
	}
	
	return 0;
}
