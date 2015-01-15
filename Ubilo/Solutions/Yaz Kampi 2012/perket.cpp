#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int P=1,S=0,N;
bool check[10];
vector<int> Ps,Ss;
int minDiff=-1;

void lookDif(int cp)
{
	if(cp==N)
	{
		bool checked = false;
		for(int i=0;i<N;i++)
			if(check[i])
			{
				checked=true;
				break;
			}
		if(checked)
		{
			int d = (int)abs((double)(P-S));
			if(d<minDiff || minDiff == -1)
				minDiff=d;
		}
		return;
	}
	check[cp] = true;
	P*=Ps[cp];
	S+=Ss[cp];
	lookDif(cp+1);
	check[cp] = false;
	P/=Ps[cp];
	S-=Ss[cp];
	lookDif(cp+1);
}

int main()
{
	ifstream inp("perket.gir");
	ofstream oup("perket.cik");
	
	int p,s;
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> p >> s;
		Ps.push_back(p);
		Ss.push_back(s);
	}
		
	lookDif(0);
	oup << minDiff << endl;
	
	return 0;
}

