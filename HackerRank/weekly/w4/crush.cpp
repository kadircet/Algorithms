#include <iostream>
using namespace std;

unsigned int tree[40000000];
unsigned int lazy[40000000];

struct segment
{
	unsigned int l,r;
};

long update(int node, segment nint, segment range, int val)
{
	//cout << node << endl;
	if(range.l<=nint.l && nint.r<=range.r)
	{
		lazy[node] += val;
		return tree[node] + lazy[node];
	}
	
	segment left;
	left.l = nint.l;
	left.r = (nint.r+nint.l)/2;
	
	long L=0,R=0;
	
	if(range.l<=left.r)
		L = update(2*node, left, range, val);
	
	segment right;
	right.l = left.r+1;
	right.r = nint.r;
	if(right.l<=range.r)
		R = update(2*node+1, right, range, val);
	
	return (tree[node]=max(L,R))+lazy[node];
}

long query(int node, segment nint, segment range)
{
	//cout << node << endl;
	if(nint.l==nint.r)
	{
		tree[node] += lazy[node];
		lazy[node] = 0;
		return tree[node];
	}
	
	segment left;
	left.l = nint.l;
	left.r = (nint.r+nint.l)/2;
	
	long L=0,R=0;
	
	if(range.l<=left.r)
		L = query(2*node, left, range);
	
	segment right;
	right.l = left.r+1;
	right.r = nint.r;
	if(right.l<=range.r)
		R = query(2*node+1, right, range);
	
	tree[node] = max(L,R) + lazy[node];
	lazy[2*node] += lazy[node];
	lazy[2*node+1] += lazy[node];
	lazy[node] = 0;
	return tree[node];
}

int main()
{
	int N,M,a,b,k;
	
	cin >> N;
	segment root, tmp;
	root.l=1,root.r=N;
	
	cin >> M;
	while(M--)
	{
		cin >> a >> b >> k;
		tmp.l = a, tmp.r = b;
		
		update(1, root, tmp, k);
	}
	
	cout << query(1, root, root) << endl;
	return 0;
}

