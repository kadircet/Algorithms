#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

unsigned long long int cnt[3001][3];
int id[1000][1000];
vector<pair<int,int> > edges;
int used[1000];

int main()
{
	//ios_base::sync_with_stdio(false);
	pair<int,int> e,e2,e3;
	int n,m,x,y,z;
	int i1,i2,i3;
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
		if(id[e.first][e.second]==0)
		{
			id[e.first][e.second]=edges.size()+1;
			edges.push_back(e);
		}
		cnt[id[e.first][e.second]][z-1]++;
		used[x-1]++;
		used[y-1]++;
	}
	m=edges.size();
	x=0;
	while(!used[x])
		x++;
	for(int i=0;i<m;i++)
	{
		e=edges[i];
		//it=nodes.find(e);
		i1=id[e.first][e.second];
		while(x<n && !used[x])x++;
		for(int j=x;j<n;j++)
		{
			if(j==e.first || j==e.second || used[j]==0)
				continue;
			e2.first=e.first;
			e2.second=j;
			if(e2.first>e2.second)
				swap(e2.first, e2.second);
			e3.first=e.second;
			e3.second=j;
			if(e3.first>e3.second)
				swap(e3.first, e3.second);
			i2 = id[e2.first][e2.second];
			i3 = id[e3.first][e3.second];
			if(i2>0 && i3>0)
				res += cnt[i1][0]*cnt[i2][1]*cnt[i3][2]+cnt[i1][0]*cnt[i2][2]*cnt[i3][1]+
						cnt[i1][1]*cnt[i2][0]*cnt[i3][2]+cnt[i1][1]*cnt[i2][2]*cnt[i3][0]+
						cnt[i1][2]*cnt[i2][0]*cnt[i3][1]+cnt[i1][2]*cnt[i2][1]*cnt[i3][0];
		}
		used[e.first]-=cnt[i1][2]+cnt[i1][1]+cnt[i1][0];
		used[e.second]-=cnt[i1][2]+cnt[i1][1]+cnt[i1][0];
		cnt[i1][0]=cnt[i1][1]=cnt[i1][2]=0;
	}
	//cout << res << endl;
	printf("%d\n", res);
	return 0;
}

