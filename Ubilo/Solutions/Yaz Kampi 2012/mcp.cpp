#include <iostream>
#include <fstream>
using namespace std;

int N;
int sizes[105];
int C[105][105];

int MCP()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			C[i][j] = -1;
	for(int i=0;i<N;i++)
		C[i][i] = 0;

	for(int l=1;l<N;l++)
		for(int i=0;i<N-l;i++)
		{
			int j=i+l;
			for(int k=i;k<j;k++)
			{
				int cost = C[i][k] + C[k+1][j] + sizes[i]*sizes[k+1]*sizes[j+1];
				if(cost<C[i][j] || C[i][j] == -1)
					C[i][j] = cost;
			}
		}

	return C[0][N-1];
}

int main()
{
	ifstream inp("mcp.gir");
	ofstream oup("mcp.cik");
	inp >> N;
	for(int i=0;i<=N;i++)
		inp >> sizes[i];
		
	oup << MCP() << endl;
	
	return 0;
}

