#include <iostream>
#include <fstream>
using namespace std;

int oldbest[350];
int best[350];
int N;

int main()
{
	ifstream inp("triangle.gir");
	ofstream oup("triangle.cik");
	inp >> N;
	int p,q;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			inp >> p;
			if(j==0)
			{
				if(i==0)
					q = p;
				else
					q=oldbest[0]+p;
			}
			else if(j==i)
				q=oldbest[j-1]+p;
			else
			{
				q=oldbest[j-1]+p;
				if(oldbest[j]+p>q)
					q=oldbest[j]+p;
			}
			best[j] = q;
		}
		for(int j=0;j<=i;j++)
			oldbest[j] = best[j];
	}
	p=best[0];
	for(int i=1;i<N;i++)
		if(best[i]>p)
			p=best[i];
	oup << p << endl;
	return 0;
}

