#include <iostream>
using namespace std;

unsigned long count[10000];
unsigned long C[1000][1000];

long comb(int n, int k)
{
	if(k==0 || k==n)
		return 1;
	if(k==1)
		return n;
		
	if(C[n][k])
		return C[n][k];
	return C[n][k] = comb(n-1, k-1) + comb(n-1, k);
}

int main()
{
	count[2]=2;
	for(int i=4;count[i-2]<=2000000000;i+=2)
		count[i] = comb(i, i/2) + count[i-2];
	
	unsigned long K,pos;
	cin >> K;
	if(K==1)
		cout << 47 << endl;
	else if(K==2)
		cout << 74 << endl;
	else
	{
		for(pos=2;pos<100;pos+=2)
			if(count[pos]>=K)
				break;
		
		//cout << "digits:" << pos << endl;
		K-=count[pos-2];
		K--;
		//cout << K << endl;
		int n7=pos/2, n4=pos/2;
		for(int i=0;i<pos && n7>0 && n4>0;i++)
		{
			if(K>=comb(pos-i-1, n7))
			{
				K-=comb(pos-i-1, n7);
				cout << 7;
				n7--;
			}
			else
				cout << 4, n4--;
		}
		while(n4>0)
			cout << 4, n4--;
		while(n7>0)
			cout << 7, n7--;
		cout << endl;
	}
	
	return 0;
}

