#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

vector<string> inp;

int getCount(const string &a, int n, char c)
{
	int res=0;
	for(int i=a.size()-n-1;i>=0;i--)
		if(a[i]==c)
			res++;
		else
			break;
	return res;
}

bool mysort(const string &s1, const string &s2, char a, char b, char c, int n)
{
	if(s1[n]!=s2[n])
		return s1[n]==a;
	if(s1[n]==a)
		return mysort(s1,s2,a,c,b,n-1);
	return mysort(s1,s2,c,b,a,n-1);
}

bool helper(const string &a, const string &b)
{
	return mysort(a,b,'A','B','C',a.size()-1);
}

int main()
{
	int n,m;
	cin >> n >> m;
	inp.resize(m);
	for(int i=0;i<m;i++)
		cin >> inp[i];
	sort(inp.begin(), inp.end(), helper);
	
	for(int i=0;i<m;i++)
		cout << inp[i] << endl;
		
	return 0;
}

