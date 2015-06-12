#include <iostream>
#include <cstring>
using namespace std;

int zipcodes[51];
bool visited[51];
int canfly[51][51];
int N,M;

string dfs(int c)
{
	
}

int main()
{
	int T;
	cin >> T;
	
	for(int t=1;t<=T;t++)
	{
		cin >> N >> M;
		for(int i=0;i<N;i++)
			cin >> zipcodes[i];
		
		memset(canfly, 0, sizeof(canfly));
		for(int i=0;i<M;i++)
		{
			cin >> s >> e;
			canfly[s][e]=canfly[e][s]=1;
		}
		
		int mini=0;
		for(int i=0;i<N;i++)
			if(zipcodes[i]<zipcodes[mini])
				mini=i;
		
		cout << "Case #" << t << ": " << dfs(mini) << endl;
	}
	
	return 0;
}

