#include <iostream>
#include <fstream>
using namespace std;

int best,total;
int bests[101];

typedef struct _rect
{
	int w, h;
}Rect;

void updateBest(Rect r)
{
	int a = r.w * r.h;
	if(a<total)
		return;
	if(a<best || best==0)
	{
		best=a;
		for(int i=0;i<=100;i++)
			bests[i] = 0;
	}
	
	if(a==best)
	{
		if(r.w > r.h)
			bests[r.h] = 1;
		else
			bests[r.w] = 1;
	}
}

Rect Rotate(Rect r)
{
	Rect rr;
	rr.w = r.h;
	rr.h = r.w;
	return rr;
}

void check(Rect *r)
{
	Rect total;
	
	total.w = 0;total.h = 0;
	for(int i=0;i<4;i++)
	{
		total.w += r[i].w;
		if(r[i].h > total.h)
			total.h = r[i].h;
	}
	updateBest(total);
	
	total.w = 0;total.h = 0;
	for(int i=0;i<3;i++)
	{
		total.w += r[i].w;
		if(r[i].h > total.h)
			total.h = r[i].h;
	}
	if(r[3].w > total.w)
		total.w = r[3].w;
	total.h += r[3].h;
	updateBest(total);
	
	total.w = 0;total.h = 0;
	total.w = r[0].w + r[1].w;
	if(r[3].w > total.w)
		total.w = r[3].w;
	total.w += r[2].w;
	total.h=r[0].h;
	if(r[1].h> total.h)
		total.h = r[1].h;
	total.h += r[3].h;
	if(r[2].h > total.h)
		total.h = r[2].h;
	updateBest(total);
	
	total.w = 0;total.h = 0;
	total.h = r[3].h;
	if(r[0].h>total.h)
		total.h = r[0].h;
	if(r[1].h + r[2].h > total.h)
		total.h = r[1].h + r[2].h;
	total.w = r[1].w;
	if(r[2].w > total.w)
		total.w = r[2].w;
	total.w += r[0].w + r[3].w;
	updateBest(total);
	
	total.w = 0;total.h = 0;
	total.w = r[0].w;
	if(r[1].w > total.w)
		total.w = r[1].w;
	total.w += r[2].w + r[3].w;
	total.h = r[0].h + r[1].h;
	if(r[2].h>total.h)
		total.h = r[2].h;
	if(r[3].h>total.h)
		total.h = r[3].h;
	updateBest(total);
	
	
	total.w = 0;total.h = 0;
	
	total.h = r[0].h+r[2].h;
	if(r[1].h+r[3].h>total.h)
		total.h = r[1].h+r[3].h;
    total.w = r[0].w + r[1].w;
    if(r[0].h < r[1].h)
    	if(r[2].w+r[1].w>total.w)
        	total.w = r[2].w+r[1].w;
    if(r[0].h+r[2].h > r[1].h)
    	if(r[2].w+r[3].w>total.w)
        	total.w = r[2].w+r[3].w;
    if(r[1].h < r[0].h)
    	if(r[0].w+r[3].w > total.w)
        	total.w = r[0].w+r[3].w;
    if(r[2].w>total.w)
    	total.w = r[2].w;
    if(r[3].w>total.w)
    	total.w = r[3].w;

	updateBest(total);
}

void checkRotate(int n, Rect* r)
{
	if(n==4)
	{
		check(r);
		return;
	}
	checkRotate(n+1, r);
	r[n] = Rotate(r[n]);
	checkRotate(n+1, r);
	r[n] = Rotate(r[n]);
}

void permute(int n, Rect* r)
{
	if(n==4)
	{
		checkRotate(0, r);
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		swap(r[n], r[i]);
		permute(n+1, r);
		swap(r[n], r[i]);
	}
}

int main()
{
	ifstream inp("paket.gir");
	ofstream oup("paket.cik");
	
	Rect *r = new Rect[4];
	
	for(int i=0;i<4;i++)
	{
		inp >> r[i].w >> r[i].h;
		total += r[i].w * r[i].h;
	}
		
	permute(0, r);
	
	oup << best << endl;
	for(int i=1;i<=100;i++)
		if(bests[i])
			oup << i << " " << best/i << endl;
		
	return 0;
}

