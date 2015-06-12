#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> bMap;

string base2(int n)
{
	vector<bool> n2;
	while(n>0)
	{
		n2.push_back(n%2);
		n/=2;
	}
	string res="";
	for(int i=0;i<8-n2.size();i++)
		res += '0';
	for(int i=n2.size()-1;i>=0;i--)
		res += n2[i]?'1':'0';
	return res;
}
int dc[]={1,0,-1,0,1,-1,1,-1};
int dr[]={0,1,0,-1,1,1,-1,-1};

bool inBound(int r, int c)
{
	return r>=0 && r<bMap.size() && c>=0 && c<bMap[0].size();
}

bool diag=false;
string detect(int r, int c, int dir=-1, int nl=0, int h=0, int w=0)
{
	if(dir==-1)
	{
		for(dir=0;dir<8;dir++)
			if(inBound(r+dr[dir], c+dc[dir]) && bMap[r+dr[dir]][c+dc[dir]]=='1')
				break;
		return detect(r+dr[dir],c+dc[dir],dir,nl,h+(dr[dir]==1),w+(dc[dir]==1));
	}
	if(dir>3)
		diag = true;
	bMap[r][c]='C';
	if(inBound(r+dr[dir], c+dc[dir]) && bMap[r+dr[dir]][c+dc[dir]]=='1')
		return detect(r+dr[dir],c+dc[dir],dir,nl,h+(dr[dir]==1),w+(dc[dir]==1));
	else
	{
		nl++;
		for(dir=0;dir<8;dir++)
			if(inBound(r+dr[dir], c+dc[dir]) && bMap[r+dr[dir]][c+dc[dir]]=='1')
				break;
		if(dir!=8)
			return detect(r+dr[dir],c+dc[dir],dir,nl,h+(dr[dir]==1),w+(dc[dir]==1));
		else
		{
			if(nl==3)
				return "Triangle";
			else if(diag)
				return "Parallelogram";
			else if(h==w)
				return "Square";
			else
				return "Rectangle";
		}
	}
	return "ANAN";
}

void print(vector<string>& x)
{
	for(int i=0;i<x.size();i++)
		cout << x[i] << endl;
}

int main()
{
	vector<string> results;
	int r,c,t;
	cin >> r >> c;
	for(int i=0;i<r;i++)
	{
		string line = "";
		for(int j=0;j<c/8;j++)
		{
			cin >> t;
			line += base2(t);
		}
		bMap.push_back(line);
		cout << line << endl;
	}
	
	for(int i=0;i<bMap.size();i++)
		for(int j=0;j<bMap[i].size();j++)
			if(bMap[i][j]=='1')
			{
				diag=false;
				results.push_back(detect(i, j));
				//cout << results.back() << endl;
				//print(bMap);
			}
	
	sort(results.begin(), results.end());
	cout << results[0];
	for(int i=1;i<results.size();i++)
		cout << ", " << results[i];
	return 0;
}

