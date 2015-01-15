#include <iostream>
#define SGN(X) ((X)>0?1:((X)<0?-1:0))
using namespace std;

struct point
{
	int x, y;
	int cross(const point& p) const
	{
		return (p.x*y) - (p.y*x);
	}
	
	point operator-(const point& p) const
	{
		point res;
		res.x = x-p.x;
		res.y = y-p.y;
		
		return res;
	}
};

point points[3];

int main()
{
	int N, prev, cur;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> points[i%3].x >> points[i%3].y;
		if(i<2)
			continue;
		
		cur = (points[i%3]-points[(i-2)%3]).cross(points[(i-1)%3]-points[(i-2)%3]);
		if(i==2)
		{
			prev=cur;
			if(cur==0)
			{
				cout << "HAYIR" << endl;
				return 0;
			}
			continue;
		}
		
		if(SGN(cur)==SGN(prev) || SGN(cur)==0)
		{
			cout << "HAYIR" << endl;
			return 0;
		}
		prev=cur;
	}
	
	cout << "EVET" << endl;
	return 0;
}

