#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<int, int> pos[5];
vector<int> A;

bool comp(const int a, const int b)
{
	int count=0;
	for(int i=0;i<5;i++)
		count += pos[i][a] < pos[i][b];
	return count > 2;
}

int main()
{
	int N,t;
	cin >> N;
	A.resize(N);
	for(int i=0;i<5;i++)
		for(int j=0;j<N;j++)
		{
			cin >> t;
			pos[i][t] = j;
			A[j]=t;
		}
	
	sort(A.begin(), A.end(), comp);
	for(int i=0;i<N;i++)
		cout << A[i] << endl;
	return 0;
}

