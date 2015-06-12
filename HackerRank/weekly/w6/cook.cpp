#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct task
{
	long st;
	long time;
	
	bool operator<(const task t) const
	{
		if(st==t.st)
			return time<t.time;
		return st<t.st;
	}
	
	bool operator()(const task lhs, const task rhs) const
	{
		if(lhs.time==rhs.time)
			lhs.st>rhs.st;
		return lhs.time>rhs.time;
	}
};

priority_queue<task, vector<task>, task> avtasks;
vector<task> tasks;

int main()
{
	int N;
	cin >> N;
	
	tasks.resize(N);
	for(int i=0;i<N;i++)
		cin >> tasks[i].st >> tasks[i].time;
	
	sort(tasks.begin(), tasks.end());
	avtasks.push(tasks[0]);
	
	int done = 0, last=0;
	unsigned long time = tasks[0].st;
	unsigned long res = 0;
	while(done<N)
	{
		if(avtasks.empty())
		{
			last++;
			avtasks.push(tasks[last]);
			time = tasks[last].st;
		}
		task cur = avtasks.top();
		avtasks.pop();
		
		time += cur.time;
		for(int i=last+1;i<N && tasks[i].st<=time;i++)
			avtasks.push(tasks[i]), last=i;
			
		res += time - cur.st;
		done++;
	}
	
	cout << res/N << endl;
	return 0;
}

