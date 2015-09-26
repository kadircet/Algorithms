#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

struct rect
{
	unsigned long long int x1,x2,y1,y2;
	
	bool operator()(const rect& r1, const rect& r2) const
	{
		return r1.x1<r2.x1;
	}
	
	bool operator<(const rect &r) const
	{
		return operator()(*this, r);
	}
};

struct event
{
	unsigned long long int x,id,type;
	
	bool operator<(const event &e) const
	{
		return x<e.x;
	}
};

int T[1000000], lazy[1000000], pre[100000];

void build(int n, int l, int r)
{
	if(l==r)
	{
		T[n]=lazy[n]=-1;
		T[2*n]=T[2*n+1]=lazy[2*n]=lazy[2*n+1]=-1;
		return;
	}
	
	T[n]=lazy[n]=-1;
	build(2*n, l, (l+r)/2);
	build(2*n+1, (l+r)/2+1, r);
}

void update(int n, int l, int r, int ql, int qr, int id, bool updpre)
{
	if(lazy[n]!=-1)
	{
		T[n]=lazy[n];
		if(l!=r)
		{
			lazy[2*n]=lazy[n];
			lazy[2*n+1]=lazy[n];
		}
		lazy[n]=-1;
	}
	
	if(ql<=l && r<=qr)
	{
		if(updpre)
			pre[id]=T[n];
		T[n]=id;
		if(l!=r)
			lazy[2*n]=lazy[2*n+1]=id;
		return;
	}
	
	int mid=(l+r)/2;
	if(ql<=mid)
		update(2*n, l, mid, ql, qr, id, updpre);
	if(mid<qr)
		update(2*n+1, mid+1, r, ql, qr, id, updpre);
}

int query(int n, int l, int r, int ql, int qr)
{
	if(lazy[n]!=-1)
	{
		T[n]=lazy[n];
		if(l!=r)
		{
			lazy[2*n]=lazy[n];
			lazy[2*n+1]=lazy[n];
		}
		lazy[n]=-1;
	}
	
	if(ql<=l && r<=qr)
		return T[n];
	
	if(lazy[n]!=-1)
		return lazy[n];
		
	int mid=(l+r)/2, res=-1;
	if(ql<=mid)
		res=query(2*n, l, mid, ql, qr);
	if(mid<qr)
		res=max(res,query(2*n+1, mid+1, r, ql, qr));
	
	return res;
}

vector<rect> rects;
map<unsigned long long int, int> visited;
vector<unsigned long long int> ys;
vector<event> events;
vector<int> res;

int main()
{
	int N;
	event e;
	cin >> N;
	rects.resize(N);
	res.resize(N);
	for(int i=0;i<N;i++)
	{
		pre[i]=-1;
		cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
		if(rects[i].x1>rects[i].x2)
			swap(rects[i].x1, rects[i].x2);
		if(rects[i].y1>rects[i].y2)
			swap(rects[i].y1, rects[i].y2);
		if(!visited[rects[i].y2])
			ys.push_back(rects[i].y2);
		if(!visited[rects[i].y1])
			ys.push_back(rects[i].y1);
		visited[rects[i].y2]=1;
		visited[rects[i].y1]=1;
	}
	sort(ys.begin(), ys.end());
	for(int i=0;i<ys.size();i++)
		visited[ys[i]]=i;
	for(int i=0;i<N;i++)
	{
		rects[i].y1=visited[rects[i].y1];
		rects[i].y2=visited[rects[i].y2];
		e.id=i;
		e.type=0;
		e.x=rects[i].x1;
		events.push_back(e);
		e.type=1;
		e.x=rects[i].x2;
		events.push_back(e);
	}
	sort(events.begin(), events.end());
	build(1, 0, ys.size());
	int miny,maxy,q;
	for(int i=0;i<events.size();i++)
	{
		e = events[i];
		miny=rects[e.id].y1,maxy=rects[e.id].y2;
		if(e.type==0)
		{
			q=query(1, 0, ys.size(), miny, maxy);
			res[e.id]=q+1;
			update(1, 0, ys.size(), miny, maxy, e.id, true);
			//cout << e.id << ' ' << q << ' ' << pre[e.id] << endl;
		}
		else
		{
			//cout << e.id << ' ' << pre[e.id] << endl;
			update(1, 0, ys.size(), miny, maxy, pre[e.id], false);
		}
	}
	
	for(int i=0;i<N;i++)
		cout << res[i] << endl;
	
	return 0;
}

