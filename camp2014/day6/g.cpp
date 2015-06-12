#include <iostream>
using namespace std;

int digits[10], d;
bool deleted[10];
int best=1000000005, nd=0;
int N, K;

void gen(int rem, int first)
{
	if(rem<0)
		return;
		
	if(K-rem>=nd && digits[first]!=0)
	{
		int res=0;
		for(int i=first;i<d;i++)
			if(!deleted[i])
			{
				res*=10;
				res+=digits[i];
			}
		if(res==0)
			return;
		if(best>res)
			best=res, nd=K-rem;
	}
	
	int na=first+1;
	while(deleted[na])na++;
	if(na>=d)
		return;
	for(int i=first;i<d;i++)
		if(!deleted[i])
		{
			deleted[i]=true;
			gen(rem-1, i==first?na:first);
			deleted[i]=false;
		}
}

int main()
{
	cin >> N >> K;
	
	while(N>0)
	{
		digits[d++] = N%10;
		N/=10;
	}
	int tmp;
	for(int i=0;i<d/2;i++)
	{
		tmp=digits[i];
		digits[i]=digits[d-i-1];
		digits[d-i-1]=tmp;
	}
	
	gen(K, 0);
	cout << best << endl;
	
	return 0;
}


