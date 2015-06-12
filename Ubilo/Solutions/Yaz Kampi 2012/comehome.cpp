#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _edge
{
	char from,to;
	int cost;
}edge;

class CompareEdge
{
	public:
		bool operator()(edge& e1, edge& e2)
		{
			return e1.cost>e2.cost;
		}
};

vector<edge> edges['z'-'A'+1];
int N;
int E;

bool containCow(char c)
{
	return c>='A' && c<'Z';
}
void SP(ostream& os)
{
	bool visited['z'-'A'+1];
	int dist['z'-'A'+1];
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
		dist[i] = -1;
	}
	priority_queue<edge, vector<edge>, CompareEdge> toVisit;
	
	for(int i=0;i<edges['Z'-'A'].size();i++)
	{
		edge e = edges['Z'-'A'][i];
		toVisit.push(edges['Z'-'A'][i]);
		dist[e.to] = e.cost;
	}

	visited['Z'-'A'] = true;
	dist['Z'-'A'] = 0;
	
	while(!toVisit.empty())
	{
		edge e = toVisit.top();
		toVisit.pop();
		
		int edgeTo = e.to;
		int edgeFrom = e.from;
		if(visited[edgeTo])
			continue;
		visited[edgeTo] = true;
		
		if(containCow(edgeTo+'A'))
		{
			os << (char)(edgeTo+'A') << " ";
			os << e.cost << endl;
			return;
		}
		
		for(int i=0;i<edges[edgeTo].size();i++)
		{
			e = edges[edgeTo][i];
			if(dist[e.to] == -1 || dist[e.to] > dist[e.from] + e.cost)
				dist[e.to] = dist[e.from] + e.cost;
			e.cost = dist[e.to];
			
			toVisit.push(e);
		}
	}
	return;
}

int main()
{
	N='z'-'A'+1;
	ifstream inp("comehome.gir");
	ofstream oup("comehome.cik");
	
	inp >> E;
	char s,e;
	int c;
	edge ed;
	for(int i=0;i<E;i++)
	{
		inp >> s >> e >> c;
		ed.from = s-'A';
		ed.to = e-'A';
		ed.cost = c;
		edges[ed.from].push_back(ed);
		ed.from = e-'A';
		ed.to = s-'A';
		edges[ed.from].push_back(ed);
	}
	SP(oup);
	return 0;
}

