#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[100000];
bool wow[100000];
bool visited[100000];
int N,K;
int far, fard;

void dfs(int cur, int d)
{
	if(visited[cur])
		return;
	visited[cur]=true;
	if(d>fard && wow[cur])
	{
		far=cur;
		fard=d;
	}
	
	for(int i=0;i<adj[cur].size();i++)
		dfs(adj[cur][i], d+1);
}

int main()
{
	int x,y;
	cin >> N >> K;
	for(int i=1;i<N;i++)
	{
		cin >> x >> y;
		if(x>y)
			swap(x,y);
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	for(int i=0;i<K;i++)
	{
		cin >> x;
		wow[x-1]=true;
	}
	
	dfs(0, 0);
	fard=0;
	memset(visited, 0, sizeof(visited));
	dfs(far, 0);
	cout << fard << endl;
	
	return 0;
}

