#include <iostream>
#include <vector>
using namespace std;

bool adj[3000][3000];
vector<int> edges[3000];

int main()
{
	int N,M,a,b;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		adj[a-1][b-1]=1;
		edges[a-1].push_back(b-1);
	}
	
	long long c=0,res=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(i==j)
				continue;
			c=0;
			for(int k=0;k<edges[i].size();k++)
				c += adj[edges[i][k]][j];
			res += c*(c-1)/2;
		}
	cout << res << endl;
	return 0;
}

