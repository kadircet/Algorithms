#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> diff[2001];
int hop[2001];
vector<int> ress[3];

void print()
{
	bool sec=false,thi=false;
	for(int i=0;i<2001;i++)
		for(int j=0;j<diff[i].size();j++)
		{
			ress[0].push_back(diff[i][j]);
			ress[1].push_back(diff[i][j]);
			ress[2].push_back(diff[i][j]);
			if(j>=1 && !sec)
			{
				swap(ress[1][ress[1].size()-1], ress[1][ress[1].size()-2]);
				sec=true;
			}
			else if(j>=1 && sec && !thi)
			{
				swap(ress[2][ress[2].size()-1], ress[2][ress[2].size()-2]);
				thi=true;
			}
		}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<ress[i].size();j++)
			cout << (ress[i][j]+1) << ' ';
		cout << endl;
	}
}

int main()
{
	cin >> N;
	int t;
	for(int i=0;i<N;i++)
	{
		cin >> t;
		diff[t].push_back(i);
		hop[i]=t;
	}
	
	long long res=1;
	for(int i=0;i<2001;i++)
	{
		if(diff[i].size())
			res*=diff[i].size();
		if(res>=3)
			break;
	}
	if(res>=3)
	{
		cout << "YES" << endl;
		print();
	}
	else
		cout << "NO" << endl;
	
	return 0;
}

