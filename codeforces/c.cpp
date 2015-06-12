#include <iostream>
using namespace std;

int main()
{
	long long N,t,res=0;
	cin >> N;
	
	for(long long i=1;i<=1000000;i++)
	{
		t = N+i;
		if(t%3)
			continue;
		t/=3;
		if(2*t>=i*(i+1))
			res++;
	}
	cout << res << endl;
	
	return 0;
}

