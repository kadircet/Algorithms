#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
using namespace std;

set<int> poss[1001][7][7];
pair<int, int> doms[1001];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> doms[i].first >> doms[i].second;
		poss[0][doms[i].first][doms[i].second].push_back(i);
		poss[0][doms[i].second][doms[i].first].push_back(i);
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<7;j++)
			if(poss[i-1][doms[i].second][j].size()==i-1 && poss[i-1][doms[i].second][j].size().find(i))
	}
}
