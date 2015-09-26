#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int edge[7][7];
bool visited[7];

void dfs(int cur)
{
	if(visited[cur])
		return;
	visited[cur]=true;
	
	for(int i=0;i<7;i++)
		if(edge[cur][i])
			dfs(i);
}

int main()
{
	int n,x,y;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		edge[x][y]++;
		edge[y][x]++;
	}
	
	int nodd=0;
	for(int i=0;i<7;i++)
	{
		x=0;
		for(int j=0;j<7;j++)
			x+=edge[i][j];
		nodd+=x&1;
	}
	
	for(int i=0;i<7;i++)
		for(int j=0;j<7;j++)
			if(edge[i][j])
			{
				dfs(i);
				i=7;
				break;
			}
	y=0;
	for(int i=0;i<7;i++)
		if(!visited[i])
		{
			x=0;
			for(int j=0;j<7;j++)
				x+=edge[i][j];
			y+=x>0;
		}
		
	if(y||nodd>2)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}

