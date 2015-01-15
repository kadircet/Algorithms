#include <iostream>
#include <fstream>
using namespace std;

unsigned long long int N;

int main()
{
	ifstream inp("jumps.gir");
	ofstream oup("jumps.cik");
	
	inp >> N;
	unsigned long long int t=0;
	if(N<6)
		oup << N << endl;
	else
	{
		if(N%6==5)
		{
			t=(N/3)%1000000;
			int m = N+N%3+3;
			m/=2;
			t=(t*m-1)%1000000;
			t=t/2;
			t=(t+N/3)%1000000;
			t=t+2;
		}
		else if(N%6==1)
		{
			t=(N/3)%1000000;
			int m = N+N%3+3;
			m/=2;
			t=(t*m-1)%1000000;
			t=t/2;
			t=(t+N/3)%1000000;
			t=t+2;
		}
		else if(N%6==0)
		{
			t=(N/3)%1000000;
			int m = N+N%3+3;
			m/=2;
			t=(t*m)%1000000;
			t=t/2;
			t=(t+N/3)%1000000;
			t=t+1;
		}
		else if(N%3!=2)
		{
			t=((N/3+1)*((N+N%3)/2)/2)%1000000+N/3+1;
		}
		else if(N%3==2)
		{
			t=(N/3)%1000000;
			int m = N+5;
			m/=2;
			t=(t*m)%1000000;
			t=t/2;
			t=(t+N/3)%1000000;
			t=t+2;
		}
		oup << t%1000000 << endl;
	}
	return 0;
}

