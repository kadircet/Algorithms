#include <iostream>
using namespace std;
#define MOD 1000000007

int main()
{
	int N,T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int res=0,t;
		for(int i=0;i<N;i++)
		{
			cin >> t;
			res |= t;
		}
		
		for(int i=0;i<N-1;i++)
			res = (res*2)%MOD;
		cout << res << endl;
	}
	
	return 0;
}

