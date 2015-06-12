#include <iostream>
using namespace std;

int level(long long x)
{
	int l=0;
	while(x)
	{
		x/=2;
		l++;
	}
	return l;
}

bool parity=true;	//true->root is black
int main()
{
	string s;
	int Q,lx,ly;
	long long x,y;
	cin >> Q;
	while(Q--)
	{
		cin >> s;
		if(s=="Qi")
			parity=!parity;
		else
		{
			cin >> x >> y;
			lx=level(x), ly=level(y);
			int res=0;
			while(lx>ly)
			{
				res += (lx%2!=(parity^s=="Qb"));
				lx--;
				x/=2;
			}
			while(ly>lx)
			{
				res += (ly%2!=(parity^s=="Qb"));
				ly--;
				y/=2;
			}
			while(x!=y)
			{
				res += 2*(ly%2!=(parity^s=="Qb"));
				ly--;lx--;
				y/=2;x/=2;
			}
			res+=(ly%2!=(parity^s=="Qb"));
			cout << res << endl;
		}
	}
	
	return 0;
}

