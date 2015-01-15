#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007LL
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		vector<unsigned long long int> X(M-1), Y(N-1);
		
		for(int i=0;i<N-1;i++)
			cin >> Y[i];
		for(int i=0;i<M-1;i++)
			cin >> X[i];
		
		sort(Y.begin(), Y.end(), greater<int>());
		sort(X.begin(), X.end(), greater<int>());
		
		unsigned long long int res=0;
		unsigned long long int xi=0, yi=0;
		while(xi<X.size() && yi<Y.size())
		{
			if(X[xi]>Y[yi])
				res = (res+(X[xi++]*(yi+1))%MOD)%MOD;
			else
				res = (res+(Y[yi++]*(xi+1))%MOD)%MOD;
		}
		while(xi<X.size())
			res = (res+(X[xi++]*(yi+1))%MOD)%MOD;
		while(yi<Y.size())
			res = (res+(Y[yi++]*(xi+1))%MOD)%MOD;
		cout << res << endl;
	}
}

