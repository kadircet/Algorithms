#include <iostream>
using namespace std;

int T;
int N,M;

int main()
{
	cin >> T;
	
	int sum, max, tmp;
	while(T--)
	{
		cin >> N >> M;
		sum = 0, max=0;
		for(int i=0;i<N;i++)
		{
			cin >> tmp;
			sum+=tmp;
			if(tmp>max)
				max=tmp;
		}
		
		M-=(max*N-sum);
		if(M%N)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	
	return 0;
}

