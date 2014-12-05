#include <iostream>
using namespace std;

int main()
{
	string s;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		int i,e;
		for(i=0, e=s.size()-1;i<e;i++,e--)
			if(s[i]!=s[e])
			{
				if(s[i+1]==s[e])
					cout << i << endl;
				else
					cout << e << endl;
				break;
			}
		
		if(s[i]==s[e])
			cout << "-1" << endl;
	}
	
	return 0;
}

