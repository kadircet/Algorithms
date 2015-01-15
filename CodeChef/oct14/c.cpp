#include <iostream>
#include <cstdio>
#define MOD 1000000009ULL
using namespace std;

int T,N,M;
char point[100000];
char posit[100000];

int main()
{
	char col;
	int pos,last=-1,first=1000001;
	unsigned long long res,k;
	
	scanf("%d%c",&T,&col);
	while(T--)
	{
		scanf("%d%d%c",&N,&M,&col);
		for(int i=0;i<N;i++)
			posit[i] = point[i] = 0;
		last=-1,first=1000001;
		
		for(int i=0;i<M;i++)
		{
			scanf("%c%d", &col, &pos);
			//cout << "HOP" << col << ' ' << pos << endl;
			point[pos-1] = col;
			last = max(pos-1, last);
			first = min(pos-1, first);
			scanf("%c", &col);
		}
		
		res=1, k=0;
		for(int i=first;i<=last;i++)
		{
			if(point[i])
			{
				posit[i]=point[i];
				if(k>0 && posit[i]!=posit[i-1])
					res = (res*k)%MOD;
				k=0;
			}
			else
				posit[i]=posit[i-1];
			k++;
		}
		cout << res << endl;
	}
	
	return 0;
}

