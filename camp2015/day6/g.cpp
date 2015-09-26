#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

vector<int> colors;
struct node
{
	unsigned int has[8];
	int c;
	
	node()
	{
		c=0;
		for(int i=0;i<8;i++)
			has[i]=0;
	}
} T[100000*4];

void build(int c, int l, int r)
{
	if(l==r)
	{
		T[c].has[colors[l-1]/32]=(1<<(colors[l-1]%32));
		T[c].c=1;
		return;
	}
	
	build(2*c, l, (l+r)/2);
	build(2*c+1, (l+r)/2+1, r);
	
	for(int i=0;i<8;i++)
	{
		T[c].has[i]=T[2*c].has[i] | T[2*c+1].has[i];
		T[c].c+=__builtin_popcount(T[c].has[i]);
	}
}

node query(int c, int l, int r, int ql, int qr)
{
	if(ql<=l && r<=qr)
		return T[c];
	
	node res,tmp;
	int mid = (l+r)/2;
	if(ql<=mid)
		res=query(2*c, l, mid, ql, qr);
	if(mid<qr)
	{
		tmp=query(2*c+1, mid+1, r, ql, qr);
		for(int i=0;i<8;i++)
			res.has[i]=res.has[i] | tmp.has[i];
	}
	res.c=0;
	for(int i=0;i<8;i++)
		res.c+=__builtin_popcount(res.has[i]);
	return res;
}

int main()
{
	int n,k;
	cin >> n >> k;
	colors.resize(n);
	for(int i=0;i<n;i++)
		cin >> colors[i];
	
	int x,y;
	build(1, 1, n);
	for(int i=0;i<k;i++)
	{
		cin >> x >> y;
		cout << query(1, 1, n, x, y).c << endl;
	}
	return 0;
}

