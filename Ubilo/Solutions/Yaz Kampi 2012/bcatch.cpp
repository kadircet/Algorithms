#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int C[2][1001][31];
int A[1001];
int T,W;

int main()
{
	ifstream inp("bcatch.gir");
	ofstream oup("bcatch.cik");
	
	inp >> T >> W;
	
	for(int i=0;i<T;i++)
		inp >> A[i+1];
	
	for(int i=1;i<=T;i++)
	{
		for(int c=0;c<=W;c++)
		{
			for(int j=0;j<2;j++)
			{
				C[j][i][c] = max(C[j][i][c], C[j][i-1][c] + (A[i]==j+1?1:0));
				if(c>0)
					C[j][i][c] = max(C[j][i][c], C[1-j][i-1][c-1] + (A[i]==j+1?1:0));
			}
		}
	}
	int m=C[0][T][W];
	if(C[1][T][W]>m)
		m = C[1][T][W];
	oup << m << endl;
	
	return 0;
}

