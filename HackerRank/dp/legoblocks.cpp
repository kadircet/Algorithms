#include <iostream>
using namespace std;

#define MOD 1000000007L

long P[1001];
long A[1001][1001];
long S[1001][1001];

int main()
{
	P[0]=1;
	for(int j=1;j<1001;j++)
		for(int i=1;i<5 && i<=j;i++)
			P[j]=(P[j]+P[j-i])%MOD;
	
	for(int i=1;i<1001;i++)
	{
		A[1][i] = P[i];
		S[i][1] = 1;
	}
		
	for(int i=2;i<1001;i++)
		for(int j=1;j<1001;j++)
			A[i][j] = (A[i-1][j]*A[1][j])%MOD;
			
	
	int T;
	int H[100],W[100];
	cin >> T;
	for(int i=0;i<T;i++)
		cin >> H[i] >> W[i];
	
	for(int w=2;w<1001;w++)
		for(int j=0;j<T;j++)
		{
			int h = H[j];
			S[h][w] = A[h][w];
			for(int i=1;i<w;i++)
				S[h][w] = ((S[h][w]-(S[h][i]*A[h][w-i])%MOD)+MOD)%MOD;
		}
		
	for(int i=0;i<T;i++)
		cout << S[H[i]][W[i]] << endl;
	
	return 0;
}

