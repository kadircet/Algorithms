#include <iostream>
#include <fstream>
#include <vector>
#define INF 10000000
using namespace std;

long long int lc[1005][1005];
long long int C[1005];

int main()
{
	ifstream inp("metin.gir");
	ofstream oup("metin.cik");
	vector<long long int> w;
	long long int N,M;
	
	inp >> N >> M;
	string s;
	for(int i=0;i<M;i++)
	{
		inp >> s;
		w.push_back(s.length());
	}
	
	for(int i=0;i<M;i++)
		C[i] = INF;
	long long int size;
	for(int i=0;i<M;i++)
	{
		size=0L;
		for(int j=i;j<M;j++)
		{
			size += w[j];
			if(size>N)
				lc[i][j] = INF;
			else
				lc[i][j] = (long long int)(N-size)*(N-size)*(N-size);
			size++;
		}
		cout << endl;
	}
	
	for(int i=0;i<M;i++)
	{
		long long int cost;
		for(int j=0;j<=i;j++)
		{
			cost = (long long int)(j>0?C[j-1]:0) + lc[j][i];
			if(cost < C[i])
				C[i] = cost;
		}
	}
	oup << C[M-1] << endl;
	return 0;
}

