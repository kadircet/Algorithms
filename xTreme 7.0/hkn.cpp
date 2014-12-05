#include <iostream>
#include <cstdio>
using namespace std;

unsigned int flip(unsigned int n)
{
    int i, newInt = 0;
    for (i=0; n>0; ++i)
    {
        newInt += (n & 0x0001);
        newInt <<= 1;
        n >>= 1;
    }
    return newInt;
}

bool isPal(unsigned int n)
{
    int flipped = flip(n);
    while (!(flipped & 0x0001))
        flipped >>= 1;
    return n == flipped;
}

int main()
{
	unsigned int a,b;
	scanf("%d,%d", &a, &b);
	
	unsigned int res=0;
	for(unsigned long long int i=a;i<=b;i++)
		res += isPal(i);
	
	cout << res << endl;
	return 0;
}

