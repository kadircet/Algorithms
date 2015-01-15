#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T,N;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> N >> a >> b;
		
		vector<int> res;
		
		for(int i=0;i<N;i++)
			res.push_back(a*i+b*(N-i-1));
		
		sort(res.begin(), res.end());
		res.resize(unique(res.begin(), res.end())-res.begin());
		for(int i=0;i<res.size();i++)
			cout << res[i] << ' ';
		cout << endl;
	}
	
	return 0;
}

