#include <iostream>
#include <cstdio>
#define sum(i,j) (dp[i][j]*count[i][j])
using namespace std;

long long mat[101][101];
long long dp[101][101][301];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> mat[i+1][j+1];
	
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int k=0;k<301;k++)
				dp[i][j][k] = 1<<30;
			
	dp[1][1][1] = mat[1][1];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=2;k<=2*N;k++)
			{
				if(i+j==2)
					j++;
				dp[i][j][k] = min(min(dp[i-1][j][k-1], dp[i][j-1][k-1]),dp[i-1][j-1][k-1])+mat[i][j];
			}
	
	double res=dp[N][N][0];
	for(int i=1;i<=2*N;i++)
		res = min(res, ((double)dp[N][N][i])/i);
	printf("%.9f\n", res);
	return 0;
}


