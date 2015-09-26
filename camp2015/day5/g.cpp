#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

vector<int> adj[2000];
bool visited[2000];
int parent[2000];
int dist[2000][2000];
int distt[2000];

void bfs(int start)
{
	queue<pair<int, int> > toVisit;
	toVisit.push(make_pair(start, 0));
	visited[start]=true;
	while(!toVisit.empty())
	{
		pair<int, int> cur = toVisit.front();
		toVisit.pop();
		dist[start][cur.first]=cur.second;
		for(int i=0;i<adj[cur.first].size();i++)
		{
			if(visited[adj[cur.first][i]])
				continue;
			visited[adj[cur.first][i]]=true;
			toVisit.push(make_pair(adj[cur.first][i], cur.second+1));
		}
	}
	memset(visited, 0, sizeof(visited));
}

int main()
{
	ios::sync_with_stdio(false);
	int n,x,y;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(int i=0;i<n;i++)
		bfs(i);

	int res=0,c=1,m=0;
	visited[0]=true;
	for(int i=0;i<n;i++)
		distt[i] = dist[0][i];
	while(c<n)
	{
		m=0;
		for(int i=0;i<n;i++)
			if(!visited[i] && distt[i]>distt[m])
				m=i;
		res+=distt[m];
		visited[m]=true;
		//cout << m+1 << ' ' << distt[m] << endl;
		c++;
		for(int i=0;i<n;i++)
			if(!visited[i] && distt[i]<dist[m][i])
				distt[i]=dist[m][i];
	}
	cout << res << endl;
	return 0;
}

