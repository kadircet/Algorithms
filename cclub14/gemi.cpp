#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct elev
{
	int to;
	int time;
};

struct node
{
	int idx, cost;
	
	bool operator<(const node& n) const
	{
		return n.cost<cost;
	}
};

map<string, vector<int> > rooms;
vector<string> colors;
vector<elev> elevators[800001];
bool visited[800001];

int shortest(int from, int to)
{
	memset(visited, 0, sizeof(visited));
	
	priority_queue<node> toVisit;
	node cur;
	cur.idx = from;
	cur.cost = 0;
	toVisit.push(cur);
	while(!toVisit.empty())
	{
		cur = toVisit.top();
		toVisit.pop();
		
		if(visited[cur.idx])
			continue;
		visited[cur.idx] = true;
		
		if(cur.idx==to)
			return cur.cost;
		
		for(int i=0;i<rooms[colors[cur.idx]].size();i++)
		{
			node to;
			to.idx = rooms[colors[cur.idx]][i];
			to.cost = cur.cost;
			
			if(!visited[to.idx])
				toVisit.push(to);
		}
		
		for(int i=0;i<elevators[cur.idx].size();i++)
		{
			node to;
			to.idx = elevators[cur.idx][i].to;
			to.cost = cur.cost+elevators[cur.idx][i].time;
			
			if(!visited[to.idx])
				toVisit.push(to);
		}
	}
	
	return -1;
}

int main()
{
	int T,N,M,S;
	int f;
	elev e;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		rooms.clear();
		colors.clear();
		colors.push_back("");
		
		cin >> N;
		string color;
		for(int i=0;i<N;i++)
		{
			cin >> color;
			rooms[color].push_back(i+1);
			colors.push_back(color);
		}
		
		cin >> M;
		for(int i=0;i<M;i++)
		{
			cin >> f >> e.to >> e.time;
			elevators[f].push_back(e);
		}
		
		cin >> S;
		int from, to;
		
		cout << "Test " << t << ":" << endl;
		for(int i=0;i<S;i++)
		{
			cin >> from >> to;
			cout << shortest(from, to) << endl;
		}
		
		for(int i=0;i<N;i++)
			elevators[i].clear();
	}
	
	return 0;
}

