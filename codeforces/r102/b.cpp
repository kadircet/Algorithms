#include <iostream>
using namespace std;

int N,M;

int main()
{
	cin >> N >> M;
	if(M>N)
		swap(N,M);
	if(N==1 || M==1)
		cout << N*M << endl;
	else if(N==2 || M==2)
		cout << 2*(2*(N/4) + min(2, N%4)) << endl;
	else
		cout << (N*M+1)/2 << endl;
	
	return 0;
}

