#include <iostream>
#define MOD 123456789L
using namespace std;

unsigned long C[100003];
unsigned long up[100003];

int main()
{
	C[0]=1;
	up[0]=0;
	/*for(int i=1;i<100003;i++)
	{
		C[i] = ((C[i-1]*(4*(i-1)+2)))%MOD;
		while(C[i]%(i+1))
			C[i]+=MOD;
		C[i] = (C[i]/(i+1))%MOD;
	}*/
	
	for(int i=1;i<100003;i++)
		for(int j=0;j<i;j++)
		{
			C[i] = (C[i]+C[j]*C[i-j-1])%MOD;
			up[i] = (up[i]+up[j]*C[i-j-1]+up[i-j-1]*C[j])%MOD;
		}
	
	int N,M;
	cin >> M >> N;
	
	unsigned long cur=0,res=0;
	for(int i=M;i<=N;i++)
	{
		cur+=C[i];
		if(cur>MOD)
		{
			res=(res+cur/MOD)%MOD;
			cur%=MOD;
		}
		res=(res+up[i])%MOD;
	}
	if(cur>0)
		res++;
	cout << res << endl;
	return 0;
}

