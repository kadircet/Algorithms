#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int nr[101];
	int T,N,K;
	
	cin >> T;
	while(T--)
	{
		memset(nr, 0, sizeof(nr));
		cin >> N >> K;
		
		int cur, tot=0;
		long res=0;
		for(int i=0;i<N;i++)
		{
			cin >> cur;
			cur %= K;
			tot += cur;
			tot %= K;
			
			res += nr[tot] + (tot==0);
			nr[tot]++;
		}
		
		cout << res << endl;
	}
	
	return 0;	
}

