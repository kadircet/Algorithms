#include <iostream>
using namespace std;

bool told[100][100];

int main()
{
	int N,M,F,a,b,c;
	cin >> N >> M >> F;
	for(int i=0;i<N;i++)
		{
			cin >> a >> b >> c;
			a--,b--,c--;
			if(told[b][c])
			{
				cout << (a+1) << endl;
				return 0;
			}
			told[a][c]=true;
			told[b][c]=true;
		}
	cout << "april fools" << endl;
	
	return 0;
}


