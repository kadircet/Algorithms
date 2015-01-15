#include <iostream>
#include <set>
using namespace std;

set<int> mis[100000];

int main()
{
	int N,t,f,cf,ct;
	cin >> N;
	cin >> ct >> cf;
	ct--;
	mis[ct].insert(cf);
	for(int i=1;i<N;i++)
	{
		cin >> t >> f;
		mis[t-1].insert(f);
	}
	mis[ct].erase(f);
	
	int res=0;
	bool found=true;
	while(found)
	{
		res++;
		found = false;
		for(int t=0;t<100000;t++)
		{
			if(mis[t].empty())
				continue;
			if(ct==-1)
				ct=t;
			set<int>::iterator it;
			for(it=mis[t].begin();it!=mis[t].end();it++)
			{
				if(t-ct>=*it-cf)
				{
					cf = *it;
					ct = t;
					mis[t].erase(it);
				}
				else
					found = true;
				break;
			}
			ct=-1;
		}
	}
	
	cout << res << endl;
	return 0;
}

