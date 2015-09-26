#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char map[1000][1000];
bool visited[1000][1000];
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,-1,1,1,-1};
int l=0;
int n,m;

bool valid(int x, int y)
{
	return x>=0 && y>=0 && x<n && y<m;
}

int isClosed(int x, int y)
{
	for(int i=0;i<4;i++)
		if(valid(x+dx[i], y+dy[i]) && map[x+dx[i]][y+dy[i]]=='-')
			return 1;
	return 0;
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> map[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]=='+')
				l+=isClosed(i,j);
				
	cout << l << endl;
	return 0;
}
