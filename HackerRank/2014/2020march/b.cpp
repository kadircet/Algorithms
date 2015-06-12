#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int count[2];

int main()
{
	int T;
	string s;
	cin >> T;
	while(T--)
	{
		cin >> s;
		if(s.size()==1)
		{
			if((s[0]-'0')%8)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
			continue;
		}
		bool found=false;
		memset(count, 0, sizeof(count));
		//count[0]=10;
		for(int i=0;i<s.size();i++)
			count[(s[i]-'0')%2]++;
		for(int i=0;i<s.size() && !found;i++)
			for(int j=0;j<s.size();j++)
			{
				if(i==j)
					continue;
				int q = (s[i]-'0')*2 + (s[j]-'0');
				q = (8-q%8)%8;
				count[(s[i]-'0')%2]--;
				count[(s[j]-'0')%2]--;
				if((q==0 && (s.size()==2 || count[0])) || (q==4 && count[1]))
				{
					cout << "YES" << endl;
					found = true;
					break;
				}
				count[(s[i]-'0')%2]++;
				count[(s[j]-'0')%2]++;
			}
		if(!found)
			cout << "NO" << endl;
	}
	return 0;
}

