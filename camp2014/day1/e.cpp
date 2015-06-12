#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int a[100000], b[100000];
int p[100000], diff[100000];
multiset<int > pos;
multiset<int, greater<int > > neg;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	for(int i=0;i<N;i++)
	{
		cin >> b[i];
		diff[i] = i - p[b[i]];
		if(diff[i]>=0)
			pos.insert(diff[i]);
		else
			neg.insert(diff[i]);
	}
	
	int a;
	multiset<int>::iterator it;
	multiset<int, greater<int> >::iterator nit;
	for(int i=0;i<N;i++)
	{
		it = pos.begin();
		nit = neg.begin();
		if(it!=pos.end())
			a = *it-i;
		if(nit!=neg.end() && i-*nit<a)
			a = i-*nit;
		cout << a << endl;
		
		int toRem = diff[i];
		if(toRem>=i)
			pos.erase(pos.find(toRem));
		else
			neg.erase(neg.find(toRem));
		pos.insert(N-p[b[i]]+i);
		diff[i] = N-p[b[i]]+i;
		
		it = pos.begin();
		while(*it==i)
		{
			neg.insert(i);
			pos.erase(it);
			it = pos.begin();
		}
	}
	
	return 0;
}

