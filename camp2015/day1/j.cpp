#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#define abs(x) ((x)<0?-(x):(x))
#define EPS 1e-5
using namespace std;

struct node
{
	double l1;
	double dp,cp;
	
	bool operator==(const node& rhs) const
	{
		return abs(l1-rhs.l1)<EPS && abs(dp-rhs.dp)<EPS && abs(cp-rhs.cp)<EPS;
	}
	
	void print()
	{
		cout << l1 << ' ' << dp << ' ' << cp << endl;
	}
};

struct point
{
	int first, second;
	
	point operator-(const point& p)
	{
		point res;
		res.first=first-p.first;
		res.second=second-p.second;
		return res;
	}
};

vector<point > p1, p2;
vector<node> pol1, pol2;

int cp(point a, point b)
{
	return b.second*a.first-a.second*b.first;
}

int dp(point a, point b)
{
	return a.first*b.first+a.second*b.second;
}

double dist(point a, point b)
{
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int T[100001];

void pre(vector<node> &w)
{
	int pos=2,cnd=0;
	T[0]=-1;
	T[1]=0;
	while(pos<w.size())
	{
		if(w[pos-1]==w[cnd])
			T[pos++]=++cnd;
		else if(cnd>0)
			cnd=T[cnd];
		else
			T[pos++]=0;
	}
}

int search(vector<node> &s, vector<node> &w)
{
	int m=0, i=0;
	
	while(m+i<s.size())
	{
		if(s[m+i]==w[i])
		{
			if(i==w.size()-1)
				return m;
			i++;
		}
		else
		{
			if(T[i]>-1)
			{
				m+=i-T[i];
				i=T[i];
			}
			else
			{
				i=0;
				m++;
			}
		}
	}
	
	return -1;
}

int main()
{
	int N;
	cin >> N;
	p1.resize(N);
	p2.resize(N);
	for(int i=0;i<N;i++)
		cin >> p1[i].first >> p1[i].second;
	for(int i=0;i<N;i++)
		cin >> p2[i].first >> p2[i].second;
		
	if(N==2)
	{
		int yd1 = p1[1].second-p1[0].second,
			yd2 = p2[1].second-p2[0].second;
		int xd1 = p1[1].first-p1[0].first,
			xd2 = p2[1].first-p2[0].first;
			
		if(yd1*xd2==yd2*xd1)
			cout << 1 << endl;
		else if(-yd1*xd2==yd2*xd1)
			cout << 2 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	
	double circ1=0,circ2=0,scale;
	for(int i=0;i<N-1;i++)
	{
		circ1+=dist(p1[i], p1[i+1]);
		circ2+=dist(p2[i], p2[i+1]);
	}
	scale = circ2/circ1;
	node tmp;
	
	for(int i=0;i<N;i++)
	{
		int j=i+1;
		while(j<N-1 && cp(p1[i]-p1[j%N], p1[(j+1)%N]-p1[j%N])==0)
			j++;
		tmp.l1 = dist(p1[i], p1[j%N])*scale;
		tmp.dp = dp(p1[i]-p1[j%N], p1[(j+1)%N]-p1[j%N])*scale*scale;
		tmp.cp = cp(p1[i]-p1[j%N], p1[(j+1)%N]-p1[j%N])*scale*scale;
		i=j-1;
		pol1.push_back(tmp);
	}
	
	for(int i=0;i<N;i++)
	{
		int j=i+1;
		while(j<N-1 && cp(p2[i]-p2[j%N], p2[(j+1)%N]-p2[j%N])==0)
			j++;
		tmp.l1 = dist(p2[i], p2[j%N]);
		tmp.dp = dp(p2[i]-p2[j%N], p2[(j+1)%N]-p2[j%N]);
		tmp.cp = cp(p2[i]-p2[j%N], p2[(j+1)%N]-p2[j%N]);
		i=j-1;
		pol2.push_back(tmp);
	}
	if(pol1.size()!=pol2.size())
	{
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=0;i<N;i++)
		pol1[i].print();
	for(int i=0;i<N;i++)
		pol2[i].print();
	
	for(int i=0;i<pol1.size();i++)
		pol2.push_back(pol2[i]);
	pre(pol1);
	int m = search(pol2, pol1);
	cout << (m+1) << endl;
	return 0;
}

