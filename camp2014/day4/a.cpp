#include <iostream>
using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;
	int a,b;
	long long res=0;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		res += b-a+1;
	}
	
	res%=K;
	res = (K-res)%K;
	cout << res << endl;
	
	return 0;
}


