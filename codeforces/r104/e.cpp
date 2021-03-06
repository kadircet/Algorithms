#include <iostream>
using namespace std;

int n4[4100000], n7[4100000];
int n47[4100000], n74[4100000];
int rev[4100000];
string s;

void build(int n, int l, int r)
{
	if(l==r)
	{
		if(s[l-1]=='4')
			n4[n]=1;
		else
			n7[n]=1;
		n47[n]=n74[n]=1;
		return;
	}
	
	build(2*n, l, (l+r)/2);
	build(2*n+1, (l+r)/2+1, r);
	
	n4[n] = n4[2*n]+n4[2*n+1];
	n7[n] = n7[2*n]+n7[2*n+1];
	n47[n] = max(n4[2*n]+n47[2*n+1], n47[2*n]+n7[2*n+1]);
	n74[n] = max(n7[2*n]+n74[2*n+1], n74[2*n]+n4[2*n+1]);
}

void upd(int n)
{
	rev[n] ^= 1;
	swap(n4[n], n7[n]);
	swap(n47[n], n74[n]);
}

void push(int n)
{
	if(rev[n])
	{
		upd(2*n);
		upd(2*n+1);
		rev[n]=0;
	}
}

void upd(int n, int l, int r, int ql, int qr)
{
	if(ql<=l && r<=qr)
	{
		upd(n);
		return;
	}
	
	push(n);
	int m = l+r>>1;
	if(ql<=m)
		upd(2*n, l, m, ql, qr);
	if(m<qr)
		upd(2*n+1, m+1, r, ql, qr);
	
	n4[n] = n4[2*n]+n4[2*n+1];
	n7[n] = n7[2*n]+n7[2*n+1];
	n47[n] = max(n4[2*n]+n47[2*n+1], n47[2*n]+n7[2*n+1]);
	n74[n] = max(n7[2*n]+n74[2*n+1], n74[2*n]+n4[2*n+1]);
}

int main()
{
	int n,m,l,r;
	cin >> n >> m;
	cin >> s;
	build(1, 1, n);
	for(int i=0;i<m;i++)
	{
		cin >> s;
		if(s=="count")
			cout << n47[1] << endl;
		else
		{
			cin >> l >> r;
			upd(1, 1, n, l, r);
		}
	}
}
