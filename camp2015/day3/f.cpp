#pragma comment(linker, "/STACK:4000000")
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

map<string, int> rank;
vector<string> inverse;
int edges[200005];
int visited[200005];

int find(int r, int c)
{
	if(visited[r]==c)
		return 0;
	visited[r]=c;
	if(edges[r]==-1)
		return r;
	if(edges[r]==0)
		return 0;
	return edges[r]=find(edges[r], c);
}

int main()
{
	ios::sync_with_stdio(false);
	string u,v,line;
	int n,m;
	cin >> n;
	cin.read((char*)&m, 1);
	rank["NULL"]=0;
	inverse.push_back("NULL");
	for(int i=0;i<200005;i++)
		edges[i]=-1;
	for(int i=0;i<n;i++)
	{
		getline(cin, line);
		m=line.find(' ');
		u=line.substr(0,m);
		v=line.substr(m+1);
		if(rank.find(u)==rank.end())
		{
			rank[u]=inverse.size();
			inverse.push_back(u);
		}
		if(rank.find(v)==rank.end())
		{
			rank[v]=inverse.size();
			inverse.push_back(v);
		}
		edges[rank[u]]=rank[v];
	}
	cin >> m;
	cin.read((char*)&n, 1);
	for(int i=0;i<m;i++)
	{
		getline(cin, u);
		if(rank.find(u)==rank.end())
			cout << u << endl;
		else
			cout << inverse[find(rank[u],i+1)] << endl;
	}
	return 0;
}

