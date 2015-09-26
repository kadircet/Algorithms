#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string s;

int mem[100001][2][2];

int f(int n, bool shifting, bool shifted)
{
	if(mem[n][shifting][shifted])
		return mem[n][shifting][shifted];
	if(n==0)
		return 0;
		
	if(shifted)
	{
		if(shifting)
			return mem[n][shifting][shifted]=min(f(n-1, 0, 1),f(n-1, 1, 1))+(s[n-1]=='.');
		return mem[n][shifting][shifted]=f(n-1, 0, 1)+(s[n-1]=='*');
	}
	return mem[n][shifting][shifted]=min(f(n-1, 0, 0)+(s[n-1]=='*'), f(n-1, 1, 1)+(s[n-1]=='.'));
}

int dot[100001],star[100001],shift[100001];

int main()
{
	int n;
	cin >> n >> s;
	dot[1]=s[0]=='.';
	star[1]=s[0]=='*';
	for(int i=2;i<=n;i++)
	{
		dot[i] = dot[i-1]+(s[i-1]=='.');
		star[i] = star[i-1]+(s[i-1]=='*');
	}
		
	int l=0,r=2,best=0,bl,br;
	while(s[l]=='.')l++;
	l++;
	r=l+1;
	while(l<r && r<n)
	{
		while(l<=n && l<r && s[l-1]=='.')l++;
		int c=(star[r]-star[l-1])-(dot[r]-dot[l-1]);
		if(c>best && l<r)
		{
			best=c;
			bl=l;
			br=r;
		}
		while(l<r && (star[r]-star[l-1])<(dot[r]-dot[l-1]))
			l++;
		r++;
	}
	int res=0;
	if(best>0)
	{
		res=2+dot[br]-dot[bl-1]+star[bl-1]+star[n]-star[br];
		cout << res << endl;
		cout << bl << endl;
		cout << "Shift+" << br << endl;
		for(int i=0;i<bl-1;i++)
			if(s[i]=='*')
				cout << "Ctrl+" << (i+1) << endl;
		for(int i=bl;i<br;i++)
			if(s[i]=='.')
				cout << "Ctrl+" << (i+1) << endl;
		for(int i=br;i<n;i++)
			if(s[i]=='*')
				cout << "Ctrl+" << (i+1) << endl;
	}
	else
	{
		bool f=true;
		res=star[n];
		cout << res << endl;
		for(int i=0;i<n;i++)
			if(s[i]=='*')
			{
				if(f)
					cout << i+1 << endl;
				else
					cout << "Ctrl+" << i+1 << endl;
			}
	}
	return 0;
}
