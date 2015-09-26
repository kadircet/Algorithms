#pragma comment(linker, "/STACK:400777216")
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char map[1000][1000];
int n,m;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,-1,0,1,-1,1,-1,0};
int visited[1000][1000];

bool valid(int x, int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}

void dfs(int x, int y, int c)
{
	if(visited[x][y]>0)
		return;
	visited[x][y]=c;
	
	for(int i=0;i<8;i++)
		if(valid(x+dx[i], y+dy[i]) && map[x+dx[i]][y+dy[i]]=='#')
			dfs(x+dx[i], y+dy[i], c);
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> map[i][j];
	
	int res=0;
	dfs(n-1, 0, 1);
	dfs(0, m-1, 2);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]=='.')
			{
				bool has1=false, has2=false;
				for(int k=0;k<8;k++)
					if(valid(i+dx[k], j+dy[k]))
					{
						if(visited[i+dx[k]][j+dy[k]]==1)
							has1=true;
						else if(visited[i+dx[k]][j+dy[k]]==2)
							has2=true;
					}
				res+=has1&&has2;
			}
	cout << res << endl;
	return 0;
}

