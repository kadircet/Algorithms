#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int N;
int tree[5005];
int l[5005], r[5005];
map<long, int> rank;

void upd(int idx, int val=1)
{
	while(idx<=N)
	{
		tree[idx]+=val;
		idx += idx&-idx;
	}
}

long query(int idx)
{
	long res=0;
	while(idx>0)
	{
		res += tree[idx];
		idx -= idx&-idx;
	}
	
	return res;
}

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		vector<long> numb, ord;
		cin >> N;
		numb.resize(N), ord.resize(N);
		
		for(int i=0;i<N;i++)
		{
			cin >> numb[i];
			ord[i] = numb[i];
		}
		
		sort(ord.begin(), ord.end());
		for(int i=0;i<N;i++)
			rank[ord[i]] = i+1;
		
		memset(tree, 0, sizeof(int)*(5*N+1));
		l[0]=0;
		upd(rank[numb[0]]);
		for(int i=1;i<N;i++)
		{
			int pos = query(rank[numb[i]]);
			upd(rank[numb[i]]);
			l[i] = l[i-1]+i-pos;
			//cout << l[i] << ' ';
		}
		//cout << endl;
		
		memset(tree, 0, sizeof(int)*(5*N+1));
		r[N] = 0;
		for(int i=N-1;i>=0;i--)
		{
			int pos = query(rank[numb[i]]);
			upd(rank[numb[i]]);
			r[i] = r[i+1]+(N-1-i)-pos;
			//cout << r[i] << ' ';
		}
		//cout << endl;
		
		int best=l[0]+r[1];
		for(int i=0;i<N;i++)
			best = min(best, l[i]+r[i+1]);
		
		rank.clear();
		cout << "Case #" << t << ": " << best << endl;
	}
	
	return 0;
}
