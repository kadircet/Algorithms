#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pipe
{
	int x,y,z;
	
	bool operator<(const pipe left) const
	{
		if(x!=left.x)
			return x<left.x;
		if(y!=left.y)
			return y<left.y;
		return z<left.z;
	}
};

vector<pipe> pipes;
int nodes[400000], N;

void update(int node, int l, int r, int q, int val)
{
	if(q<l || r<q)
		return;
	if(l==r && q==l)
	{
		nodes[node] = max(val, nodes[node]);
		return;
	}
	update(2*node, l, (l+r)/2, q, val);
	update(2*node+1, (l+r)/2+1, r, q, val);
	
	nodes[node] = max(nodes[2*node], nodes[2*node+1]);
}

int query(int node, int l, int r, int ql, int qr)
{
	if(qr<l || r<ql)
		return 0;
	if(ql<=l && r<=qr)
		return nodes[node];
	
	int left = query(2*node, l, (l+r)/2, ql, qr),
		right= query(2*node+1, (l+r)/2+1, r, ql, qr);
	return max(left, right);
}

int main()
{
	cin >> N;
	pipes.resize(N);
	for(int i=0;i<N;i++)
		cin >> pipes[i].x >> pipes[i].y >> pipes[i].z;
	sort(pipes.rbegin(), pipes.rend());
	
	int res=0;
	for(int i=0;i<N;i++)
	{
		if(query(1, 1, 100000, pipes[i].y, 100000)>=pipes[i].z)
			res++;
		update(1, 1, 100000, pipes[i].y, pipes[i].z);
	}
	cout << res << endl;
	return 0;
}

