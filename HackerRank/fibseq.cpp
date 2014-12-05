#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if(N<=2)
	{
		cout << N << endl;
		return 0;
	}
	vector<long> a;
	long cur;
	for(int i=0;i<N;i++)
	{
		cin >> cur;
		a.push_back(cur);
	}
	
	int l=0,r=2;
	int best=2;
	while(r<N)
	{
		//cout << r << endl;
		if(a[r-1] + a[r-2] == a[r])
		{
			r++;
			best = max(best, r-l);
		}
		else
		{
			best = max(best, r-l);
			l=r-1;
			r=l+2;
		}
	}
	
	cout << best << endl;
	return 0;
}

