#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string inp[2];
int count[2][256];
int main()
{
	int res=0;
	for(int i=0;i<2;i++)
	{
		cin >> inp[i];
		for(int j=0;j<inp[i].size();j++)
			count[i][inp[i][j]]++;
	}
	
	for(int i=0;i<256;i++)
		res += abs(count[0][i] - count[1][i]);
	cout << res << endl;
	
	return 0;
}

