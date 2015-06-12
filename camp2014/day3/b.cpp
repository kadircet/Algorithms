#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[800];
int source,sink;
int capacity[800][800];
int from[800], visited[800];

int bfs()
{
	for(int i=0;i<=sink;i++)
		from[i] = -1, visited[i]=0;
	queue<int> toVisit;
	toVisit.push(source);
	visited[source]=1;
	
	int node,next,cap;
	bool found=false;
	while(!toVisit.empty())
	{
		node = toVisit.front(), next;
		toVisit.pop();
		
		for(int i=0;i<adj[node].size();i++)
		{
			next = adj[node][i];
			if(!visited[next] && capacity[node][next]>0)
			{
				visited[next] = 1;
				from[next] = node;
				toVisit.push(next);
				
				if(next==sink)
				{
					found = true;
					break;
				}
			}
		}
		if(found)
			break;
	}
	
	node=sink, cap=10000;
	while(from[node]!=-1)
	{
		cap = min(cap, capacity[from[node]][node]);
		node = from[node];
	}
	
	node=sink;
	while(from[node]!=-1)
	{
		int prev = from[node];
		capacity[prev][node]-=cap;
		capacity[node][prev]+=cap;
		node=prev;
	}
	
	if(cap==10000)
		return 0;
	return cap;
}

int main()
{
	int n=1,tot=0;
	int W,H,node;
	char map[20][20];
	int nodes[20][20];
	
	cin >> H >> W;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			cin >> map[i][j];
			if(map[i][j]!='.')
				nodes[i][j]=n++, tot++;
			if(map[i][j]=='W')
				n++;
		}
	source=0,sink=n;
	
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			node=nodes[i][j];
			if(map[i][j]=='W')
			{
				capacity[node][node+1]=1;
				adj[node].push_back(node+1);
				adj[node+1].push_back(node);
				if(i%2)
				{
					if(j+1<W && map[i][j+1]=='B')
					{
						capacity[node+1][nodes[i][j+1]]=1;
						adj[node+1].push_back(nodes[i][j+1]);
						adj[nodes[i][j+1]].push_back(node+1);
					}
					if(j-1>=0 && map[i][j-1]=='B')
					{
						capacity[node+1][nodes[i][j-1]]=1;
						adj[node+1].push_back(nodes[i][j-1]);
						adj[nodes[i][j-1]].push_back(node+1);
					}
				}
				else
				{
					if(i+1<H && map[i+1][j]=='B')
					{
						capacity[node+1][nodes[i+1][j]]=1;
						adj[node+1].push_back(nodes[i+1][j]);
						adj[nodes[i+1][j]].push_back(node+1);
					}
					if(i-1>=0 && map[i-1][j]=='B')
					{
						capacity[node+1][nodes[i-1][j]]=1;
						adj[node+1].push_back(nodes[i-1][j]);
						adj[nodes[i-1][j]].push_back(node+1);
					}
				}
			}
			else if(map[i][j]=='B')
			{
				if(i%2)
				{
					capacity[node][sink] = 1;
					adj[node].push_back(sink);
					adj[sink].push_back(node);
				}
				else
				{
					capacity[source][node]=1;
					adj[node].push_back(source);
					adj[source].push_back(node);
					
					if(i+1<H && map[i+1][j]=='W')
					{
						capacity[node][nodes[i+1][j]]=1;
						adj[node].push_back(nodes[i+1][j]);
						adj[nodes[i+1][j]].push_back(node);
					}
					if(i-1>=0 && map[i-1][j]=='W')
					{
						capacity[node][nodes[i-1][j]]=1;
						adj[node].push_back(nodes[i-1][j]);
						adj[nodes[i-1][j]].push_back(node);
					}
					if(j+1<W && map[i][j+1]=='W')
					{
						capacity[node][nodes[i][j+1]]=1;
						adj[node].push_back(nodes[i][j+1]);
						adj[nodes[i][j+1]].push_back(node);
					}
					if(j-1>=0 && map[i][j-1]=='W')
					{
						capacity[node][nodes[i][j-1]]=1;
						adj[node].push_back(nodes[i][j-1]);
						adj[nodes[i][j-1]].push_back(node);
					}
				}
			}
		}
		
	int p=bfs(), res=0;
	while(p)
	{
		res+=p;
		p=bfs();
	}
	cout << (tot-3*res) << endl;
		
	return 0;
}

