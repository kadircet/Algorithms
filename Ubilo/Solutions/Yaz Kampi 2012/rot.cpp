#include <iostream>
#include <fstream>
using namespace std;

char board[25][25];
char nboard[25][25];
int R,C,A;

void rotate270()
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			nboard[C-j-1][i] = board[i][j];
	swap(R,C);
}

void rotate180()
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			nboard[R-i-1][C-j-1] = board[i][j];
}

void rotate90()
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			nboard[j][R-i-1] = board[i][j];
	swap(R,C);
}

void rotate45()
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			nboard[i+j][j] = board[i][j];
	R+=C-1;
}

void printB(char board[25][25], ostream& oup)
{
	int mid=R-C;
	for(int i=0;i<R;i++, oup << endl)
	{
		if(A%90!=0)
		{
			for(int j=i;j<mid;j++)
				oup << " ";
			for(int j=i;j>mid;j--)
				oup << " ";
			for(int j=0;j<C;j++)
				if(board[i][j] != 0)
					oup << board[i][j] << " ";
		}
		else
		{
			for(int j=0;j<C;j++)
				oup << board[i][j];
		}
	}
}

int main()
{
	ifstream inp("Rot.gir");
	ofstream oup("Rot.cik");
	inp >> R >> C;
	for (int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			inp >> board[i][j];
	inp >> A;
	int n = A/90;
	n%=4;
	if(n==1)
		rotate90();
	else if(n==2)
		rotate180();
	else if(n==3)
		rotate270();
	if(n!=0)
	{
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				board[i][j] = nboard[i][j];
	}
	if(A%90!=0)
	{
		for(int i=0;i<25;i++)
			for(int j=0;j<25;j++)
				nboard[i][j] = 0;
		rotate45();
	}
	if(A%360!=0)
		printB(nboard, oup);
	else
		printB(board, oup);
	return 0;
}

