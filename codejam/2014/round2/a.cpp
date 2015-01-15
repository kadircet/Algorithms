#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		vector<int> inc;
		int N, X;
		cin >> N >> X;
		
		inc.resize(N);
		for(int i=0;i<N;i++)
			cin >> inc[i];
		
		sort(inc.begin(), inc.end());
		
		int res=0;
		int b=0, e=N-1;
		while(b<e)
		{
			int s = inc[b] + inc[e];
			if(s<=X)
				e--, b++;
			else
				e--;
			res++;
		}
		
		res+=max(e-b+1,0);
		
		cout << "Case #" << t << ": " << res << endl;
	}
	
	return 0;
}

