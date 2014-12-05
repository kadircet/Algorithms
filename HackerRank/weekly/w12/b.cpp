#include <iostream>
using namespace std;

int C[100001];

int main()
{
	int N,h[100000];
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> h[i];
	
	for(int i=N-1;i>=0; i--)
		C[i] = max((h[i]+1)/2, (C[i+1]+h[i]+1)/2);
	
	cout << C[0] << endl;
	return 0;
}

