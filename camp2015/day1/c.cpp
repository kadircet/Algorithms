#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

vector<unsigned long long int> attacks, buys;
int adj[21];

int main()
{
	ios_base::sync_with_stdio(false);
	int K;
	unsigned long long int mask, mask2;
	int n,m,k,c,s,tmp,res;
	cin >> K;
	while(K--)
	{
		res=0;
		attacks.clear();
		buys.clear();
		cin >> n >> m >> k >> c;
		for(int i=0;i<n;i++)
			adj[i] = (1LL<<i);
		for(int i=0;i<k;i++)
		{
			cin >> s;
			mask=0;
			for(int j=0;j<s;j++)
			{
				cin >> tmp;
				mask |= (1LL<<(tmp-1));
			}
			attacks.push_back(mask);
		}
		for(int i=0;i<n;i++)
		{
			cin >> s;
			mask=0;
			for(int j=0;j<s;j++)
			{
				cin >> tmp;
				mask |= (1LL<<(tmp-1));
			}
			buys.push_back(mask);
		}
		for(int i=0;i<c;i++)
		{
			cin >> s >> tmp;
			adj[s-1]|=(1LL<<(tmp-1));
			adj[tmp-1]|=(1LL<<(s-1));
		}
		for(int i=1;i<(1<<n);i++)
		{
			mask=(1LL<<n)-1;
			mask2=0;
			for(int j=0;j<n;j++)
			{
				if((i&(1LL<<j)))
				{
					mask &= adj[j];
					mask2|= buys[j];
					if((i&mask)!=i)
						break;
				}
			}
			if((i&mask)!=i)//not a clique
				continue;
			//cout << i << ' ' << mask << ' ' << mask2 << endl;
			for(int j=0;j<attacks.size();j++)
				if((attacks[j]&mask2)==attacks[j])
				{
					res++;
					break;
				}
		}
		cout << res << endl;
	}
	return 0;
}
 
