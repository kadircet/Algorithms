#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct point
{
	long long int x,y;
};

int N,M,K;
unsigned long long int cK;
vector<point> bikes, bikers;
vector<unsigned long long int> times;

int wbike[251], wbiker[251], vis[501];
unsigned long long int dist[251][251];
bool find_bike(int biker);

bool find_biker(int bike)
{
	if(vis[bike+N]==1)
		return false;
	vis[bike+N]=1;
	
	if(wbiker[bike]==-1)
		return true;
	return find_bike(wbiker[bike]);
}

bool find_bike(int biker)
{
	if(vis[biker]==1)
		return false;
	vis[biker]=1;
	
	for(int i=0;i<M;i++)
		if(dist[biker][i]<=cK)
			if(find_biker(i))
			{
				wbiker[i]=biker;
				wbike[biker]= i;
				return true;
			}
	return false;
}

bool find_path()
{
	memset(vis, 0, sizeof(vis));
	
	for(int i=0;i<N;i++)
		if(wbike[i]==-1)
			if(find_bike(i))
				return true;
	return false;
}

int main()
{
	cin >> N >> M >> K;
	
	bikers.resize(N);
	bikes.resize(M);
	for(int i=0;i<N;i++)
	{
		cin >> bikers[i].x >> bikers[i].y;
		wbike[i]=-1;
	}
	for(int i=0;i<M;i++)
	{
		cin >> bikes[i].x >> bikes[i].y;
		wbiker[i]=-1;
	}
		
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			dist[i][j] = (bikes[j].x-bikers[i].x)*(bikes[j].x-bikers[i].x)+
				(bikes[j].y-bikers[i].y)*(bikes[j].y-bikers[i].y);
			times.push_back(dist[i][j]);
		}
	sort(times.begin(), times.end());
	
	unsigned long long int ans=times.back()+1;
	int l=0,u=times.size()-1;
	while(l<=u)
	{
		cK = times[(u+l)/2];
		
		bool flag=false;
		for(int i=0;find_path();i++)
			if(i==K-1)
			{
				flag=true;
				break;
			}
		if(flag)
		{
			ans = min(ans, cK);
			u=(u+l)/2-1;
		}
		else
			l=(u+l)/2+1;
		for(int i=0;i<N;i++)
			wbike[i]=-1;
		for(int i=0;i<M;i++)
			wbiker[i]=-1;
	}
	cout << ans << endl;
	
	return 0;
}

