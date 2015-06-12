#include <iostream>
using namespace std;

int best[51], k[51], l[51];
bool avaib[51];
int T;

int main()
{
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> k[i];
		avaib[i] = k[i]<=T-i;
	}
	
	for(int i=0;i<T;i++)
		cin >> l[i];
	
	for(int i=T-1;i>=0;i--)
	{
		if(avaib[i]==false)
			continue;

		int lose=0;
		for(int j=1;j<k[i];j++)
			lose = max(lose, best[j+i]);
		if(l[i]>lose)
		{
			best[i] = l[i];
			for(int j=1;j<k[i];j++)
				best[j+i]=0;
		}
	}
	int res=0;
	for(int i=0;i<T;i++)
		res += best[i];
	cout << res << endl;
	
	return 0;
}

