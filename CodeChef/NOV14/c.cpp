#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int T;
	long long X,K,t;
	cin >> T;
	cout.precision(15);
	while(T--)
	{
		cin >> X >> K;
		t=0;
		while(2*t+1<K)
			t=2*t+1;
		
		cout << fixed << (K-t-1+0.5)*X/(t+1.0) << endl;
	}
	
	return 0;
}

