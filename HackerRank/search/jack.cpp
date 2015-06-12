#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
struct edge
{
	int from,to;
	int cost;
};

vector<vector<edge> > edges;
vector<bool> visited;
bool found = false;

int bfs(int s, int e)
{
	priority_queue<ii, vector<ii>, greater<ii> > toVisit;
	toVisit.push(ii(0, s));
	
	//vector<int> dist(visited.size());
	
	while(!toVisit.empty())
	{
		ii cur = toVisit.top();
		toVisit.pop();
		if(visited[cur.second])
			continue;
		visited[cur.second] = true;
		
		if(cur.second==e)
		{
			found=true;
			return cur.first;
		}
		
		for(int i=0;i<edges[cur.second].size();i++)
			toVisit.push(ii(max(cur.first, edges[cur.second][i].cost), edges[cur.second][i].to));
	}
	return 0;
}

int main()
{
	int N,E;
	int f,t,c;
	
	cin >> N >> E;
	edges.resize(N);
	visited.resize(N);
	for(int i=0;i<E;i++)
	{
		cin >> f >> t >> c;
		f--;t--;
		
		edge e;
		e.cost=c;
		
		e.from=f,e.to=t;
		edges[f].push_back(e);
		
		e.to=e.from, e.from=t;
		edges[t].push_back(e);
	}
	int res=bfs(0, N-1);
	if(found)
		cout << res << endl;
	else
		cout << "NO PATH EXISTS" << endl;
	return 0;
}

