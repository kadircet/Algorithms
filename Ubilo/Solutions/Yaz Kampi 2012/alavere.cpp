#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

typedef struct _edge
{
	char e1,e2;
	int cost;
}edge;

vector<edge> edges;
map<char, char> pathFrom;
int max_c;

vector<edge> getAdj(char cur)
{
	vector<edge> adj;
	vector<edge>::iterator it1;
	for(it1=edges.begin(); it1!=edges.end(); it1++)
	{
		edge it;
		it.e1 = it1->e1;
		it.e2 = it1->e2;
		it.cost = it1->cost;
		if(it.e1 == cur)
			adj.push_back(it);
		else if(it.e2 == cur)
		{
			it.e2 = it.e1;
			it.e1 = cur;
			adj.push_back(it);
		}
	}
	return adj;
}

void dfs(char cur, char end, map<char, bool> visit, int c, map<char, char> path)
{
	if(cur == end)
	{
		if(c>max_c)
		{
			max_c=c;
			pathFrom = path;
		}
		return;
	}
	if(visit[cur])
		return;
	visit[cur] = true;
	vector<edge> adj=getAdj(cur);
	for(int i=0;i<adj.size();i++)
	{
		path[adj.e2] = adj.e1;
		dfs(adj.e2, end, visit, c+adj.cost, path);
	}
	visit[cur] = false;
}

int V,E;

int main()
{
	ifstream inp("alavere.gir");
	inp >> V >> E;
	edge e;
	for (int i=0;i<E;i++)
	{
		inp >> e.e1 >> e.e2 >> e.cost;
		edges.push_back(e);
	}
	inp >> e.e1 >> e.e2;
	map<char, bool> visit;
	pathFrom[e.e1] = e.e1;
	map<char, char> path;
	dfs(e.e1, visit, path);
	cout << cost[e.e2] << endl;
	return 0;
}

