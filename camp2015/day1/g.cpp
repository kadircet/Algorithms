#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int best=13*13*13*13+1;
int n[4];
int p[4], op[3];
bool used[4];

int doop(int res, int p, int op)
{
	if(op==3 && (p==0 || res%p!=0))
		return 13*13*13*13*13;
	switch(op)
	{
		case 0:
			res+=p;
			break;
		case 1:
			res-=p;
			break;
		case 2:
			res*=p;
			break;
		case 3:
			res/=p;
	}
	return res;
}

void search2(int pos=0)
{
	if(pos==3)
	{
		int res=p[0];
		for(int i=0;i<3;i++)
			if(op[i]==3 && res%p[i+1]!=0)
				return;
			else
				res=doop(res,p[i+1],op[i]);
		if(best==13*13*13*13+1)
			best=res;
		else if(abs(21-best)>abs(21-res))
			best=res;
		else if(abs(21-best)==abs(21-res) && best>res)
			best=res;
			
		res = doop(doop(p[0], p[1], op[0]),doop(p[2],p[3],op[2]),op[1]);
		if(abs(21-best)>abs(21-res))
			best=res;
		else if(abs(21-best)==abs(21-res) && best>res)
			best=res;
		return;
	}
	for(int i=0;i<4;i++)
	{
		op[pos]=i;
		search2(pos+1);
	}
}

void search(int pos=0)
{
	if(pos==4)
	{
		search2();
		return;
	}
	for(int i=0;i<4;i++)
	{
		if(!used[i])
		{
			used[i]=true;
			p[pos] = n[i];
			search(pos+1);
			used[i]=false;
		}
	}
}

int main()
{
	for(int i=0;i<4;i++)
		cin >> n[i];
	search();
	cout << best << endl;
	return 0;
}
 
