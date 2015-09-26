#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#define ds(x) (x%10+(x/10)%10+(x/100)%10)
using namespace std;

string s,inp;
int T[1000001];

void buildtable(string w)
{
	int pos=2,cnd=0;
	T[0]=-1;
	T[1]=0;
	
	while(pos<w.size())
	{
		if(w[pos-1]==w[cnd])
			T[pos++]=++cnd;
		else if(cnd>0)
			cnd=T[cnd];
		else
			T[pos++]=0;
	}
}

int search(string w)
{
	int m=0, i=0;
	while(m+i<s.size())
	{
		if(w[i]==s[m+i])
		{
			if(i==w.size()-1)
				return m;
			i++;
		}
		else
		{
			if(T[i]>-1)
			{
				m=m+i-T[i];
				i=T[i];
			}
			else
			{
				i=0;
				m++;
			}
		}
	}
	
	return -1;
}

int main()
{
	int n;
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			if(ds(i)==ds(j))
				s+="L";
			else
				s+="U";
	cin >> n >> inp;
	buildtable(inp);
	if((n=search(inp))!=-1)
	{
		cout.width(6);
		cout.fill('0');
		cout << n << endl;
	}
	else
		cout << "No solution" << endl;
	return 0;
}

