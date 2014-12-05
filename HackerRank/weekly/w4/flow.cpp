#include <iostream>
using namespace std;
#define MOD 1000000009L

unsigned long C[5001];
unsigned long comb[5001][5001];

void calcC()
{
	C[0] = 1;
	
	for(int i=1;i<5001;i++)
		for(int j=0;j<i;j++)
			C[i] = (C[i] + C[j]*C[i-j-1])%MOD;
}

void calccomb()
{
	for(int i=0;i<5001;i++)
		comb[0][i] = comb[1][i] = 1;
		
	for(int i=2;i<5001;i++)
		for(int j=0;j<=i;j++)
			if(j==0 || j==i)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%MOD;
}

int main()
{
	calcC();
	calccomb();
	
	int T,N;
	unsigned long res;
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		res = 0;
		
		for(int i=1;i<=N;i++)
			res = (res + comb[N][i]*C[i])%MOD;
		
		cout << res << endl;
	}
	
	return 0;
}

