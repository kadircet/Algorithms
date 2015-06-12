#include <iostream>
#include <cstring>
using namespace std;

int board[100][100];
int mrow[100];
int mcol[100];
int N,M;

int main()
{
	int T, t=0;
	cin >> T;
	
	while(T--)
	{
		cin >> N >> M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin >> board[i][j];
		
		bool found=true;
		t++;
		cout << "Case #" << t << ": ";
		memset(mrow, 0, sizeof(mrow));
		memset(mcol, 0, sizeof(mcol));
		
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				mrow[i] = max(mrow[i], board[i][j]);
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				mcol[j] = max(mcol[j], board[i][j]);
		
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(board[i][j]!=mcol[j] && board[i][j]!=mrow[i])
				{
					cout << "NO";
					found = false;
					i=N;
					break;
				}
		
		if(found)
			cout << "YES";
		cout << endl;
	}
	
	return 0;
}

