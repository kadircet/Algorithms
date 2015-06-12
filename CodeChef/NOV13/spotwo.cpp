#include <iostream>
#include <stack>
#define M 1000000007LL
using namespace std;

long long pow(long long a, unsigned long long b, long long m)
{
	if(b==1)
		return a%m;
	
	return b%2?(pow((a*a)%m, b/2, m)*a)%m:pow((a*a)%m, b/2, m)%m;
}

unsigned long long toBin(int n)
{
	stack<bool> bits;
	while(n>0)
		bits.push(n%2), n/=2;
	
	unsigned long long res=0;
	while(!bits.empty())
		res*=10, res+=bits.top(), bits.pop();
	
	return res;
}

int main()
{
	unsigned long long x = 10010010011111000000ULL;
	cin >> x;
	for(int i=0;i<100000;i++)
	{
		cin >> x;
		x=toBin(x);
		cout << (pow(2, x, M)*pow(2, x, M))%M << endl;
	}
	return 0;
}

