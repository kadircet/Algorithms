#include <iostream>
using namespace std;

unsigned long A,B,K;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		int res=0;
		cin >> A >> B >> K;
		long na=0,nb=0,nk=0;
		while(na<A)na<<=1;
		while(nb<B)nb<<=1;
		while(nk<K)nk<<=1;
		
		nk--;na--;nb--;
		
		cout << "Case #" << t << ": " << res << endl;
	}
	
	return 0;
}

