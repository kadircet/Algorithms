#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int R,G;
vector<int> printed;

int isPrinted(int x)
{
	for(int i=0;i<printed.size();i++)
		if(printed[i] == x)
			return true;
	return false;
}

int main()
{
	ifstream inp("jabuka.gir");
	ofstream oup("jabuka.cik");
	
	inp >> R >> G;
	int m = R;
	int d = 1;
	if(R>G)m=G;

	if(R%2 != 0 || G%2 != 0)
		d=2;
	for(int i=1;i*i<=m;i++)
	{
		int rd, gd;
		if(R%i == 0 && R%i == G%i && !isPrinted(i))
		{
			oup << i << " " << R/i << " " << G/i << endl;
			printed.push_back(i);
		}
		if(R%i == 0)
		{
			rd = R/i;
			if(R%rd == G%rd && !isPrinted(rd))
			{
				oup << rd << " " << i << " " << G/rd << endl;
				printed.push_back(rd);
			}
		}
		if(G%i == 0)
		{
			gd = G/i;
			if(G%gd == R%gd && !isPrinted(gd))
			{
				oup << gd << " " << R/gd << " " << i << endl;
				printed.push_back(gd);
			}
		}
	}
	return 0;
}

