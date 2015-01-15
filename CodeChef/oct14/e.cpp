#include <iostream>
#include <set>
#include <map>
#include <cmath>
using namespace std;

map<int, set<int> > pointx;
int points[2000][2];
int N;
int rankx[2000001];
int ranky[2000001];
bool conn[2001][2001];

int main()
{
	int dx=1, dy=1;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> points[i][0] >> points[i][1];
		if(rankx[points[i][0]+1000000]==0)
			rankx[points[i][0]+1000000]=dx++;
		if(ranky[points[i][1]+1000000]==0)
			ranky[points[i][1]+1000000]=dy++;
		conn[rankx[points[i][0]+1000000]][ranky[points[i][1]+1000000]]=true;
	}
	
	if(N<3)
		cout << (4-N) << endl;
	else
	{
		int res=2;
		unsigned long long r;
		long long a,b,c,d;
		long long x1,y1, x2,y2;
		long long x3,y3, x4,y4;
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				a=points[i][0], b=points[i][1];
				c=points[j][0], d=points[j][1];
				
				if(c==a || (c-a)*(c-a) == (d-b)*(d-b))
					continue;
				r=(c-a)*(c-a);
				x1 = sqrt(r);
				if(x1*x1!=r)
					continue;
				r=x1;
				
				y1 = d-r, y2 = d+r;
				y3 = b-r, y4 = b+r;
					
				x1 = c+(d-b)*(d-y1)/(c-a)+1000000;
				x2 = c+(d-b)*(d-y2)/(c-a)+1000000;
				x3 = a+(d-b)*(b-y3)/(c-a)+1000000;
				x4 = a+(d-b)*(b-y4)/(c-a)+1000000;
				
				/*cout << "HOP---------" << endl;
				cout << r << endl;
				cout << a << ',' << b << ':' << c << ',' << d << endl;
				cout << x1 << ' ' << y1 << endl;
				cout << x2 << ' ' << y2 << endl;
				cout << x3 << ' ' << y3 << endl;
				cout << x4 << ' ' << y4 << endl;
				cout << "-----------" << endl;*/

				int tmp=2;
				if(y1>=-1000000 && y1<=1000000 && x1>=0 && x1<=2000000 && ((d-b)*(d-y1))%(c-a)==0)
					tmp-=conn[rankx[x1]][ranky[y1+1000000]];
				if(y3>=-1000000 && y3<=1000000 && x3>=0 && x3<=2000000 && ((d-b)*(b-y3))%(c-a)==0)
					tmp-=conn[rankx[x3]][ranky[y3+1000000]];
				res = min(tmp, res);
				tmp=2;
				if(y2>=-1000000 && y2<=1000000 && x2>=0 && x2<=2000000 && ((d-b)*(d-y2))%(c-a)==0)
					tmp-=conn[rankx[x2]][ranky[y2+1000000]];
				if(y4>=-1000000 && y4<=1000000 && x4>=0 && x4<=2000000 && ((d-b)*(b-y4))%(c-a)==0)
					tmp-=conn[rankx[x4]][ranky[y4+1000000]];
				res = min(tmp, res);
			}
		cout << res << endl;
	}
	return 0;
}

