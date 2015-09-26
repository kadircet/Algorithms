#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool bitsn[64];
bool res[64];

int main()
{
	unsigned long long int n;
	cin >> n;
	for(int i=0;n>0;i++,n>>=1)
		bitsn[i]=n%2;
	for(int i=63;i>=0;i--)
		if(bitsn[i])
		{
			res[i]=1;
			while(i>0)
			{
				res[i-1]=res[i]^bitsn[i-1];
				i--;
			}
			break;
		}
	
	unsigned long long int r=0,p2=1;
	for(int i=0;i<64;i++)
	{
		r+=res[i]*p2;
		p2*=2;
	}
	cout << r << endl;
	return 0;
}

