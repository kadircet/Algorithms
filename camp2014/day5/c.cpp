#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
long long fact[17];
long long a[17];

int main()
{
	fact[1] =1;
	for(int i=2;i<17;i++)
		fact[i] = fact[i-1]*i;
	a[1] = 0;
	a[2] = 1;
	for(int i=3;i<17;i++)
		a[i] = (i-1)*(a[i-1]+a[i-2]);
	
	int N;
	cin >> N;
	long long g = gcd(a[N], fact[N]);
	cout << a[N]/g << '/' << fact[N]/g << endl;
	
	return 0;
}

