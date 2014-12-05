#include <iostream>
#include <cmath>
using namespace std;

int T,N;
int D[100000];

int main()
{
	int curd, curv;
	cin >> T;
	while(T--)
	{
		curd=curv=-1;
		
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> D[i];
		
		for(int i=0;i<N;i++)
			if(curv==-1 && D[i]>0)
				curv=i;
			else if(curd==-1 && D[i]<0)
				curd=i;
		
		unsigned long long res=0, tmp;
		while(curd<N && curv<N)
		{
			tmp = D[curv];
			if(tmp>-D[curd])
				tmp=-D[curd];
			
			D[curv]-=tmp;
			D[curd]+=tmp;
			res+=tmp*abs(curd-curv);
			
			while(curv<N && D[curv]<=0)
				curv++;
			while(curd<N && D[curd]>=0)
				curd++;
		}
		cout << res << endl;
	}
	
	return 0;
}
