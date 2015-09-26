#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> adj[101];

int main()
{
	int K,n,m,e,x,y;
	cin >> K;
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<101;j++)
			adj[j].clear();
		cin >> n >> m;
		for(int j=0;j<m;j++)
		{
			cin >> x >> y;
			if(x!=y)
			{
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}
		cin >> e;
		sort(adj[e].begin(), adj[e].end());
		adj[e].resize(distance(adj[e].begin(),unique(adj[e].begin(), adj[e].end())));
		if(adj[e].size()!=0)
			cout << adj[e][0];
		else
			cout << ' ';
		for(int j=1;j<adj[e].size();j++)
			cout << ' ' << adj[e][j];
		cout << endl;
	}
	return 0;
}

 
