#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool> > adj;
int ns;
vector<bool> visited;

void dfs(int c, int d)
{
	if(c==d)
	{
		ns++;
		return;
	}
	if(visited[c])
		return;
	visited[c] = true;
	for(int i=0;i<adj[c].size();i++)
	{
		if(adj[c][i])
			dfs(i, d);
	}
	visited[c] = false;
}

void print(vector<int>& p, int c, int d=1)
{
	if(c==0)
	{
		cout << "Shortest Route Length: " << d << endl;
		cout << "Shortest Route after Sorting of Routes of length " << d << ": " << (char)(c+'F') << ' ';
		return;
	}
	print(p, p[c], d+1);
	cout << (char)(c+'F') << ' ';
}

void bfs(int s, int d)
{
	queue<pair<int, int> > toVisit;
	toVisit.push(make_pair(s, s));
	vector<int> prev('Z'-'F'+1);
	//prev[s]=s;
	
	int l=s;
	while(!toVisit.empty())
	{
		int s = toVisit.front().first;
		int c = toVisit.front().second;
		toVisit.pop();
		
		if(c==d)
		{
			prev[d]=s;
			break;
		}
		
		if(visited[c])
			continue;
		visited[c] = true;
		//cout << (char)(s+'F') << "-->" << (char)(c+'F') << endl;
		prev[c]=s;
		//l=c;
		for(int i=0;i<adj[c].size();i++)
		{
			if(adj[c][i])
				toVisit.push(make_pair(c,i));
		}
	}
	print(prev, d);
}

int main()
{
	adj.resize('Z'-'F'+1);
	visited.resize('Z'-'F'+1);
	for(int i=0;i<'Z'-'F'+1;i++)
		adj[i].resize('Z'-'F'+1);
	
	char dest;
	cin >> dest;
	char a,b;
	cin >> a >> b;
	while(a!='A')
	{
		adj[a-'F'][b-'F'] = true;
		adj[b-'F'][a-'F'] = true;
		cin >> a >> b;
	}
	dfs(0, dest-'F');
	if(ns==0)
	{
		cout << "No Route Available from F to " << dest << endl;
		return 0;
	}
	cout << "Total Routes: " << ns << endl;
	
	for(int i=0; i<visited.size();i++)
		visited[i] = false;
	bfs(0, dest-'F');
	cout << endl;
	return 0;
}

