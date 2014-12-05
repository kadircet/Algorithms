#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;

void printvector(vector<int> v, ostream& oup)
{
	while(v.back() == 0)
		v.pop_back();
	oup << v.size() << " ";
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++)
		oup << *it << " ";
	oup << endl;
}

int main()
{
	ifstream inp("fibonacci.gir");
	ofstream oup("fibonacci.cik");
	vector<int> n1, n2;
	int l1, l2;
	int c;
	inp >> l1;
	
	for (int i=0;i<l1;i++)
	{
		inp >> c;
		n1.push_back(c);
	}
	inp >> l2;
	for (int i=0;i<l2;i++)
	{
		inp >> c;
		n2.push_back(c);
		n1[i] += c;
		n1.push_back(0);
	}
	n1.push_back(0);
	bool isChanged = true;
	while(isChanged)
	{
		isChanged = false;
		if(n1[0] == 2)
		{
			isChanged = true;
			n1[1]++;
			n1[0] = 0;
		}
		for(int i=n1.size()-1;i>0;i--)
		{
			if(n1[i] > 0 && n1[i-1] > 0)
			{
				int t = min(n1[i], n1[i-1]);
				isChanged = true;
				n1[i+1] += t;
				n1[i]-=t;
				n1[i-1]-=t;
			}
			else if(n1[i] > 1 && i>1)
			{
				isChanged = true;
				n1[i-1]++;
				n1[i-2]++;
				n1[i]--;
				i--;
			}
			else if(n1[i] > 1)
			{
				isChanged = true;
				n1[i-1]+=2;
				n1[i]--;
				i=n1.size()-1;
			}
		}
	}
	printvector(n1, oup);
	return 0;
}

