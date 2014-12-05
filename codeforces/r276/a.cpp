#include <iostream>
using namespace std;

int main()
{
	int n;
	long long l,r;
	cin >> n;
	while(n--)
	{
		cin >> l >> r;
		for(int i=0;i<=60;i++)
			if(!(l>>i&1) && l+(1LL<<i)<=r)
				l|=1LL<<i;
		cout << l << endl;
	}
	return 0;
}

