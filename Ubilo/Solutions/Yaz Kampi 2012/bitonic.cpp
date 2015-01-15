#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class point
{
	public:
		double x,y;
		double dist(point& p)
		{
			return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
		}
		friend istream& operator>>(istream& is, point& p);
};

istream& operator>>(istream& is, point& p)
{
	is >> p.x >> p.y;
	return is;
}

int N;
vector<point> points;
double B[1005][1005];

double bitonic(int x, int y)
{
	double c1 = B[y][y+1] + points[x].dist(points[y+1]);
	double c2 = B[x][y+1] + points[y].dist(points[y+1]);
	B[x][y] = c1;
	if(B[x][y] > c2)
		B[x][y] = c2;
	return B[x][y];
}

bool comp(const point p1, const point p2)
{
	return p1.x<p2.x;
}

int main()
{
	ifstream inp("bitonic.gir");
	ofstream oup("bitonic.cik");
	
	inp >> N;
	point p;
	points.push_back(p);
	for(int i=0;i<N;i++)
	{
		inp >> p;
		points.push_back(p);
	}
	sort(points.begin(), points.end(), comp);
	
	for(int i=0;i<=N;i++)
		for(int j=0;j<=N;j++)
			B[i][j] = -1.0;
	
	for(int i=1;i<=N;i++)
		B[i][N] = points[N].dist(points[i]);
	
	for(int i=N-1;i>0;i--)
		for(int j=i;j>0;j--)
			bitonic(j, i);
	
	oup.precision(2);
	oup.setf(ios::fixed);
	oup << bitonic(1, 1) << endl;	
	return 0;
}

