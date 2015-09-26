#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char map[8][8];
bool visited[8][8][8][8][65];
int dx[]={-1,1,-1,1};
int dy[]={-1,1,1,-1};
int best=0;

bool valid(int x, int y)
{
	return x>=0 && y>=0 && x<8 && y<8;
}

void dfs(int cx, int cy, int px=0, int py=0, int count=0)
{
	if(visited[cx][cy][px][py][count])
		return;
	
	visited[cx][cy][px][py][count]=true;
	for(int i=0;i<4;i++)
	{
		if(valid(cx+dx[i], cy+dy[i])&&valid(cx+2*dx[i], cy+2*dy[i]) && map[cx+dx[i]][cy+dy[i]]==1
			&& map[cx+2*dx[i]][cy+2*dy[i]]==0)
		{
			map[cx+dx[i]][cy+dy[i]]=0;
			dfs(cx+2*dx[i], cy+2*dy[i], cx, cy, count+1);
			map[cx+dx[i]][cy+dy[i]]=1;
		}
	}
	visited[cx][cy][px][py][count]=false;
	best=max(best,count);
}

int main()
{
	vector<pair<int, int> > W;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='W')
			{
				map[i][j]=2;
				W.push_back(pair<int,int>(i,j));
			}
			else if(map[i][j]=='B')
				map[i][j]=1;
			else
				map[i][j]=0;
		}
	
	for(int i=0;i<W.size();i++)
	{
		map[W[i].first][W[i].second]=0;
		dfs(W[i].first, W[i].second);
		map[W[i].first][W[i].second]=2;
	}
	cout << best << endl;
	return 0;
}

