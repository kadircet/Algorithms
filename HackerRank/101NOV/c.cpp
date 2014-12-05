#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100000];
bool visited[100000];
int maxDist[100000];
int maxDidx[100000];
int M,midx;

void dfs(int cur, int p, int d)
{
	if(d>M)
	{
		M=d;
		midx=cur;
	}
	for(int i=0;i<g[cur].size();i++)
		if(g[cur][i]!=p)
			dfs(g[cur][i], cur, d+1);
}

int main()
{
	int n,m,k,x,y,v;
	cin >> n >> m;
	for(int i=1;i<n;i++)
	{
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	
	for(int i=0;i<m;i++)
	{
		unsigned long long res=0;
		cin >> v >> k;
		M=0;
		if(maxDist[v-1]==0)
		{
			dfs(v-1, v-1, 0);
			maxDist[v-1] = M;
			maxDidx[v-1] = midx;
		}
		res += maxDist[v-1];
		v = maxDidx[v-1];
		
		M=0;
		if(maxDist[v]==0)
		{
			dfs(v, v, 0);
			maxDist[v] = M;
			maxDidx[v] = midx;
		}
		res += (k-1)*maxDist[v];
		cout << res << endl;
	}
}

