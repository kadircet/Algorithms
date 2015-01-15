#include <iostream>
using namespace std;

int map[501][501];
int fil[501][501];
int Cost[501][501], I[501][501];
int row[501][501], col[501][501];
int maps[501][501];

int main()
{
	int R,C, H,W;
	cin >> R >> C;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			cin >> map[i][j];
			row[i][j] = (j>0?row[i][j-1]:0) + map[i][j]*map[i][j];
			col[i][j] = (i>0?col[i-1][j]:0) + map[i][j]*map[i][j];
			maps[i][j] = (i>0?maps[i-1][j]:0) + (j>0?maps[i][j-1]:0) + map[i][j]*map[i][j] - (i>0&&j>0?maps[i-1][j-1]:0);
		}
		
	long sum=0
	cin >> H >> W;
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
			cin >> fil[i][j];
			sum += fil[i][j]*fil[i][j];
		}
	
	for(int i=0;i<=R-H;i++)
		for(int j=0;j<=C-W;j++)
		{
			I[i][j] = maps[i+H][j+W] + (i>0&&j>0?maps[i-1][j-1]:0);
			I[i][j] -= (i>0?maps[i-1][j+W]:0) + (j>0?maps[i+H][j-1]:0);
		}
			
	for(int i=0;i<=R-H;i++)
		for(int j=0;j<=C-W;j++)
			Cost[i][j] = sum + map[i][j]*map[i][j];
			
			
	long best=40*40*501*501;
	int ansi, ansj;
	for(int j=0;j<=C-W;j++)	
		for(int i=0;i<=R-H;i++)
		{
			long cur = 0;
			for(int k=0;k<H;k++)
				for(int l=0;l<W;l++)
				{
					cur += (map[i+k][j+l]-fil[k][l])*(map[i+k][j+l]-fil[k][l]);
					if(cur>=best)
					{
						k=H;
						break;
					}
				}
			if(best>cur)
			{
				best = cur;
				ansi = i;
				ansj = j;
				if(best == 0)
				{
					j = C;
					break;
				}
			}
		}
		
	cout << best << endl;
	cout << ansi+1 << ' ' << ansj+1 << endl;
	return 0;
}

