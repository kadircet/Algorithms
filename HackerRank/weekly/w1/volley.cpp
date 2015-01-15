/*
f(0,0) = 1
f(1,0) = f(0,0)
f(x,y) = f(y,x)
f(x,y) = f(x-1,y) + f(x,y-1)
*/
#include <iostream>
#include <cmath>
#define MOD 1000000007
using namespace std;

unsigned long f[25][25];

unsigned long pow2(long n)
{
	if(n==0)
		return 1;
	
	long sq = pow2(n/2)%MOD;
	return (sq*sq*(n%2?2:1))%MOD;
}

int main()
{
	f[0][0] = 1;
	for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
			if(!(i|j))
				continue;
			else
				f[i][j] = ((i>0?f[i-1][j]:0)+(j>0?f[i][j-1]:0))%MOD;
				
	int A,B;
	cin >> A >> B;
	unsigned long res;
	
	if(A>=24 && B>=24)
	{
		if(abs(A-B)!=2)
			res = 0;
		else
		{
			int to=min(A,B)-24;
			res = (pow2(to)*f[24][24])%MOD;
		}
	}
	else if(max(A,B)==25)
		res = f[24][min(A,B)];
	else
		res = 0;
	
	cout << res << endl;
	return 0;
}

