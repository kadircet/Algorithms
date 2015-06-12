#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> x;
	int N,K,t;
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> t;
		x.push_back(t);
	}
	sort(x.begin(), x.end());
	
	int res=1<<30;
	for(int i=0;i<=N-K;i++)
		res = min(res, x[i+K-1]-x[i]);
	cout << res << endl;
	
	return 0;
}

