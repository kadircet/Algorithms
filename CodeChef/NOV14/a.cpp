#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T;
	string s;
	cin >> T;
	while(T--)
	{
		cin >> s;
		sort(s.begin(), s.end());
		int res=1;
		for(int i=1;i<s.size();i++)
			res += s[i]!=s[i-1];
		cout << res << endl;
	}
	
	return 0;
}

