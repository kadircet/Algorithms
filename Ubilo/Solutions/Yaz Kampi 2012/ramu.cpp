#include <iostream>
#include <fstream>
#define INF 10000000
using namespace std;

int C[401][401];
int A[401];
int N,M;

int main()
{
	ifstream inp("ramu.gir");
	ofstream oup("ramu.cik");
	
	inp >> N >> M;
	for(int i=1;i<=N;i++)
		inp >> A[i];
	for(int i=1;i<=M;i++)
		C[0][i] = -INF;
	
	for(int d=1;d<=N;d++)
		for(int w=1;w<=M;w++)
		{
			int cost=-INF;
			if(w%2==1)
			{
				cost = C[d-1][w-1] -A[d];
				if(C[d-1][w] > cost)
					cost = C[d-1][w];
			}
			else
			{
				cost = C[d-1][w-1] +A[d];
				if(C[d-1][w] > cost)
					cost = C[d-1][w];
			}
			C[d][w] = cost;
		}
	int m=0;
	//for(int i=0;i<=N;i++, cout << endl)
	for(int j=0;j<=M;j++)
		if(C[N][j]>m)// << " " ;
			m=C[N][j];
	oup << m << endl;
	return 0;
}

