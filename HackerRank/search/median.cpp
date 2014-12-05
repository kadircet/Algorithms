#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
	multiset<long long> left, right;
	int n;
	char c;
	long long x;
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		bool valid = true;
		cin >> c >> x;
		if(c=='r')
		{
			multiset<long long>::iterator li = left.find(x),
											ri = right.find(x);
			if(li!=left.end())
				left.erase(li);
			else if(ri!=right.end())
				right.erase(ri);
			else
				valid=false;
		}
		else if(c=='a')
		{
			if(left.empty() || x < *left.rbegin())
				left.insert(x);
			else
				right.insert(x);
		}
		
		if(left.size() > 1 + right.size())
		{
			right.insert(*left.rbegin());
			left.erase(left.find(*left.rbegin()));
		}
		else if(right.size() > left.size())
		{
			left.insert(*right.begin());
			right.erase(right.find(*right.begin()));
		}
		
		if(valid && (!left.empty() || !right.empty()))
		{
			if(left.size()>right.size())
				cout << *left.rbegin() << endl;
			else
			{
				long long m = *left.rbegin() + *right.begin();
				if(m%2)
					printf("%.1lf", m/2.);
				else
					printf("%.0lf", m/2.);
				cout << endl;
			}
		}
		else
			cout << "Wrong!" << endl;
	}
	return 0;
}

