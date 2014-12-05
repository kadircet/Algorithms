#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool M[4001][4001];
vector<int> milks;

int main()
{
	ifstream inp("sut.gir");
	ofstream oup("sut.cik");
	int N,S=0;
	
	for(int i=0;i<4001;i++)
		for(int j=0;j<4001;j++)
			M[i][j] = false;
	M[0][0] = true;
	
	inp >> N;
	int m;
	for(int i=0;i<N;i++)
	{
		inp >> m;
		milks.push_back(m);
		S+=m;
	}
	
	for(int k=0;k<milks.size();k++)
		for(int i=S;i>=0;i--)
			for(int j=S;j>=0;j--)
			{
				if(M[i][j])
				{
					M[i+milks[k]][j] = true;
					M[i][j+milks[k]] = true;
				}	
			}
	for(int i=S;i>=0;i--)
		if(M[i][i])
		{
			oup << i << endl;
			break;
		}
	
	return 0;
}

