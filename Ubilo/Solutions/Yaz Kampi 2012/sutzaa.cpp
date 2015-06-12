#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int D[4001][4001];
vector<int> milks, g1, g2;

int findBestPart(int a, int b)
{
	if(D[a][b] != -1)
		return D[a][b];
	
	if(a>b)
	{
		int cost;
		for(vector<int>::iterator it=g1.begin();it!=g1.end();it++)
		{
			int elem = *it;
			g1.erase(it);
			g2.push_back(elem);
			cost = findBestPart(a-elem, b+elem);
			g2.pop_back();
			if(cost>D[a][b] || D[a][b]==-1)
				D[a][b] = cost;
			cost = findBestPart(a-elem, b);
			if(cost>D[a][b] || D[a][b]==-1)
				D[a][b] = cost;
			g1.push_back(elem);
		}			
	}
	else
	{
		int cost;
		for(vector<int>::iterator it=g2.begin();it!=g2.end();it++)
		{
			int elem = *it;
			g2.erase(it);
			g1.push_back(elem);
			cost = findBestPart(a+elem, b-elem);
			g1.pop_back();
			if(cost>D[a][b] || D[a][b]==-1)
				D[a][b] = cost;
			cost = findBestPart(a, b-elem);
			if(cost>D[a][b] || D[a][b]==-1)
				D[a][b] = cost;
			g2.push_back(elem);
		}	
	}
	return D[a][b];
}

int main()
{
	ifstream inp("sut.gir");
	ofstream oup("sut.cik");
	bool **part;
	int N,S=0;
	
	inp >> N;
	int m;
	for(int i=0;i<N;i++)
	{
		inp >> m;
		milks.push_back(m);
		g1.push_back(m);
		S+=m;
	}
	
	int s1, s2;
	s1=S;s2=0;
	
	for(int i=0;i<4001;i++)
		for(int j=0;j<4001;j++)
			D[i][j] = -1;
	for(int i=0;i<=S;i++)
		D[i][i] = i;
	cout << findBestPath(s1, 0) << endl;
	for(int i=0;i<=S;i++,cout << endl)
		for(int j=0;j<=S;j++)
			cout << D[i][j] << " ";
	
	return 0;
}

