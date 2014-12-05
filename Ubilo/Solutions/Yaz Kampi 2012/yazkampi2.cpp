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

double dist(point& p1, point& p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int N,M;

point villages[100001];
point stations[100001];

int findNearestStat(point p)
{
	double minDiff=numeric_limits<double>::max();
	int nS=0;
	for(int i=0;i<M;i++)
	{
		double curDiff = dist(p, stations[i]);
		if(curDiff < minDiff)
		{
			minDiff = curDiff;
			nS = i;
		}
	}
	return nS+1;
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
	
	for(int i=0;i<N;i++)
		oup << findNearestStat(villages[i]) << endl;
	
	return 0;
}


