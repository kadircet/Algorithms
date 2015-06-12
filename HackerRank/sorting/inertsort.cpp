#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class BIT
{
	private:
		int n;
		vector<int> a;
	
	public:
		BIT(){}
		BIT(int n)
		{
			this->n = n+10;
			this->a = vector<int>(n+10, 0);
		}
		
		int query(int idx)
		{
			int res=0;
			while(idx>0)
			{
				res += a[idx];
				idx-=idx&-idx;
			}
			return res;
		}
		
		void update(int idx, int val=1)
		{
			while(idx<=this->n)
			{
				a[idx]+=val;
				idx+=idx&-idx;
			}
		}
};

int main()
{
	int T,N;
	vector<int> a,b;
	map<int, int> rank;
	BIT inv;
	
	cin>>T;
	while(T--)
	{
		rank.clear();
		
		cin >> N;
		
		inv = BIT(N);
		a = vector<int>(N);
		for(int i=0;i<N;i++)
			cin >> a[i];
		b=vector<int>(a);
		sort(a.begin(), a.end());
		for(int i=0;i<N;i++)
			rank[a[i]]=i+1;
		
		long res=0;
		for(int i=0;i<N;i++)
		{
			res += i-inv.query(rank[b[i]]);
			inv.update(rank[b[i]]);
		}
		cout << res << endl;
	}
	
	return 0;
}

