#include <iostream>
using namespace std;

bool poss(int m, int s)
{
	if(s<0)
		return false;
	return s/9+(s%9!=0)<=m;
}

string solvem(int m, int s)
{
	if(m==0)
		return "";
	for(int i=0;i<10;i++)
		if(poss(m-1, s-i))
			return (char)(i+'0') + solvem(m-1, s-i);
	
	return "-1";
}


string solveM(int m, int s)
{
	if(m==0)
		return "";
	for(int i=9;i>=0;i--)
		if(poss(m-1, s-i))
			return (char)(i+'0') + solveM(m-1, s-i);
	
	return "-1";
}

int main()
{
	int s,m,M;
	cin >> m >> s;
	M=s/9+(s%9!=0);
	if(M>m)
		cout << "-1 -1" << endl;
	else if(s==0)
	{
		if(m==1)
			cout << "0 0" << endl;
		else
			cout << "-1 -1" << endl;
	}
	else
	{
		for(int i=1;i<10;i++)
			if(poss(m-1, s-i))
			{
				cout << i << solvem(m-1, s-i) << ' ';
				break;
			}
		cout << solveM(m, s) << endl;
	}
	
	return 0;
}
