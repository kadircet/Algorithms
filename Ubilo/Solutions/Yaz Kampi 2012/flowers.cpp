#include <iostream>
#include <fstream>
#define INF (1<<30)
using namespace std;

int F,V;
long long int C[101][101];
long long int A[101][101];

void printSol(ostream &os, int last, int flower)
{
	if(flower==1)
		os << last << " ";
	else
	{
		int llast=0;
		for(int i=1;i<last;i++)
			if(C[flower-1][i]+A[flower][last]==C[flower][last])
			{
				llast = i;
				break;
			}
		printSol(os, llast, flower-1);
		os << last << " ";
	}
}

int main()
{
	ifstream inp("flowers.gir");
	ofstream oup("flowers.cik");
	
	inp >> F >> V;
	for(int i=1;i<=F;i++)
		for(int j=1;j<=V;j++)
			inp >> A[i][j];
	
	
	for(int i=0;i<=F;i++)
		for(int j=0;j<=V;j++)
			C[i][j] = -INF;
	for(int i=0;i<=V;i++)
		C[0][i]=0;
		
		
	for(int i=1;i<=F;i++)
		for(int j=i;j<=V;j++)
			for(int k=i-1;k<j;k++)
			{
				int cost = C[i-1][k] + A[i][j];
				if(cost > C[i][j])
					C[i][j] = cost;
			}
	int m=-INF;
	int last=0;
	for(int i=1;i<=V;i++)
		if(C[F][i]>m)
		{
			m=C[F][i];
			last = i;
		}
	oup << m << endl;
	
	printSol(oup, last, F);
	oup << endl;
	return 0;
}

