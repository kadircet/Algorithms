#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K, Q, q;
	cin >> N >> K >> Q;
	
	vector<int> A(N);
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	for(int i=0;i<Q;i++)
	{
		cin >> q;
		cout << A[((q-K)%N+N)%N] << endl;
	}
	
	return 0;
}

