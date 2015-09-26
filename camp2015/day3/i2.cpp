#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

map<pair<int,int>,vector<int> > nodes;
vector<pair<int,int> > edges;
bool used[1000];

int main()
{
	//ios_base::sync_with_stdio(false);
	pair<int,int> e,e2,e3;
	int n,m,x,y,z;
	map<pair<int,int>,vector<int> >::iterator it,it1,it2;
	vector<int> t;
	unsigned long long int res=0;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++)
	{
		//cin >> x >> y >> z;
		scanf("%d%d%d", &x, &y, &z);
		e.first=x-1;
		e.second=y-1;
		if(e.first>e.second)
			swap(e.first, e.second);
		if(nodes.find(e)==nodes.end())
		{
			nodes[e]=vector<int>(3);
			edges.push_back(e);
			used[x-1]=used[y-1]=true;
		}
		nodes[e][z-1]++;
	}
	m=edges.size();
	for(int i=0;i<m;i++)
	{
		e=edges[i];
		it=nodes.find(e);
		t=it->second;
		for(int j=0;j<n;j++)
		{
			if(j==e.first || j==e.second || !used[j])
				continue;
			e2.first=e.first;
			e2.second=j;
			if(e2.first>e2.second)
				swap(e2.first, e2.second);
			e3.first=e.second;
			e3.second=j;
			if(e3.first>e3.second)
				swap(e3.first, e3.second);
			it1=nodes.find(e2);
			it2=nodes.find(e3);
			if(it1!=nodes.end() && it2!=nodes.end())
				res += 
t[0]*it1->second[1]*it2->second[2]+t[0]*it1->second[2]*it2->second[1]+
						
t[1]*it1->second[0]*it2->second[2]+t[1]*it1->second[2]*it2->second[0]+
						
t[2]*it1->second[0]*it2->second[1]+t[2]*it1->second[1]*it2->second[0];
		}
		nodes.erase(it);
	}
	cout << res << endl;
	return 0;
}


