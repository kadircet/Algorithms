#include <iostream>
using namespace std;

long gcd(long a, long b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	long A,B;
	char q;
	
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> A >> q >> B;
		long g=gcd(A,B);
		A/=g, B/=g;
		
		while(A>=2 && B%2==0)
			A/=2, B/=2;
		int res=0;
		while(B%2==0)
			B/=2, res++;
		
		cout << "Case #" << t << ": ";
		if(B==1)
			cout << res << endl;
		else
			cout << "impossible" << endl;
	}
	
	return 0;
}

