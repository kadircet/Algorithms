#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> values;
int signs[4];
int main()
{
	int N,M,s,t;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> M;
		values.push_back(M);
	}
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> t >> s;
		signs[s-1] = t;
	}
	
	sort(values.begin(), values.end());
	do
	{
		int m=-1;
		int sum=0;
		for(int i=0;i<N;i++)
		{
			sum += values[i];
			
		}
	}while(next_permutation(values));
}

