#include <iostream>
#include <vector>
using namespace std;

struct move
{
	int x,y;
	int dir;
};

int N,M,K;
bool board[101][101],board2[101][101];
vector<move> results, results2;

int main()
{
	int a,b;
	move m;
	cin >> N >> M >> K;
	for(int i=0;i<K;i++)
	{
		cin >> a >> b;
		board2[a-1][b-1]=board[a-1][b-1]=true;
	}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			if(!board[i][j])
			{
				int lr=0,upd=0;
				for(int k=i;k<N;k++)
					if(board[k][j])
						break;
					else
						lr++;
				for(int k=j;k<M;k++)
					if(board[i][k])
						break;
					else
						upd++;
				m.x=i+1, m.y=j+1;
				if(upd<lr)
				{
					for(int k=i;k<N;k++)
						if(board[k][j])
							break;
						else
							board[k][j]=true;
					m.dir=1;
				}
				else
				{
					for(int k=j;k<M;k++)
						if(board[i][k])
							break;
						else
							board[i][k]=true;
					m.dir=0;
				}
				results.push_back(m);
			}
		}
		
	int nv=0, nh=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!board2[i][j])
			{
				nv++;
				if(j>0 && board2[i][j-1]==0)
					nv--;
			}
	
	for(int j=0;j<M;j++)
		for(int i=0;i<N;i++)
			if(!board2[i][j])
			{
				nh++;
				if(i>0 && board2[i-1][j]==0)
					nh--;
			}

	int res = min(nv, nh);
	if(res==nv)
	{
		m.dir=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if(board2[i][j]==0)
				{
					m.x=i+1, m.y=j+1;
					results2.push_back(m);
					while(j<M && board2[i][j]==0)
						board2[i][j++]=1;
				}
			}
	}
	else
	{
		m.dir=1;
		for(int j=0;j<M;j++)
			for(int i=0;i<N;i++)
			{
				if(board2[i][j]==0)
				{
					m.x=i+1, m.y=j+1;
					results2.push_back(m);
					while(i<N && board2[i][j]==0)
						board2[i++][j]=1;
				}
			}
	}
	
	if(results.size()>results2.size())
		results=results2;
				
	cout << results.size() << endl;
	for(int i=0;i<results.size();i++)
		cout << results[i].x << ' ' << results[i].y << ' ' << results[i].dir << endl;
	
	return 0;
}

