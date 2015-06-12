#include <iostream>
#include <string>
using namespace std;

int count(string s)
{
	int l=0,r=s.size()-1;
		
	int flag=0;
	while(l<=r && flag<2)
	{
		if(s[l]==s[r])
			l++,r--;
		else
		{
			flag++;
			if(s[l+1]==s[r])
				l++;
			else if(s[l]==s[r-1])
				r--;
			else
				flag++;
		}
	}
	
	return flag;
}

string rev(string s)
{
	string revs;
	revs.resize(s.size());
	for(int i=0;i<s.size();i++)
		revs[i] = s[s.size()-1-i];
	
	return revs;
}

int main()
{
	int T;
	string s;
	cin >> T;
	while(T--)
	{
		cin >> s;
		if(count(s)>1 && count(rev(s))>1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	
	return 0;
}

