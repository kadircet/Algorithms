#include <iostream>
using namespace std;

bool common(long a, long b)
{
	bool found[10];
	for(int i=0;i<10;i++)
		found[i] = false;
	while(a>0)
	{
		found[a%10] = true;
		a/=10;
	}
	while(b>0)
	{
		if(found[b%10])
			return true;
		b/=10;
	}		
	return false;
}

int main()
{
	long N,res=0;
	cin >> N;
	for(int i=1;i*i<=N;i++)
		if(N%i==0)
		{
			int t=common(N,i) + common(N, N/i);
			res+=t;
			if(t==2 && i==N/i)
				res--;
		}
		
	cout << res << endl;
	return 0;
}


