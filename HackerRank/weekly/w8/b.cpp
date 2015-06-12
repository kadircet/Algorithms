#include <iostream>
using namespace std;

int A[1005], B[1005];
int N;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> A[i];
		B[0] = A[0];
		B[N] = A[N-1];
		for(int i=1;i<N;i++)
			B[i] = A[i-1]*A[i]/gcd(A[i], A[i-1]);
		for(int i=0;i<=N;i++)
			cout << B[i] << ' ';
		cout << endl;
	}
	
	return 0;
}
