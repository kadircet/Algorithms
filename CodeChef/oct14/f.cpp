#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge
{
	int len;
	int x1,y1;
	int x2,y2;
	
	bool operator<(const edge& rhs) const
	{
		return len<rhs.len;
	}
};
vector<edge> edges, results;
int N,M,K;
bool board[100][100];

int main()
{
	int a,b;
	edge e;
	cin >> N >> M >> K;
	for(int i=0;i<K;i++)
	{
		cin >> a >> b;
		board[a-1][b-1]=true;
	}
	
	int lx,ly[100];
	for(int i=0;i<M;i++)
		ly[i]=0;
	for(int i=0;i<N;i++)
	{
		lx=0;
		for(int j=0;j<M;j++)
		{
			if(board[i][j])
			{
				e.x1=lx,e.y1=i;
				e.x2=j,e.y2=i;
				e.len = e.x2-e.x1-1;
				lx=e.x2;
				if(e.len>0)
					edges.push_back(e);
				
				e.x1=j, e.y1=ly[j];
				e.x2=j, e.y2=i;
				e.len = e.y2-e.y1-1;
				ly[j]=e.y2;
				if(e.len>0)
					edges.push_back(e);
			}
		}
	}
	
	int res=0;
	sort(edges.rbegin(), edges.rend());
	for(int i=0;i<edges.size();i++)
	{
		if(edges[i].x1==edges[i].x2)
		{
			int np=0;
			for(int j=edges[i].y1+1;j<edges[i].y2;j++)
			{
				if(board[edges[i].x1][j])np++;
				board[edges[i].x1][j]=true;
			}
			if(edges[i].len>np)
				results.push_back(edges[i]);
		}
		else
		{
			int np=0;
			for(int j=edges[i].x1+1;j<edges[i].x2;j++)
			{
				if(board[j][edges[i].y1])np++;
				board[j][edges[i].y1]=true;
			}
			if(edges[i].len>np)
				results.push_back(edges[i]);
		}
	}
	
	cout << results.size() << endl;
	for(int i=0;i<results.size();i++)
	{
		if(results[i].x1==results[i].x2)
			cout << (results[i].x1+1) << ' ' << (results[i].y1+2) << " 1" << endl;
		else
			cout << (results[i].x1+2) << ' ' << (results[i].y1+1) << " 0" << endl;
	}
	return 0;
}

