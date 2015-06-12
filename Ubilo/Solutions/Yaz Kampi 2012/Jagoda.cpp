#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

typedef struct _day
{
	int n,s;
}day;
int bowl[1000];
int N,M,K;
int pt[100000];

int getBowl(int n)
{
	return n/K;
}

int getStart(int n)
{
	return K*n;
}

int getEnd(int n)
{
	if (K*n+K-1>=N)
		return N-1;
	return K*n+K-1;
}

int main()
{
	ifstream inp("jagoda.gir");
	ofstream oup("jagoda.cik");
	
	inp >> N >> M;
	day today;
	K = (int)sqrt(N);
	for(int i=0;i<M;i++)
	{
		inp >> today.n >> today.s;
		today.s--;
		int put = 0;
		int lastPut = today.s + today.n - 1;
		int sBowl = getBowl(today.s);
		bool carry = false;
		
		if(getEnd(sBowl) <= lastPut && today.s%K!=0)
		{
			/*for(int j=getStart(sBowl);j<today.s;j++)
			{
				carry =true;
				if(pt[j]==0)
				{
					carry = false;
					break;
				} 
			}
			if(carry)
			{
				for(int j=getStart(sBowl);j<today.s;j++)
					pt[j]--;
				put += ++bowl[sBowl];
				today.n -= getEnd(sBowl) + 1 - today.s;
				today.s = getEnd(sBowl) + 1;
			}
			else
			{*/
				for(int j=today.s;j<=getEnd(sBowl);j++)
				{
					put += ++pt[j];
					today.n--;
					today.s++;
				}
			//}
		}
		
		cout << "before: " << put << endl;
		
		if(today.n>=K)
		{
			int lastBowl;
			if(lastPut == N-1 || (lastPut+1)%K==0)
				lastBowl = getBowl(lastPut);
			else
				lastBowl = getBowl(lastPut) - 1;
			for(int j=getBowl(today.s);j<=lastBowl;j++)
				put += ++bowl[j];
			today.s = getEnd(lastBowl) + 1;
		}
		
		cout << "bowl: " << put << endl;
		
		for(int j=today.s;j<=lastPut;j++)
			put += ++pt[j];
		cout << put << endl;
		oup << put << endl;
	}
	
	return 0;
}

