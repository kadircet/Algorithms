#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class SegmentTree
{
	private:
		int *A, size;
	public:
		SegmentTree(int N)
		{
			size = 4*N+10;
			A = new int[size];
			for(int i=0;i<size;i++)
				A[i] = 0;
		}
		
		int update(int node, int s, int e, int p, int u)
		{
			if(s>p || e<p)
				return A[node];
			if(s==e)
				return (A[node] += u);
			int mid=(s+e)/2;
			return (A[node] = max(update(2*node, s, mid, p, u), update(2*node+1, mid+1, e, p, u)));
		}
		
		int query(int node, int s, int e, int rs, int re)
		{
			if(s>re || e<rs)
				return 0;
			if(s>=rs && e<=re)
				return A[node];
			int mid=(s+e)/2;
			return max(query(2*node, s, mid, rs, re), query(2*node+1, mid+1, e, rs, re));
		}
};

int main()
{
	ifstream inp("segment2.gir");
	ofstream oup("segment2.cik");
	int N,M;
	char c;
	int rs, re;
	
	inp >> M;
	SegmentTree st(1000000);
	for(int i=0;i<M;i++)
	{
		inp >> c;
		if(c=='Q')
		{
			inp >> rs >> re;
			oup << st.query(1, 1, 1000000, rs, re) << endl;
		}
		else
		{
			inp >> rs;
			st.update(1, 1, 1000000, rs, 1);
		}
	}
	
	return 0;
}

