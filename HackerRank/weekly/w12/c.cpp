#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> edges[1000001];
set<int> noin;
bool found[1000001];
int ind[1000001];

int main()
{
	int n,k,t,l,node;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> k;
		for(int j=0;j<k;j++)
		{
			cin >> t;
			if(j>0)
			{
				ind[t]++;
				edges[l].push_back(t);
			}
			l=t;
			found[t]=true;
		}
	}
	
	for(int i=0;i<1000001;i++)
		if(found[i] && !ind[i])
			noin.insert(i);
	
	set<int>::iterator it;
	while(!noin.empty())
	{
		it = noin.begin();
		node = *it;
		noin.erase(it);
		
		cout << node << ' ';
		for(int i=0;i<edges[node].size();i++)
		{
			ind[edges[node][i]]--;
			if(ind[edges[node][i]]==0)
				noin.insert(edges[node][i]);
		}
	}
	cout << endl;
	
	return 0;
}
