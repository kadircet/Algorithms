#include <iostream>
using namespace std;

int N,best;

int main()
{
	cin >> N;
	bool bug=false;
	int cur, ans, best;
	for(int i=0;i<N;i++)
	{
		cin >> cur;
		if(i==0)
		{
			ans = i;
			best = cur;
		}
		else
		{
			if(cur<best)
			{
				ans = i;
				best = cur;
				bug =false;
			}
			else if(cur==best)
				bug =true;
		}
	}
	
	if(bug)
		cout << "Still Rozdil" << endl;
	else
		cout << (ans+1) << endl;
	return 0;
}


