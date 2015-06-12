#include <iostream>
#define MOD 1000000007UL
using namespace std;

bool got[15];
int num[16];
unsigned long N,K;
unsigned long init[15];
unsigned long mat[15][15], base[15][15];

void genInit(int cur)
{
	if(cur>15)
		return;
	
	if(cur>0)
		init[cur-1] = (init[cur-1]+1)%MOD;
		
	for(int i=0;i<K;i++)
		genInit(cur+num[i]);
}

unsigned long temp[15][15], res[15][15];
void multMat(unsigned long a[][15], unsigned long b[][15])
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			temp[i][j] = 0;
			
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			for(int k=0;k<15;k++)
				temp[i][j] = (temp[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
				
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			res[i][j] = temp[i][j];
}

void expMat(long N)
{
	if(N==1)
		return;
	
	expMat(N/2);
	multMat(mat, mat);
	if(N%2)
		multMat(res, base);
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			mat[i][j] = res[i][j];
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<K;i++)
	{
		cin >> num[i];
		got[num[i]-1] = true;
	}
	
	genInit(0);
	for(int i=0;i<15;i++)
		for(int j=0;j<14;j++)
			mat[i][j] = base[i][j] = i==(j+1);
	
	for(int i=0;i<15;i++)
		mat[i][14] = base[i][14] = got[14-i];

	if(N>15)
	{
		expMat(N-15);
		
		unsigned long res = 0;
		for(int i=0;i<15;i++)
			res = (res + mat[i][14]*init[i]%MOD)%MOD;
		cout << (res*2)%MOD << endl;
	}
	else
		cout << (init[N-1]*2)%MOD << endl;
	
	return 0;
}

