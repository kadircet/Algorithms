#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ifstream inp("badhair.gir");
	ofstream oup("badhair.cik");
	
	vector<int> cows;
	int N,h;
	inp >> N;
	
	cows.push_back(0);
	for(int i=0;i<N;i++)
	{
		inp >> h;
		cows.push_back(h);
	}
	
	vector<int> c = vector<int>(N+1, 0);
	vector<int> block = vector<int>(N+1, 0);
	int left = N;
	while(left>0)
	{
		left--;
		if(cows[left] > cows[left+1])
		{
			c[left] += c[left+1] + 1;
			int b = block[left+1];
			while(b!=block[b] && cows[left] > cows[b])
			{
				c[left] += c[b] + 1;
				b = block[b];
			}
			block[left] = b;
		}
		else
			block[left] = left+1;
	}
	long long intd tot = 0;
	for(int i=1;i<N+1;i++)
		tot += c[i];
	oup << tot << endl;
	return 0;
}

