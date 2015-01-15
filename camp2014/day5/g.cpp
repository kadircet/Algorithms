#include <iostream>
#include <vector>
#include <algorithm>

int dist[100001], inp[100001];
int count[100001];
bool isBest[100001];
std::vector<int> poss;

int main()
{
	int N,t;
	std::cin >> N;
	for(int i=1;i<=N;i++)
	{
		std::cin >> inp[i];
		t=inp[i];
		dist[i] = t-i;
		if(dist[i]<0)
			dist[i]+=N;
		count[dist[i]]++;
	}
	
	int best=count[1];
	for(int i=0;i<=N;i++)
		if(count[i]>best)
			best=count[i];
	
	for(int i=1;i<=N;i++)
		if(count[dist[i]]==best)
		{
			poss.push_back(i-inp[i]+1);
			if(i+1-inp[i]<=0)
				poss[poss.size()-1]+=N;
		}
	std::sort(poss.begin(), poss.end());
	std::cout << poss[0] << std::endl;
	return 0;
}


