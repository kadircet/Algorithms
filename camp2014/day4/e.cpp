#include <iostream>
using namespace std;

bool pos[1000001];
int no[1000001];

int rev(int n, int x)
{
	int res=0;
	for(int i=0;(1<<i)<=n;i++)
		if((x&(1<<i))==0)
			res+=1<<i;
	return res;
}

int main()
{
	int n,q=0;
	cin >> n;
	if(n==1)
	{
		cout << 2 << endl;
		cout << "1 0" << endl;
		return 0;
	}
	int m=0;
	for(int i=0;(1<<i)<=n;i++)m=1<<i;
	for(int i=n-1;i>=0;i--)
	{
		int x=rev(n, i+1);
		if(x>n)
			x-=m;
		while(x<0 || pos[x])
		{
			x+=m;
			m|=m>>1;
			x-=m;
		}
		if(x==0)
			q=i+1;
		pos[x]=1;
		no[i]=x;
	}
	unsigned long long res = q;
	for(int i=1;i<=n;i++)
		res+=no[i-1]^i;
	cout << res << endl;
	if(q!=0)
		cout << q;
	else
		cout << 0;
	for(int i=0;i<n;i++)
		cout << ' ' << no[i];
	cout << endl;
	
	return 0;
}


