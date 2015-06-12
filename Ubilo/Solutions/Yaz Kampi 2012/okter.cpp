#include <iostream>
#include <fstream>
using namespace std;

int R,C;
char** map;

int main()
{
	ifstream inp("okret.gir");
	ofstream oup("okret.cik");
	
	inp >> R >> C;
	map = new char*[R];
	for(int i=0;i<R;i++)
	{
		map[i] = new char[C];
		for(int j=0;j<C;j++)
			inp >> map[i][j];
	}
	
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			//oup << i << " " << j << endl;
			if(map[i][j] == '.')
			{
				if(i==0 && j==0)
				{
					int t=0;
					t+=map[i+1][j]=='X';
					t+=map[i][j+1]=='X';
					if(t>=1)
					{
						oup << "1" << endl;
						return 0;
					}
				}
				else if(i==R-1 && j==C-1)
				{
					int t=0;
					t+=map[i-1][j]=='X';
					t+=map[i][j-1]=='X';
					if(t>=1)
					{
						oup << "1" << endl;
						return 0;
					}
				}
				else if(i==R-1)
				{
					int t=0;
					t+=map[i-1][j]=='X';
					if(j>0)
						t+=map[i][j-1]=='X';
					if(j<R-1)
						t+=map[i][j+1]=='X';
					
					if(t>=2)
					{
						oup << "1" << endl;
						return 0;
					}
				}
				else if(j==C-1)
				{
					int t=0;
					if(i>0)
						t+=map[i-1][j]=='X';
					t+=map[i][j-1]=='X';
					if(i<R-1)
						t+=map[i+1][j]=='X';
					if(t>=2)
					{
						oup << "1" << endl;
						return 0;
					}
				}
				else if(i==0)
				{
					int t=0;
					if(j>0)
						t+=map[i][j-1]=='X';
					if(j<R-1)
						t+=map[i][j+1]=='X';
					t+=map[i+1][j]=='X';
					if(t>=2)
					{
						oup << "1" << endl;
						return 0;
					}
				}
				else if(j==0)
				{
					int t=0;
					if(i>0)
						t+=map[i-1][j]=='X';
					if(i<R-1)
						t+=map[i+1][j]=='X';
					t+=map[i][j+1]=='X';
					if(t>=2)
					{
						oup << "1" << endl;
						return 0;
					}	
				}
				else
				{
					int t=0;
					t+=map[i-1][j]=='X';
					t+=map[i][j-1]=='X';
					t+=map[i][j+1]=='X';
					t+=map[i+1][j]=='X';
					if(t>=3)
					{
						oup << "1" << endl;
						return 0;
					}
				}
			}
		}
	oup << "0" << endl;
	return 0;
}

