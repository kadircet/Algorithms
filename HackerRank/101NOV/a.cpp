#include <iostream>
using namespace std;

bool seen[256];
int T;
string A,B;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> A >> B;
		for(int i=0;i<256;i++)
			seen[i] = false;
		for(int i=0;i<A.size();i++)
			seen[A[i]] = true;
		
		bool flag=false;
		for(int i=0;i<B.size();i++)
			if(seen[B[i]])
			{
				flag=true;
				break;
			}
		if(flag)
			cout << "YES";
		else
			cout << "NO";
		cout <<endl;
	}
}
