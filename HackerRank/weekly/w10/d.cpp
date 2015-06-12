#include <iostream>
using namespace std;

int N;
unsigned long V[500000], P[500000], suff[500000];

unsigned long f(int x, int e)
{
	if(x==N-1)
		return V[x];
	if(e==0)
		return f(x+1, P[x]-1);
	if(e>=N-1-x)
		return suff[x];
	
	if(V[x] == 0)
	{
		if(P[x] > e)
			return f(x+1, P[x]-1);
		else
			return f(x+1, e-1);
	}
	
	if(e>P[x])
		return V[x] + f(x+1, e-1);
	
	return max(V[x] + f(x+1, e-1), f(x+1, P[x]-1));
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> V[i] >> P[i];
		
	suff[N-1] = V[N-1];
	for(int i=N-2;i>=0;i--)
		suff[i] = suff[i+1] + V[i];
	
	cout << f(0,0) << endl;
	return 0;
}

