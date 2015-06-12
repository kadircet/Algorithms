#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<bool> used;
int mid(pair<int, int> x)
{
	return (x.first + x.second) >> 1;
}

class Task
{
	public:
		int idx, d, m;
		
		bool operator<(const Task& t) const
		{
			if(this->d!=t.d)
				return this->d < t.d;
			if(this->m!=t.m)
				return this->m > t.m;
			return this->idx < t.idx;
		}
};

template<class T>
class Node
{
	private:
		pair<int, int> interval;
		
		void push()
		{
			left->val += this->add;
			left->add += this->add;
			right->val += this->add;
			right->add += this->add;
			this->add = 0;
		}
	
	public:
		T val, add, idx;
		
		Node()
		{
			this->add=0;
			this->left= this->right = NULL;
		}
		
		void build(int s, int e)
		{
			//cout << s << ' ' << e << endl;
			this->add=0;
			this->val=0;
			this->idx=s;
			interval.first=s, interval.second=e;
			if(s==e)
				return;
			
			this->left=new Node<T>();
			this->right=new Node<T>();
			int m = mid(this->interval);
			this->left->build(s, m);
			this->right->build(m+1, e);
		}
		
		void update(int s, int e, int v)
		{
			if(s<=interval.first && interval.second<=e)
			{
				this->val += v;
				this->add += v;
				return;
			}
			if(this->add)
				this->push();
			int m = mid(this->interval);
			if(s<=m)
				left->update(s, e, v);
			if(m<e)
				right->update(s, e, v);
			
			Node mn = max(*left, *right);
			this->val = mn.val;
			this->idx = mn.idx;
		}
		
		Node query(int s, int e)
		{
			if(s<=interval.first && interval.second<=e)
				return *this;
			
			if(this->add)
				this->push();
			int m = mid(this->interval);
			
			if(e<=m)
				return left->query(s, e);
			else if(s>m)
				return right->query(s, e);
			else
				return max(left->query(s, m), right->query(m+1, e));
		}
		
		bool operator<(const Node& x) const
		{
			if(!used[this->idx])
				return true;
			if(!used[x.idx])
				return false;
			return this->val < x.val;
		}
		Node<T> *left, *right;
};

template<class T>
class BIT
{
	private:
		vector<T> A;
	
	public:
		BIT(int n)
		{
			A.resize(n);
		}
		
		T get(int idx)
		{
			T res=0;
			while(idx)
			{
				res+=A[idx];
				idx -= idx&-idx;
			}
			return res;
		}
		
		void update(int idx, T val=1)
		{
			while(idx<=A.size())
			{
				A[idx] += val;
				idx += idx&-idx;
			}
		}
};

int main()
{
	int T;
	cin >> T;
	vector<Task> task(T);
	used.resize(T+10);
	for(int i=0;i<T;i++)
		cin >> task[i].d >> task[i].m, task[i].idx=i;
	
	sort(task.begin(), task.end());
	vector<int> rank(T);
	for(int i=0;i<T;i++)
		rank[task[i].idx] = i;
	
	int ans=0;
	BIT<int> sum(T+10);
	Node<int> segT;
	segT.build(1, T);
	
	for(int i=0;i<T;i++)
	{
		int idx=rank[i]+1, res;
		
		sum.update(idx, task[idx-1].m);
		used[idx] = true;
		
		segT.update(idx, idx, -task[idx-1].d);
		segT.update(idx, T, task[idx-1].m);
		
		//cout << sum.get(idx+1) << ' ' << task[idx].d << endl;
		
		res = max(0, sum.get(idx) - task[idx-1].d);
		if(idx+1 <= T)
		{
			//cout << "lan:" << idx+1 << endl;
			Node<int> r = segT.query(idx+1, T);
			if(used[r.idx])
			{
				res = max(res, sum.get(r.idx) - task[r.idx-1].d);
				//cout << r.idx << ' ' << sum.get(r.idx) << ' ' << task[r.idx-1].d << endl;
			}
		}
		
		ans = max(res, ans);
		cout << ans << endl;
	}
}

