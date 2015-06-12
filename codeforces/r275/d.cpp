#include <iostream>
using namespace std;

int q[100000], l[100000], r[100000];
int n,m;
int sum[100000], a[100000], t[400000];

void construct(int n, int l, int r)
{
	if(l==r)
	{
		t[n] = a[l-1];
		return;
	}
	
	construct(2*n, l, (l+r)/2);
	construct(2*n+1, (l+r)/2+1, r);
	t[n] = t[2*n] & t[2*n+1];
}

int query(int n, int l, int r, int ql, int qr)
{
	if(r<ql || qr<l)
		return (1<<30)-1;
	if(ql<=l && r<=qr)
		return t[n];
	
	return query(2*n, l, (l+r)/2, ql, qr) & query(2*n+1, (l+r)/2+1, r, ql, qr);
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> l[i] >> r[i] >> q[i];
	
	for(int mask=1;mask<(1<<30);mask<<=1)
	{
		for(int i=0;i<n;i++)sum[i]=0;
		for(int i=0;i<m;i++)
			if(q[i]&mask)
				sum[l[i]-1]++, sum[r[i]]--;
		for(int i=0;i<n;i++)
		{
			if(i>0)
				sum[i] += sum[i-1];
			
			if(sum[i])
				a[i] |= mask;
		}
	}
	construct(1, 1, n);
	for(int i=0;i<m;i++)
		if(query(1, 1, n, l[i], r[i])!=q[i])
		{
			cout << "NO" << endl;
			return 0;
		}
		
	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
