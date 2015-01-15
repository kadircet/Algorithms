#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _edge
{
	int from,to;
	int cost;
	bool valid;
}edge;

vector<edge> edges[200005];
int depth[200005];
bool visited[200005];
int N;
vector<int> maxs;
int max_out=999999;

int toCorrect(int pos)
{
	if(depth[pos]!=-1)
		return depth[pos];
		
	if(visited[pos])
		return 0;
	
	int d=0;
	edge e;
	visited[pos] = true;
	for(int i=0;i<edges[pos].size();i++)
	{
		e = edges[pos][i];
		int q = toCorrect(e.to);
		if(!e.valid)
			d+=q+1;
		else if(q>0)
			d+=q-1;
	}
	visited[pos] = false;
	
	return d;
}

int DFS(int pos)
{
	if(depth[pos]!=-1)
		return depth[pos];
	
	for(int i=0;i<edges[pos].size();i++)
	{
		edge e = edges[pos][i];
		int q = toCorrect(e.to);

		if(e.valid)
		{
			if(depth[pos] == -1 || depth[pos]>q-1)
				depth[pos] = q-1;
		}
		else
		{
			if(depth[pos] == -1 || depth[pos]>q+1)
				depth[pos] = q+1;
		}
	}
	
	return depth[pos];
}

int main()
{
	ifstream inp("baskent.gir");
	ofstream oup("baskent.cik");
	inp >> N;
	
	int s,e;
	edge ed;
	for(int i=0;i<N-1;i++)
	{
		inp >> s >> e;
		ed.from = s-1;
		ed.to = e-1;
		ed.valid = true;
		edges[ed.from].push_back(ed);
		ed.from = e-1;
		ed.to = s-1;
		ed.valid = false;
		edges[ed.from].push_back(ed);
		depth[i] = -1;
		visited[i]=false;
	}
	depth[N-1] = -1;
	visited[N-1]=false;

	for(int i=0;i<N;i++)
		DFS(i);
	
	for(int i=0;i<N;i++)
		if(depth[i]<max_out)
			max_out=depth[i];
	
	oup << max_out << endl;
	for(int i=0;i<N;i++)
		if(depth[i]==max_out)
			oup << i+1 << " ";
	oup << endl;
	return 0;
}

