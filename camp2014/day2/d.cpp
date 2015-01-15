#include <iostream>
#include <map>
using namespace std;

int N;
int count[300000];
map<int, int> rank;
int front[300000];

int main()
{
	cin >> N;
	
	int a,b,d=0;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		if(rank.find(a)==rank.end())
			rank[a] = d++;
		if(rank.find(b)==rank.end())
			rank[b] = d++;

		count[rank[a]]++;
		if(a!=b)
			count[rank[b]]++;
		
		front[rank[a]]++;
	}
	
	int best=-1;
	for(int i=0;i<d;i++)
	{
		if(2*count[i]>=N)
		{
			if(2*front[i]>=N)
			{
				best=0;
				break;
			}
			
			int moves = (N+1)/2 - front[i];
			if(best>moves || best==-1)
				best=moves;
		}
	}
	
	cout << best << endl;
	return 0;
}

