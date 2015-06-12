#include <iostream>
using namespace std;

int main()
{
	int N,k;
	cin >> N >> k;
	
	if(k>N || k==0)
		cout << -1 << endl;
	else if(k==1 && N>1)
		cout << -1 << endl;
	else
	{
		for(int i=0;i<N;i++)
		{
			if(i<N-k+2)
			{
				if(i%2)
					cout << 'b';
				else
					cout << 'a';
			}
			else
				cout << (char)('c'+i-(N-k+2));
		}
		cout << endl;
	}
	
	return 0;
}

