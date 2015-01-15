#include <iostream>
#include <fstream>
using namespace std;

int L,D;
int p[40][40][40];

int par(int op, int cl, int md)
{
	if(p[op][cl][md] != -1)
		return p[op][cl][md];
	int cd=op-cl;
	if(cd>md)
		md=cd;
	if(md>D)
		return 0;
	if(op+cl > L)
		return 0;
	if(cl>op)
		return 0;
	if(op>L/2)
		return 0;
	if(op==cl && op+cl==L && md==D)
		return 1;
	p[op][cl][md] = par(op+1, cl, md) + par(op, cl+1, md);
	return p[op][cl][md];
}

int main()
{
	ifstream inp("par.gir");
	ofstream oup("par.cik");
	for(int i=0;i<40;i++)
		for(int j=0;j<40;j++)
			for(int k=0;k<40;k++)
				p[i][j][k] = -1;
	inp >> L >> D;
	if(D==L/2 || D==1)
		oup << 1 << endl;
	else if(D==0 || D>L/2)
		oup << 0 << endl;
	else
		oup << par(0, 0, 0) << endl;
	
	return 0;
}

