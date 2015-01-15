#include <iostream>
#define M 1000000007LL
using namespace std;

long long pow(long long a, int b, int m)
{
	if(b==1)
		return a%m;
	
	return b%2?(pow((a*a)%m, b/2, m)*a)%m:pow((a*a)%m, b/2, m)%m;
}

int main()
{
	int N,T;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << (pow(2, N, M)+M - 1)%M << endl;
	}
	return 0;
}

