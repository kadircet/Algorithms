#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

typedef struct _edge
{
	int from,to;
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

vector<edge> edges[100];
int N;

int mst()
{
	bool visited[100];
	int cost=0;
	int nV=0;
	for(int i=0;i<N;i++)
		visited[i] = false;
	priority_queue<edge, vector<edge>, CompareEdge> toVisit;
	for(int i=0;i<edges[0].size();i++)
		toVisit.push(edges[0][i]);
	visited[0] = true;
	while(!toVisit.empty() && nV < N)
	{
		edge e = toVisit.top();
		toVisit.pop();
		
		int edgeTo = e.to;
		if(visited[edgeTo])
			continue;
		visited[edgeTo] = true;
		nV++;

		cost += e.cost;
		for(int i=0;i<edges[edgeTo].size();i++)
			toVisit.push(edges[edgeTo][i]);
	}
	return cost;
}

int main()
{
	ifstream inp("agrinet.gir");
	ofstream oup("agrinet.cik");
	
	inp >> N;
	int cost;
	edge e;
	for(int i=0;i<N;i++)
	{
		e.from = i;
		for(int j=0;j<N;j++)
		{
			e.to = j;
			inp >> cost;
			e.cost = cost;
			edges[i].push_back(e);
		}
	}
	oup << mst() << endl;
	return 0;
}

