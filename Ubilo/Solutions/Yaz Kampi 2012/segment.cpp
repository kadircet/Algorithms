#include <iostream>
#include <fstream>
#include <cmath>
#define INF 9999999
using namespace std;

class SegmentTree
{
	private:
		int *A, size;
		int* lazy;
	public:
		SegmentTree(int N)
		{
			size = 4*N+10;
			A = new int[size];
			lazy = new int[size];
			for(int i=0;i<size;i++)
				A[i] = lazy[i] = 0;
		}
		
		int update(int node, int s, int e, int rs, int re, int u)
		{
			if(s>re || e<rs)
				return A[node] + lazy[node];
			if(s==e)
			{
				A[node] += lazy[node]+u;
				lazy[node] = 0;
				return A[node];
			}
			if(s>=rs && e<=re)
			{
				lazy[node] += u;
				return A[node] + lazy[node];
			}
			int mid=(s+e)/2;
			return (A[node] = max(update(2*node, s, mid, rs, re, u), update(2*node+1, mid+1, e, rs, re, u))) + lazy[node];
		}
		
		int query(int node, int s, int e, int rs, int re)
		{
			if(s>re || e<rs)
				return 0;
			if(s>=rs && e<=re)
				return A[node] + lazy[node];
			int mid=(s+e)/2;
			return max(query(2*node, s, mid, rs, re), query(2*node+1, mid+1, e, rs, re)) + lazy[node];
		}
};

int main()
{
	ifstream inp("segment.gir");
	ofstream oup("segment.cik");
	int N=1000000, M;
	char c;
	int rs, re;
	
	inp >> M;
	SegmentTree st(N);
	for(int i=0;i<M;i++)
	{
		inp >> c >> rs >> re;
		if(c=='Q')
			oup << st.query(1, 1, N, rs, re) << endl;
		else
			st.update(1, 1, N, rs, re, 1);
	}
	
	return 0;
}

