#include <iostream>
#include <string>
using namespace std;

int res(int k, string s1, string s2)
{
	int L=0;
	
	for(int diff=0;diff<s1.length();diff++)
	{
		int l=0,r=0;
		int miss=0;
		
		while(r+diff<s1.length() && (miss<k||s1[r]==s2[r+diff]))
		{
			miss += (s1[r] != s2[diff+r]);
			r++;
		}
		L = max(L, r-l);
		
		while(r+diff<s1.length())
		{
			while(l+diff+1<s1.length() && s1[l]==s2[diff+l])
				l++;
			if(l+diff+1<s1.length())
				l++;
				
			r++;
			while(r+diff+1<s1.length() && s1[r]==s2[diff+r])
				r++;
			
			L = max(L, r-l);
		}
	}
	
	return L;
}

int main()
{
	string s1,s2;
	int k, t;
	
	cin >> t;
	while(t--)
	{
		cin >> k >> s1 >> s2;
		cout << max(res(k, s1, s2),res(k, s2, s1)) << endl;
	}
	
	return 0;
}

