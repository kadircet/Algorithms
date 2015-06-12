#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long int K;
int N,d;
int arr[100000];

class node
{
public:
	vector<int> v;
	node *l, *r;
	
	node(int n, int a[]);
	~node();
	int getFunc(int ql, int qr, int x, int (*f)(node*, int));
	int lt(int l, int r, int x);
	int eq(int l, int r, int x);
	int gt(int l, int r, int x);
};

int getLt(node *n, int x)
{
	return lower_bound(n->v.begin(), n->v.end(), x) - n->v.begin();
}

int getGt(node *n, int x)
{
	return n->v.end() - upper_bound(n->v.begin(), n->v.end(), x);
}

int getEq(node *n, int x)
{
	pair<vector<int>::iterator,vector<int>::iterator> r;
	r = equal_range(n->v.begin(), n->v.end(), x);
	return r.second - r.first;
}

node::node(int n, int a[]):v(n),l(NULL),r(NULL)
{
	if(n==1)
		v[0] = a[0];
	else
	{
		l = new node(n/2, a);
		r = new node(n-n/2, a+n/2);
		merge(l->v.begin(), l->v.end(), r->v.begin(), r->v.end(), v.begin());
	}
}
	
node::~node()
{
	delete l;
	delete r;
}

int node::getFunc(int ql, int qr, int x, int (*f)(node*, int))
{
	ql=max(0,ql), qr=min(qr,(int)v.size());
	if(ql>=qr)
		return 0;
	else if(ql==0 && qr==v.size())
		return f(this, x);
	else
		return l->getFunc(ql, qr, x, f) + r->getFunc(ql-l->v.size(), qr-l->v.size(), x, f);
}

int node::lt(int l, int r, int x)
{
	return getFunc(l, r, x, getLt);
}

int node::gt(int l, int r, int x)
{
	return getFunc(l, r, x, getGt);
}
	
int node::eq(int l, int r, int x)
{
	return getFunc(l, r, x, getEq);
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> arr[i];
		
	node *root = new node(N, arr);
	
	int l=N-2, r=N-1;
	unsigned long long inv=0, res=0;
	
	for(int i=0;i<N;i++)
		inv += root->gt(0, i+1, arr[i]);
	
	while(l>=0 && r>0)
	{
		if(inv<=K)
		{
			res+=l+1;
			r--;
			if(r==l)
				l--;
			else
				inv += root->gt(0, l+1, arr[r])+root->lt(r, N, arr[r]);
		}
		else
		{
			inv -= root->gt(0, l, arr[l])+root->lt(r, N, arr[l]);
			l--;
		}
	}
	
	cout << res << endl;
	
	return 0;
}

