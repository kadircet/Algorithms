#include <iostream>
using namespace std;

int ways(int k, int n)
{
	if(k==1)
		return 2;
	return ways(k-1, n-2)*(n-2);
}

int main()
{
	int N,K;
	cin >> N >> K;
	while(N!=0 && K!=0)
	{
		cout << ways(K, N) << endl;
		/*if(K==1)
			cout << 2 << endl;
		else if(K==2)
			cout << 2*(N-2) << endl;
		*/cin >> N >> K;
	}
	
	return 0;
}

