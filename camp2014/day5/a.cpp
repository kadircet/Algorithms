#include <iostream>
using namespace std;

int mat[100][100];
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> mat[i][j];
	for(int i=1;i<N;i++)
		for(int j=0;j<M;j++)
			mat[i][j] += mat[i-1][j];
			
	int res=0;
	for(int i=0;i<M;i++)
		if(mat[N-1][i]>res)
			res=mat[N-1][i];
	cout << res << endl;
	
	return 0;
}

