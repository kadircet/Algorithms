#include <iostream>
using namespace std;

int M[2001][2001], m[2001][2001];
int n,d,adj[2001][2001];
int a[2001];

int main()
{
	cin >> d >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
		
	int s,e;
	for(int i=1;i<n;i++)
	{
		cin >> s >> e;
		s--,e--;
		adj[s][e]=adj[e][s]=1;
	}
}

