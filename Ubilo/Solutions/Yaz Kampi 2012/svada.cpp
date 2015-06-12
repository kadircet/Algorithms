#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,T;
int max_A, min_D = 9999999;
vector<int> A,B,C,D;

int calcHarvest(int t)
{
	int H = 0;
	for(int i=0;i<N;i++)
	{
		if(t<A[i])
			continue;
		H += 1 + (t-A[i])/B[i];
	}
	return H;
}

int calcOpen(int t)
{
	int H = 0;
	for(int i=0;i<M;i++)
	{
		if(t<C[i])
			continue;
		H += 1 + (t-C[i])/D[i];
	}
	return H;
}

int main()
{
	ifstream inp("svada.gir");
	ofstream oup("svada.cik");
	inp >> T >> N;
	int s,c;
	for(int i=0;i<N;i++)
	{
		inp >> s >> c;
		if(s>max_A)
			max_A = s;
		A.push_back(s);
		B.push_back(c);
	}
	inp >> M;
	for(int i=0;i<M;i++)
	{
		inp >> s >> c;
		if(c<min_D)
			min_D = c;
		C.push_back(s);
		D.push_back(c);
	}
	
	int lastT = -1;
	int t = T/2;
	int u = T;
	int l = 0;
	while(true)
	{
		if(l+1>=u)
			break;
		if(calcHarvest(t)>calcOpen(T-t))
			u = t;
		else
			l = t;
		t = (u+l)/2;
	}
	oup << t << endl;
	return 0;
}

