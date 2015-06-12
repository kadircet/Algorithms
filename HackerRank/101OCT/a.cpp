#include <iostream>
#include <algorithm>
using namespace std;

string inp[100];

int main()
{
	int T,N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
		{
			cin >> inp[i];
			sort(inp[i].begin(), inp[i].end());
		}
		
		bool flag=true;
		for(int i=0;i<N-1;i++)
			for(int j=0;j<inp[i].size();j++)
				if(inp[i][j]>inp[i+1][j])
				{
					flag=false;
					break;
				}
		
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	
	return 0;
}

