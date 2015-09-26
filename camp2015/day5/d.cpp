#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int ord[128];

bool comp(const char a, const char b)
{
	return ord[a]>=ord[b];
}

int main()
{
	int n;
	string s,l="",r="",m="";
	cin >> n >> s;
	ord['I']=1;
	ord['V']=5;
	ord['X']=10;
	ord['L']=50;
	ord['C']=100;
	ord['D']=500;
	ord['M']=1000;
	sort(s.begin(), s.end(), comp);
	
	int used=1;
	m=s[0];
	while(s[used]==s[0])
	{
		m+=s[0];
		used++;
	}
	n-=ord[s[0]]*used;
	while(used<s.size())
	{
		if(n>0)
		{
			r+=s[used];
			n-=ord[s[used]];
			used++;
		}
		else
		{
			l+=s[used];
			n+=ord[s[used]];
			used++;
		}
	}
	if(n==0)
		cout << l << m << r << endl;
	else
		cout << "NO" << endl;
	return 0;
}

