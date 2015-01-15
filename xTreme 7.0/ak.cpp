#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int> > adj;
vector<int> inDegree;
vector<double> point;
vector<bool> visited;

int main()
{
	int N;
	cin >> N;
	int a,b;
	adj.resize(N+1);
	inDegree.resize(N);
	point.resize(N);
	
	while(true)
	{
		cin >> a >> b;
		if(cin.eof())
			break;
		
		adj[a-1].push_back(b-1);
		inDegree[b-1]++;
	}
	
	queue<int> toVisit;
	for(int i=0;i<inDegree.size();i++)
		if(inDegree[i]==0)
		{
			toVisit.push(i);
			point[i]=1.;
		}
	
	visited.resize(N);
	while(!toVisit.empty())
	{
		int c=toVisit.front();
		toVisit.pop();
		
		if(visited[c])
			continue;
		visited[c] = true;
		
		for(int i=0;i<adj[c].size();i++)
		{
			point[adj[c][i]] += point[c]/adj[c].size();
			toVisit.push(adj[c][i]);
		}
	}
	
	double m=0;
	for(int i=0;i<point.size();i++)
		m=max(m,point[i]);
	for(int i=0;i<point.size();i++)
		if(abs(point[i]-m)<=0.01)
			cout << i+1 << endl;
	
	return 0;
}

