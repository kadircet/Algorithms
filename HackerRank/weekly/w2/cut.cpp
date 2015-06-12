#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int> > childs;
vector<int> values, tree;
int N;
vector<bool> visited;

int calcTree(int node)
{
	//if(tree[node]==0)
	{
		tree[node]=values[node];
		for(int i=0;i<childs[node].size();i++)
			if(tree[childs[node][i]] == 0)
			{
				tree[node] += calcTree(childs[node][i]);
			}
	}
	return tree[node];
}

int main()
{
	cin >> N;
	visited.resize(N);
	values.resize(N),tree.resize(N);
	for(int i=0;i<N;i++)
		cin >> values[i];
		
	int f,s;
	childs.resize(N);
	for(int i=1;i<N;i++)
	{
		cin >> f >> s;
		childs[f-1].push_back(s-1);
		childs[s-1].push_back(f-1);
	}
	
	calcTree(0);
	
	int res=-1;
	int maxx=0;
	for(int i=0;i<N;i++)
		maxx = max(maxx, tree[i]);
	res = maxx;
	//maxx /= 2;
	
	for(int i=0;i<N;i++)
	{
		res = min(res, abs(maxx - 2 * tree[i]));		
	}
	cout << res << endl;
	
	return 0;
}

