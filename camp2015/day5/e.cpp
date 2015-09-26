#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char map[16][16];
bool visited[16][16];

int count(int x, int y)
{
	int res=0;
	memset(visited, 0, sizeof(visited));
	for(int i=x;i<16;i++)
		for(int j=y;j<16;j++)
			if(map[i][j]=='#')
				visited[i-x][j-y]=true;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			if((i<x || j<y) && map[i][j]=='#' && !visited[i][j])
				return -1;
	memset(visited, 0, sizeof(visited));
	for(int i=0;i+x<16;i++)
		for(int j=0;j+y<16;j++)
			if(map[i][j]=='#')
				visited[i+x][j+y]=true;
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			if((i+x>16 || j+y>16) && map[i][j]=='#' && !visited[i][j])
				return -1;
	for(int i=x;i<16;i++)
		for(int j=y;j<16;j++)
			res+=map[i][j]=='#' && map[i-x][j-y]=='#';
	return res;
}

void print(int x, int y)
{
	for(int i=0;i<16;i++, cout << endl)
		for(int j=0;j<16;j++)
		{
			if(i<x || j<y)
			{
				cout << '.';
				continue;
			}
			if(map[i-x][j-y]=='#' && map[i][j]=='#')
				cout << '#';
			else
				cout << '.';
		}
}

int main()
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			cin >> map[i][j];
	
	int mcost=-1,mx,my;
	for(int x=0;x<=15;x++)
		for(int y=0;y<=15;y++)
		{
			int cost=count(x,y);
			if((mcost==-1 || cost<mcost) && cost>0)
			{
				mcost=cost;
				mx=x;
				my=y;
			}
			//if(cost!=-1)
			//	cout << x << ' ' << y << ' ' << cost << endl;
		}
		
	cout << -my << ' ' << -mx << endl;
	print(mx,my);
	return 0;
}

