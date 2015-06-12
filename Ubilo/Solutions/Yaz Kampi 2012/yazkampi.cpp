#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

class point
{
	public:
		double order;
		double x,y;
		friend istream& operator>>(istream& is, point& p);
};

istream& operator>>(istream& is, point& p)
{
	is >> p.x >> p.y;
	return is;
}

bool comp(const point p1, const point p2)
{
	if(p1.x==p2.x)
		return p1.order > p2.order;
	return p1.x<p2.x;
}

double dist(point& p1, point& p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int N,M;

point villages[100001];
point stations[100001];

int findNearestStat(point p)
{
	int nS=0;
	double curdiff=0;
	int u = M;
	int l = 0;
	int m,s;
	while(u>l+1)
	{
		m = (u+l)/2;
		s=m;
		
		curdiff = dist(stations[s], p);
		if(s<M-1 && curdiff>dist(stations[s+1], p))
		{
			curdiff = dist(stations[s+1], p);
			s++;
			l=s+1;
		}
		else
			u=s;
	}
	nS = l;
	if(dist(stations[nS], p) > dist(stations[u], p))
		nS = u;
	else if(dist(stations[nS], p) == dist(stations[u], p))
		if(stations[u].order < stations[nS].order)
			nS = u;
	return stations[nS].order;
}

int main()
{
	ifstream inp("yazkampi.gir");
	ofstream oup("yazkampi.cik");
	
	inp >> N >> M;
	point p;
	for(int i=0;i<N;i++)
	{
		inp >> villages[i];
		villages[i].order = i+1;
	}
	for(int i=0;i<M;i++)
	{
		inp >> stations[i];
		stations[i].order=i+1;
	}
	
	sort(stations, stations+M, comp);
	
	for(int i=0;i<N;i++)
		oup << findNearestStat(villages[i]) << endl;
	
	return 0;
}

