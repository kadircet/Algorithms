#include <iostream>
#include <cstring>
using namespace std;

char board[4][4];

char win(char c[])
{
	bool o,x;
	o=x=false;
	for(int i=0;i<4;i++)
		if(c[i]=='.')
			return 0;
		else if(c[i]=='O')
			o=true;
		else if(c[i]=='X')
			x=true;
	if(o&&x)
		return 0;
	return o?'O':'X';
}

int main()
{
	int T,i=0;
	cin >> T;
	
	while(T--)
	{
		i++;
		cout << "Case #" << i << ": ";
		
		bool emp=false, found=false;
		memset(board, 0, sizeof(board));
		
		char check[4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				cin >> board[i][j];
				if(board[i][j]=='.')
					emp=true;
			}
		for(int i=0;i<4;i++)
			check[i] = board[i][i];
		if(win(check)!=0)
		{
			cout << win(check) << " won" << endl;
			continue;
		}
		
		for(int i=0;i<4;i++)
			check[i] = board[3-i][i];
		if(win(check)!=0)
		{
			cout << win(check) << " won" << endl;
			continue;
		}
		
		for(int j=0;j<4;j++)
		{
			for(int i=0;i<4;i++)
				check[i] = board[j][i];
			if(win(check)!=0)
			{
				cout << win(check) << " won" << endl;
				found=true;
				break;
			}
			
			for(int i=0;i<4;i++)
				check[i] = board[i][j];
			if(win(check)!=0)
			{
				cout << win(check) << " won" << endl;
				found=true;
				break;
			}
		}
		if(found)
			continue;
		
		if(emp)
			cout << "Game has not completed" << endl;
		else
			cout << "Draw" << endl;
	}
	
	return 0;
}

