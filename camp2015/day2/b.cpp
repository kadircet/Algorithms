#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int prefix[100001],suffix[100001];

int main()
{
	int n,res=0,sum;
	string number;
	cin >> n >> number;
	prefix[0] = number[0]-'0';
	for(int i=1;i<n+1;i++)
	{
		prefix[i] = prefix[i-1]+(number[i]-'0')*(i%2?-1:1);
		while(prefix[i]<0)
			prefix[i]+=11;
		prefix[i]%=11;
	}
	suffix[n] = (number[n]-'0')*(n%2?-1:1);
	for(int i=n-1;i>=0;i--)
	{
		suffix[i] = suffix[i+1]+(number[i]-'0')*(i%2?-1:1);
	}
	for(int i=0;i<n+1;i++)
	{
		sum=0;
		if(i>0)
			sum=prefix[i-1];
		if(i<n)
			sum+=suffix[i+1]*-1;
		while(sum<0)
			sum+=11;
		sum%=11;
		res+=sum==0;
	}
	cout << res << endl;
	return 0;
}
