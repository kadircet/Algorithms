#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
	ifstream inp("huffman.gir");
	ofstream oup("huffman.cik");
	int N,T,l;
	priority_queue<int, vector<int>, greater<int> > L;
	T=0;
	
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> l;
		L.push(l);
		T+=l;
	}
	
	long long int cost=0;
	while(L.size()>1)
	{
		int i = L.top();
		L.pop();
		int j = L.top();
		L.pop();
		L.push(i+j);
		cost += i+j;
	}
	
	oup << cost << endl;
	return 0;
}

