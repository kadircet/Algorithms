#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	string inp;
	
	cin >> T;
	while(T--)
	{
		cin >> inp;
		int b=0, res=0;
		for(int i=1;i<inp.size();i++)
			if(inp[b] == inp[i])
				res++;
			else
				b=i;
		cout << res << endl;
	}
	
	return 0;
}

