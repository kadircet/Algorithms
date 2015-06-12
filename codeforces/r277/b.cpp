#include <iostream>
#include <cstring>
using namespace std;

int board[101][101], b2[101][101];
int row[101],col[101];

int main()
{
	int m,n;
	cin >> m >> n;
	for(int i=0;i<m;i++)
		row[i]=1;
	for(int j=0;j<n;j++)
		col[j]=1;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> board[i][j];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==0)
				row[i]=col[j]=0;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			b2[i][j] = row[i] && col[j];
	
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(b2[i][j])
				row[i]=col[j]=1;
				
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(board[i][j] && !(row[i] || col[j]))
			{
				cout << "NO" << endl;
				return 0;
			}
	
	cout << "YES" << endl;
	for(int i=0;i<m;i++, cout << endl)
		for(int j=0;j<n;j++)
			cout << (row[i] && col[j]) << ' ';
	return 0;
}

