#include <iostream>
using namespace std;

int main()
{
	int N, a, b;
	int mina, minb;
	cin >> N;
	cin >> mina >> minb;
	N--;
	while(N--)
	{
		cin >> a >> b;
		mina = min(mina, a);
		minb = min(minb, b);
	}
	cout << (long)mina*minb << endl;
	return 0;
}

