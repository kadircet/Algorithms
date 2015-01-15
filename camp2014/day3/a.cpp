#include <iostream>
using namespace std;

int board[100],beg[100],end[100];

int main()
{
	int L,N,M;
	cin >> L >> N >> M;
		
	char x;
	for(int i=0;i<2*L;i++)
	{
		cin >> x;
		board[i%L]+=x=='-';
	}
	
	if(N==0 || M==0)
	{
		cout << "No" << endl;
		return 0;
	}
	
	int c=0;
	for(int i=0;i<L;i++)
		if(board[i]==2)
			c=1;
		else if(board[i]==0)
		{
			c=0;
			break;
		}
	if(c==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}


