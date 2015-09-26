#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
using namespace std;

map<string, bool> seen;
vector<vector<int> > adj;
map<string, int> rank;
vector<string> inverse;
map<pair<int, int>, int> calls; //last call made from i->j
vector<pair<int, int> > sorting;
struct tm _tm;

bool mysort(const int &a, const int &b)
{
	return atoi(inverse[a].c_str())<atoi(inverse[b].c_str());
}

int main()
{
	int K,n,stamp,dur;
	string n1,n2;
	string date, time;
	cin >> K;
	for(int t=0;t<K;t++)
	{
		adj.clear();
		seen.clear();
		rank.clear();
		inverse.clear();
		calls.clear();
		sorting.clear();
		cin >> n;
		for(int j=0;j<n;j++)
		{
			cin >> date >> time >> dur >> n1 >> n2;
			date+= " " + time;
			if(n1!=n2)
			{
				if(seen.find(n1)==seen.end())
				{
					seen[n1]=true;
					rank[n1]=inverse.size();
					sorting.push_back(pair<int,int>(atoi(n1.c_str()),rank[n1]));
					inverse.push_back(n1);
					adj.push_back(vector<int>());
				}
				if(seen.find(n2)==seen.end())
				{
					seen[n2]=true;
					rank[n2]=inverse.size();
					sorting.push_back(pair<int,int>(atoi(n2.c_str()),rank[n2]));
					inverse.push_back(n2);
					adj.push_back(vector<int>());
				}
				pair<int,int> p=make_pair(rank[n2], rank[n1]);
				sscanf(date.c_str(), "%d/%d/%d %d:%d", &_tm.tm_year, &_tm.tm_mon, &_tm.tm_mday, &_tm.tm_hour, &_tm.tm_min);
				_tm.tm_sec=0;
				_tm.tm_mon--;
				_tm.tm_year-=1900;
				_tm.tm_isdst = 0;
  				stamp = mktime(&_tm);
  				//cout << stamp << endl;
  				if(calls.find(p)!=calls.end())
  				{
  					//cout << calls[p] << ' ' << stamp << ' ' << ((stamp-calls[p])-24*60*60) << endl;
  					if(calls[p]+24*60*60>=stamp)
  					{
  						adj[rank[n1]].push_back(rank[n2]);
  						adj[rank[n2]].push_back(rank[n1]);
  						//cout << "adding: " << n1 << ' ' << n2 << ' ' << stamp <<endl;
  					}
  				}
  				p = make_pair(rank[n1], rank[n2]);
  				calls[p]=stamp+dur*60;
			}
		}
		sort(sorting.begin(), sorting.end());
		for(int i=0;i<adj.size();i++)
		{
			sort(adj[i].begin(), adj[i].end(), mysort);
			adj[i].resize(distance(adj[i].begin(),unique(adj[i].begin(), adj[i].end())));
		}
		for(int i=0;i<sorting.size();i++)
		{
			int r=sorting[i].second;
			cout << inverse[r] << ":";
			for(int j=0;j<adj[r].size();j++)
				cout << ' ' << inverse[adj[r][j]];
			cout << endl;
		}
	}
	return 0;
}

 
