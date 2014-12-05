#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool contains(vector<int> a, int key)
{
	for(int i=0;i<a.size();i++)
		if(a[i]==key)
			return true;
	return false;
}

vector<int> getSolution(int i, int last, bool **part, vector<int> milks)
{
	vector<int> sol;
	if(i<0)
		return sol;
	if(i>0 && part[i-1][last])
		return getSolution(i-1, last, part, milks);
	if(last>=milks[i])
	{
		sol = getSolution(i-1, last-milks[i], part, milks);
		sol.push_back(milks[i]);
	}
	return sol;
}

bool** partition(vector<int> milks, int sum)
{
	bool **part = new bool*[milks.size()+1];
	part[0] = new bool[sum/2+1];
	part[0][0] = true;
	part[0][milks[0]] = true;
	for(int i=1;i<milks.size();i++)
	{
		part[i] = new bool[sum/2+1];
		part[i][0] = true;
		for(int j=0;j<=sum/2;j++)
		{
			if(j>=milks[i])
				part[i][j] = part[i-1][j] || part[i-1][j-milks[i]];
			else
				part[i][j] = part[i-1][j];
		}
	}
	return part;
}

int main()
{
	ifstream inp("sut.gir");
	ofstream oup("sut.cik");
	bool **part;
	int N,S=0;
	vector<int> milks;
	
	inp >> N;
	int m;
	for(int i=0;i<N;i++)
	{
		inp >> m;
		milks.push_back(m);
		S+=m;
	}
	part = partition(milks, S);
	
	vector<int> g1 = getSolution(N-1, j, part, milks);
	vector<int> g2;
	for(int i=0;i<milks.size();i++)
		if(!contains(g1, milks[i]))
			g2.push_back(milks[i]);

	int T=0;
	for(int j=S/2;j>0;j--)
		if(part[N-1][j])
		{
			if(j==S-j)
			{
				T=j;
				break;
			}
			else
			{
				int diff = S-2*j;
				if(contains(milks,diff))
				{
					T=j;
					break;
				}
				else
				{
					
				}
			}
		}
	oup << T << endl;
	return 0;
}

