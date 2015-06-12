#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool poss[100*100+1];

int main()
{
	int T,N,G;
	cin >> T;
	while(T--)
	{
		vector<int> A;
		cin >> N >> G;
		A.resize(N);
		int tot=0;
		for(int i=0;i<N;i++)
		{
			cin >> A[i];
			tot+=A[i];
		}
		
		memset(poss, false, sizeof(poss));
		poss[0] = true;
		for(int i=0;i<N;i++)
			for(int c=tot;c>=A[i];c--)
				if(poss[c-A[i]])
					poss[c] = true;
		
		bool found = false;
		for(int c=0;c<=tot;c++)
			if(poss[c] && c<=G && tot-c<=G)
			{
				cout << "YES" << endl;
				found = true;
				break;
			}
		if(!found)
			cout << "NO" << endl;
	}
	
	return 0;
}

