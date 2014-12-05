#include <iostream>
using namespace std;

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};
int mat[502][502];

int main()
{
	int n,m;
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> mat[i][j];
	
	double M=-1;
	int mi, mj;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			double tmp = mat[i][j]/2.0;
			for(int k=0;k<8;k++)
				tmp += mat[i+dx[k]][j+dy[k]]/16.0;
			
			if(tmp > M)
			{
				M=tmp;
				mi = i, mj=j;
			}
		}
		
	cout << mi << ' ' << mj << endl;
	return 0;
}

