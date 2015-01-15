#include <iostream>
#include <set>
#include <utility>
#include <fstream>
using namespace std;

class compare
{
	public:
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)
		{
			if(a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		}
};

set<pair<int, int>,compare> s;
int l[1000001], r[1000001], p[1000001], n;

pair<int, int> mkp(int x, int y)
{
	int m,d;
	if(x == 0) m = 1, d = y-m;
	else if(y == n+1) m = n, d = m-x;
	else m = (x+y)/2, d = m-x;
	return make_pair(d,m);
}

void insert(int x,int y)
{
	pair<int, int> block = mkp(x,y);
	if(block.first==0) return;
	l[block.second] = x; r[block.second] = y;
	s.insert(block);
}

void remove(int x, int y)
{
	s.erase(mkp(x,y));
}

int main()
{
	ifstream inp("otopark.gir");
	ofstream oup("otopark.cik");
	int m, state, id, xl, xr;
	inp >> n >> m;
	
	s.insert(make_pair(n-1,1)); l[1] = 0; r[1] = n+1;
	for(int i=0;i<m;i++)
	{
		inp >> state >> id;
		if(state==1)
		{
			int x = s.begin()->second;
			xl = l[x]; xr = r[x];
			r[xl] = l[xr] = x;
			
			s.erase(s.begin());
			insert(xl,x);
			insert(x,xr);
			
			oup << (p[id] = x) << endl;
		}
		else
		{
			int x = p[id], xl = l[x], xr = r[x];
			r[xl] = xr; l[xr] = xl;
			remove(xl,x);
			remove(x,xr);
			insert(xl,xr);
		}
	}
	return 0;
}

