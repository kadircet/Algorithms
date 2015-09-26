#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

struct point
{
	long long int x,y;
	
	bool operator()(const point &p1, const point &p2) const
	{
		if(p1.x!=p2.x)
			return p1.x<p2.x;
		return p1.y<p2.y;
	}
	
	bool operator<(const point &p1) const
	{
		return operator()(*this, p1);
	}
	
	point operator-(const point &p1)
	{
		point res;
		res.x=x-p1.x;
		res.y=y-p1.y;
		return res;
	}
};

vector<point> u,l;
vector<point> ps;

long long int cross(point p1, point p2, point p3)
{
	p2=p2-p1;
	p3=p3-p1;
	
	return p2.x*p3.y-p2.y*p3.x;
}

int main()
{
	long long int N;
	cin >> N;
	ps.resize(N);
	for(int i=0;i<N;i++)
		cin >> ps[i].x >> ps[i].y;
	sort(ps.begin(), ps.end());
	for(int i=0;i<N;i++)
	{
		while(u.size()>1 && cross(u[u.size()-2], u[u.size()-1], ps[i])<=0)
			u.pop_back();
		u.push_back(ps[i]);
	}
	for(int i=N-1;i>=0;i--)
	{
		while(l.size()>1 && cross(l[l.size()-2], l[l.size()-1], ps[i])<=0)
			l.pop_back();
		l.push_back(ps[i]);
	}
	
	long long int res=l.size()+u.size()-4;
	res += (N-res-2)*3;
	cout << res << endl;
	return 0;
}

