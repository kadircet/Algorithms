#include <iostream>
#include <fstream>
using namespace std;

int N;
int A[100001];
int C[100001];

int main()
{
	ifstream inp("azalan.gir");
	ofstream oup("azalan.cik");
	inp >> N;
	for(int i=0;i<N;i++)
	{
		inp >> A[i];
		C[i] = 1;
	}
	for(int i=0;i<N;i++)
	{
		int c=1;
		for(int k=0;k<i;k++)
		{
			if(A[i]<A[k] && c<C[k]+1)
				c=C[k]+1;
		}
		C[i] = c;
	}
	int m=0;
	for(int i=0;i<N;i++)
		if(C[i] > m)
			m=C[i];
	oup << m << endl;
	return 0;
}

