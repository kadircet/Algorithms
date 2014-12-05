#include <iostream>
using namespace std;

char map[101][101],nmap[101][101];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin >> map[i][j];
			nmap[i][j]=map[i][j];
		}
	
	for(int i=1;i<N-1;i++)
		for(int j=1;j<N-1;j++)
		{
			int c=0;
			for(int k=0;k<4;k++)
				c+=map[i+dx[k]][j+dy[k]]<map[i][j];

			if(c==4)
				nmap[i][j] = 'X';
		}
	
	for(int i=0;i<N;i++,cout << endl)
		for(int j=0;j<N;j++)
			cout << nmap[i][j];
	return 0;
}

