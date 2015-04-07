#include <iostream>
using namespace std;

long long x[150000], p[150000];
long long ex[150000];
struct node
{
	long long p, s, sub, sum;
} tree[1000000], res;

void build(int n, int l, int r)
{
	if(l==r)
	{
		tree[n].p=tree[n].s=tree[n].sub=max(0LL, ex[l]);
		tree[n].sum=ex[l];
	}
	else
	{
		int m = (l+r)/2;
		build(2*n, l, m);
		build(2*n+1, m+1, r);
		tree[n].sum=tree[2*n].sum+tree[2*n+1].sum;
		tree[n].p=max(tree[2*n].p, tree[2*n].sum+tree[2*n+1].p);
		tree[n].s=max(tree[2*n+1].s, tree[2*n].s+tree[2*n+1].sum);
		tree[n].sub=max(tree[2*n].s+tree[2*n+1].p, max(tree[2*n].sub, tree[2*n+1].sub));
	}
}

void query(int n, int l, int r, int ql, int qr)
{
	if(ql<=l && r<=qr)
	{
		if(res.sub==-1)
			res=tree[n];
		else
		{
			res.sub = max(res.sub, max(tree[n].sub, res.s+tree[n].p));
			res.p = max(res.p, res.sum+tree[n].p);
			res.s = max(tree[n].s, res.s+tree[n].sum);
			res.sum += tree[n].sum;
		}
		return;
	}
		
	int m = (l+r)/2;
	if(m>=ql)
		query(2*n, l, m, ql, qr);
	if(m+1<=qr)
		query(2*n+1, m+1, r, ql, qr);
}

int main()
{
	int n,m,c;
	int a,b;
	cin >> n >> m >> c;
	for(int i=0;i<n;i++)
		cin >> x[i];
	for(int i=1;i<n;i++)
		cin >> p[i];
	long sum=0;
	for(int i=1;i<n;i++)
		ex[i] = (x[i]-x[i-1])*50-c*p[i];
	build(1, 1, n-1);
	
	long long resul=0;
	for(int i=0;i<m;i++)
	{
		res.sub=-1;
		cin >> a;
		cin >> b;
		query(1, 1, n-1, a, b-1);
		resul += res.sub;
	}
	
	cout << fixed;
	cout << resul/100.0 << endl;
	
	return 0;
}

