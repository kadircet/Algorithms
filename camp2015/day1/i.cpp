#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

vector<int> start;
vector<int> edges[10000];
pair<int, int> edge[1000000];
bool locked[10000][10000];
bool redge[10000][10000];
bool visited[10000];
queue<int> toVisit;

void bfs()
{
	/*if(visited[cur])
		return;
	visited[cur] = true;*/
	
	while(!toVisit.empty())
	{
		int cur=toVisit.front();
		toVisit.pop();
		for(int i=0;i<edges[cur].size();i++)
			if(!visited[edges[cur][i]] && !locked[cur][edges[cur][i]])
			{
				visited[edges[cur][i]]=true;
				toVisit.push(edges[cur][i]);
			}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int N,M,P,x,y;
	//cin >> N >> M >> P;
	scanf("%d%d%d", &N, &M, &P);
	for(int i=0;i<P;i++)
	{
		//cin >> x;
		scanf("%d", &x);
		visited[x-1]=true;
		toVisit.push(x-1);
	}
	for(int i=0;i<M;i++)
	{
		//cin >> x >> y;
		scanf("%d%d", &x, &y);
		if(redge[x-1][y-1])
			continue;
		redge[x-1][y-1]=redge[y-1][x-1]=true;
		edges[x-1].push_back(y-1);
		edges[y-1].push_back(x-1);
		edge[i] = make_pair(x-1, y-1);
	}
	for(int i=0;i<N;i++)
	{
		//cin >> x;
		scanf("%d", &x);
		for(int j=0;j<x;j++)
		{
			//cin >> y;
			scanf("%d", &y);
			if(edge[y-1].second==i)
				locked[edge[y-1].first][edge[y-1].second]=true;
			else
				locked[edge[y-1].second][edge[y-1].first]=true;
		}
	}
	bfs();
	for(int i=0;i<N;i++)
		if(!visited[i])
		{
			//cout << (i+1) << endl;
			printf("%d\n", i+1);
			return 0;
		}
	//cout << "Impossible" << endl;
	printf("Impossible\n");
	return 0;
}


