#include <iostream>
#include <fstream>
#define INF 999999
using namespace std;

int N,E,d;
int cost[101][21][101];

int takeMaxRoad(int LE, int N, int D)
{
	if(N<=0)
		return INF;
	if(D<=0)
		return 0;
	if(cost[LE][N][D] != -1)
		return cost[LE][N][D];
		
	int NE = D+E-d;
	
	int time = 999999;
	for(int x=1;x*x<=LE;x++)
	{
		int t = takeMaxRoad(LE-x*x, N, D-x)+1;
		if(t<time)
			time = t;
	}
	if(N>1)
		for(int x=1;x*x<=NE;x++)
		{
			int t = takeMaxRoad(NE-x*x, N-1, D-x)+1;
			if(t<time)
				time = t;
		}
	return cost[LE][N][D]=time;
}

int main()
{
	ifstream inp("bisiklet.gir");
	ofstream oup("bisiklet.cik");
	for(int j=0;j<101;j++)
		for(int k=0;k<21;k++, cost[j][k][0] = 0)
			for(int p=1;p<101;p++)
				cost[j][k][p] = -1;
	
	inp>>N>>E>>d;
	if(d>E)
		oup << 0 << endl;
	else
		oup << takeMaxRoad(E, N, d) << endl;
			
	return 0;
}

