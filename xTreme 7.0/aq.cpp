#include <iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	string inp, last;
	cin >> inp;
	cin >> last;
	for(int i=0;i<(1<<n)-2;i++)
	{
		cin >> inp;
		if(last==inp)
			m--;
		if(m==0)
		{
			cout << 1 << endl;
			return 0;
		}
		last=inp;
	}
	cout << 0 << endl;
	return 0;
}

