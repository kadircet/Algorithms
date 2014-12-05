#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int C[1001][1001];

int main()
{
	ifstream inp("lcs.gir");
	ofstream oup("lcs.cik");
	
	string a,b;
	inp >> a >> b;
	
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
		{
			int c=C[i-1][j];
			if(C[i][j-1] > c)
				c=C[i][j-1];
			if(a[i-1]==b[j-1] && C[i-1][j-1]+1>c)
				c=C[i-1][j-1]+1;
			C[i][j] = c;
		}
	
	oup << C[a.size()][b.size()] << endl;
	return 0;
}

