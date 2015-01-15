#include <iostream>
using namespace std;

int main()
{
	int T,res;
	int N,C,M;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> N >> C >> M;
		res = N/C;
		int wrap = res,n;
		while(wrap>=M)
		{
			n=wrap/M;
			wrap=wrap%M+n;
			res+=n;
		}
		cout << res << endl;
	}
    return 0;
}

