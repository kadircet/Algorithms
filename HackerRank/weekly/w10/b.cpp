#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,K;
	string s;
	cin >> N >> K >> s;
	
	vector<int> bits(N);
	
	int cur = 0;
	for(int i=0;i<N;i++)
	{
		if(i>=K)
			cur ^= bits[i-K];
		bits[i] = (s[i]-'0')^cur;
		cur ^= bits[i];
		cout << bits[i];
	}
	cout << endl;
	return 0;
}

