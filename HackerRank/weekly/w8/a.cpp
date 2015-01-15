#include <iostream>
using namespace std;

unsigned long pow[64];
bool ones[64];

int main()
{
	pow[0]=1;
	for(int i=1;i<64;i++)
		pow[i] = pow[i-1]*2;
		
	int T,nm;
	unsigned long N,k;
	cin >> T;
	while(T--)
	{
		nm=0, k=0;
		cin >> N;
		if(N==1)
		{
			cout << "Richard" << endl;
			continue;
		}
		for(int i=0;i<64;i++)
		{
			ones[i] = N&(1L<<i);
			k+=ones[i];
		}
			
		for(int i=63;i>=0 && k>1;i--)
			if(ones[i])
				nm++,k--,ones[i]=0;
		for(int i=0;i<64;i++)
			if(ones[i])
			{
				nm+=i;
				break;
			}
			
		if(nm%2)
			cout << "Louise";
		else
			cout << "Richard";
		cout << endl;
	}
	
	return 0;
}

