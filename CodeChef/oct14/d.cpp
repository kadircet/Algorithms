#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	int R,G,B,M;
	cin >> T;
	
	long long maxr=0, maxg=0, maxb=0, tmp, best;
	while(T--)
	{
		maxr=0, maxg=0, maxb=0;
		cin >> R >> G >> B >> M;
		for(int i=0;i<R;i++)
		{
			cin >> tmp;
			maxr=max(tmp, maxr);
		}
		for(int i=0;i<G;i++)
		{
			cin >> tmp;
			maxg=max(tmp, maxg);
		}
		for(int i=0;i<B;i++)
		{
			cin >> tmp;
			maxb=max(tmp, maxb);
		}
		
		best = max(max(maxr, maxg), maxb);
		long long cm;
		for(int i=0;i<M;i++)
		{
			long cr = max(max(maxr, maxg), maxb);
			if(cr==maxr)
			{
				maxr/=2;
				//maxg++;
				//maxb++;
			}
			else if(cr==maxg)
			{
				//maxr++;
				maxg/=2;
				//maxb++;
			}
			else if(cr==maxb)
			{
				//maxr++;
				//maxg++;
				maxb/=2;
			}
			//cout << maxr << ' ' << maxg << ' ' << maxb << endl;
			cm = max(max(maxr, maxg),maxb);
			best = min(best, cm);
		}
		cout << best << endl;
	}
	
	return 0;
}

