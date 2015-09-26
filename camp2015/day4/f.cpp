#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char res[1024],inp[1024];
int conv[128];
char invconv[]="0123456789ABCDEF";
string line;

int main()
{
	int n,m;
	cin >> n >> m;
	cout << m << endl;
	for(int i=0;i<10;i++)
		conv[i+'0']=i;
	for(int i=0;i<6;i++)
		conv[i+'A']=conv[i+'a']=i+10;
	for(int i=0;i<m;i++)
	{
		memset(res, 0, 1024);
		memset(inp, 0, 1024);
		int k=0,t=0;
		cin >> line;
		for(int j=0;j<line.size();j++)
		{
			t=conv[line[j]];
			k=0;
			while(t>0)
			{
				inp[(line.size()-1-j)*4+k++]=t%2;
				t/=2;
			}
		}
		for(int j=0;j<n;j++)
			if(inp[j]==1)
			{
				k=j;
				break;
			}
		res[0]=1;
		for(int j=n-1;j>k;j--)
			res[n-j]=inp[j];
		k=n-k;
		t=0;
		for(int j=0;j<k%4;j++)
		{
			t*=2;
			t+=res[j];
		}
		if(k%4)
			cout << invconv[t];
		int q=k%4;
		k&=~3;
		while(k!=0)
		{
			t=0;
			for(int j=0;j<4;j++)
			{
				t*=2;
				t+=res[j+q];
			}
			q+=4;
			k-=4;
			cout << invconv[t];
		}
		cout << endl;
	}
}

