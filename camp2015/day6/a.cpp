#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool comp(const string &s1, const string &s2, char a, char b, char c, int n)
{
	if(s1[n]!=s2[n])
		return s1[n]==a;
	if(s1[n]==a)
		return comp(s1,s2,a,c,b,n-1);
	return comp(s1,s2,c,b,a,n-1);
}

bool poss(const string &s1, char a, char b, char c, int n)
{
	if(n==0)
		return s1[n]!=c;
	if(s1[n]==a)
		return poss(s1, a,c,b,n-1);
	if(s1[n]==b)
		return poss(s1, c,b,a,n-1);
	return false;
}

int main()
{
	int n;
	string s,A="",B="";
	cin >> n >> s;
	for(int i=0;i<n;i++)
	{
		A+='A';
		B+='B';
	}
	//if(comp(A, s, 'A','B','C',n-1) && comp(s, B, 'A','B','C',n-1))
	if(poss(s, 'A','B','C',n-1))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
