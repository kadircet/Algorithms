#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> BIT;

long long get(int idx)
{
	long long res=0;
	while(idx>0)
	{
		res+=BIT[idx];
		idx -= idx & -idx;
	}
	return res;
}

void insert(int idx, int val=1)
{
	while(idx<=BIT.size())
	{
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<long long> d(n), d2(n);
	BIT.resize(n);
	for(int i=0;i<n;i++)
		cin >> d[i], d2[i] = d[i];
	
	map<long long, int> rankMap;
	int rank=0;
	sort(d2.begin(), d2.end());
	d2.resize(unique(d2.begin(), d2.end())-d2.begin());
	for(int i=0;i<d2.size();i++)
		rankMap[d2[i]]=rank++;
	
	vector<int> lower(n), greater(n), prev(n);
	vector<bool> visited(n);
	for(int i=0;i<n;i++)
	{
		rank = rankMap[d[i]];
		lower[i] = get(rank) - prev[rank];
		//cout << d[i] << ' ' << lower[i] << endl;
		if(!visited[rank])insert(rank+1);
		visited[rank]=true;
		prev[rank] += lower[i];
	}
	
	BIT.clear(), BIT.resize(n);
	visited.clear(), visited.resize(n);
	for(int i=n-1;i>=0;i--)
	{
		rank = d2.size()-rankMap[d[i]]-1;
		greater[i] = get(rank);
		//cout << d[i] << ' ' << greater[i] << endl;
		if(!visited[rank])insert(rank+1);
		visited[rank]=true;
	}
	
	long long m=0;
	for(int i=0;i<n;i++)
		m+=lower[i]*greater[i];
	cout << m << endl;
	return 0;
}

