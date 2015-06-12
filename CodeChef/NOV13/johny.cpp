#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,K,T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		vector<int> a(N);
		for(int i=0;i<N;i++)
			cin >> a[i];
		cin >> K;
		K--;
		int res=0;
		for(int i=0;i<N;i++)
			if(a[i]<a[K])
				res++;
		cout << res+1 << endl;
	}
	return 0;
}

