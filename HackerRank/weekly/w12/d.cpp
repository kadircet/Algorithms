#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int N,Q;
int a[50001], b[50001];
vector<int> occur[50001];
vector<int> E;
vector<int> edges[50001];
bool visited[50001];

void dfs(int cur)
{
	visited[cur]=true;
	
	E.push_back(cur);
	for(int i=0;i<edges[cur].size();i++)
	{
		if(!visited[edges[cur][i]])
		{
			dfs(edges[cur][i]);
			E.push_back(cur);
		}
	}
}

long long cons[400000], coef[400000];
long long na[400000], nb[400000];
bool sign[400000];
void build(int n, int l, int r)
{
	if(l==r)
	{
		sign[n] = false;
		cons[n] = nb[n] = b[l];
		coef[n] = na[n] = a[l];
		return;
	}
	
	int mid = (l+r)/2;
	build(2*n, l, mid);
	build(2*n+1, mid+1, r);
	
	sign[n] = false;
	cons[n] = (cons[2*n+1] + ((coef[2*n+1]*cons[2*n])%MOD))%MOD;
	coef[n] = (coef[2*n]*coef[2*n+1])%MOD;
}

void update(int n, int t, int a, int b)
{
	sign[n] = !sign[n];
	coef[n] = powm(a, t);
	cons[n] = ((b*(coef[n]-1)%MOD)*powm(a-1, MOD-2))%MOD;
	nb[n] = b;
	na[n] = a;
}

void push(int n, int l, int r)
{
	int mid = (l+r)/2;
	if(sign[n])
	{
		update(2*n, mid-l+1, na[n], nb[n]);
		update(2*n, r-mid, na[n], nb[n]);
	}
}

void update(int n, int l, int r, int ql, int qr, int a, int b)
{
	if(ql<=l && r<=qr)
	{
		update(n, r-l+1, a, b);
		return;
	}
	
	push(n, l, r);
	int mid = (l+r)/2;
	if(ql<=mid)
		upd(2*n, l, mid, ql, qr, a, b);
	if(mid+1<=qr)
		upd(2*n, mid+1, r, ql, qr, a, b);
	
	cons[n] = (cons[2*n+1] + ((coef[2*n+1]*cons[2*n])%MOD))%MOD;
	coef[n] = (coef[2*n]*coef[2*n+1])%MOD;
}

long long getCoef(int n, int l, int r, int ql, int qr)
{
	long long res=1;
	if(ql<=l && r<=qr)
		return coef[n];
		
	push(n, l, r);
	int mid = (l+r)/2;
	if(ql<=mid)
		res = (res*getCoef(n, l, mid, ql, qr))%MOD;
	if(mid+1<=qr)
		res = (res*getCoef(n, mid+1, r, ql, qr))%MOD;
	
	return res;
}

long long getCons(int n, int l, int r, int ql, int qr)
{
	long long res=0;
	if(ql<=l && r<=qr)
		return cons[n];
		
	push(n, l, r);
	int mid = (l+r)/2;
	if(ql<=mid)
		res = (getCoef(n, mid+1, r, ql, qr)*getCons(n, l, mid, ql, qr))%MOD;
	if(mid+1<=qr)
		res = (res+getCons(n, mid+1, r, ql, qr))%MOD;
	
	return res;
}

long long query(int n, int l, int r, int ql, int qr, int x)
{
	return ((getCoef(n, l, r, ql, qr)*x)%MOD + getCons(n,l,r,ql,qr))%MOD;
}

int main()
{
	int u,v,qa,qb,x,t;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> a[i] >> b[i];
	
	for(int i=1;i<N;i++)
	{
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	dfs(1);
	for(int i=0;i<E.size();i++)
		occur[E[i]].push_back(i);
			
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> t >> u >> v;
		if(t==1)
		{
			cin >> qa >> qb;
		}
		else
		{
			cin >> x;
			query(
		}
	}
	return 0;
}

