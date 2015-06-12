#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

struct point
{
	double x,y;
};

point points[150],orig;
int M;
int h[50];

bool before(int i, int j)
{
	double a2 = atan2(points[j].y-orig.y, points[j].x-orig.x),
			a1= atan2(points[i].y-orig.y, points[i].x-orig.x);
	
	if(a1!=a2)
		return a1<a2;
	return points[i].x<points[j].x;
}

void sort(int start, int end)
{
	orig=points[start];
	for(int i=start+1;i<end;i++)
		if(points[i].y<orig.y)
			orig = points[i];
		else if(points[i].y==orig.y && points[i].x<orig.x)
			orig = points[i];
	
	for(int i=start;i<end;i++)
		for(int j=i+1;j<end;j++)
			if(before(j, i))
				swap(points[i], points[j]);
}

double area(int start, int end)
{
	int N = end-start;
	double res=0;
	for(int i=start;i<end;i++)
		res += points[i].x*points[(i+1)%N].y - points[(i+1)%N].x*points[i].y;
	
	return res/2;
}

int main()
{
	int N;
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> N >> h[i];
		for(int j=0;j<2*N;j++)
			cin >> points[j].x >> points[j].y;
		
		for(int j=0;j<N;j++)
		{
			points[j+2*N].x = points[j].x + points[((j+1)%N)+N].x;
			points[j+2*N].x /= 2;
			points[j+2*N].y = points[j].y + points[((j+1)%N)+N].y;
			points[j+2*N].y /= 2;
		}
		
		for(int j=0;j<N;j++)
		{
			points[j+3*N].x = points[j].x + points[j+N].x;
			points[j+3*N].x/= 2;
			points[j+3*N].y = points[j].y + points[j+N].y;
			points[j+3*N].y/=2 ;
		}
		
		sort(0, N);
		sort(N, 2*N);
		sort(2*N, 4*N);
		double bot = area(0, N), top = area(N, 2*N), mid = area(2*N, 4*N);
		cout << bot << ' ' << top << ' ' << mid << endl;
		
		double vol = (bot+top+4*mid)*h[i]/6.0;
		cout << vol << endl;
	}
}

