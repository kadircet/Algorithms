#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

bool ent[128];

int main()
{
	string s;
	getline(cin, s);
	ent['"']=ent['\'']=ent['<']=ent['>']=ent['&']=true;
	
	int c=0;
	for(int i=0;i<s.size();i++)
		c+=ent[s[i]];
	if(c==0)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for(int i=0;i<s.size();i++)
		if(s[i]!='&' && ent[s[i]])
		{
			cout << 0 << endl;
			return 0;
		}
	
	int res=-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='&')
		{
			c=0;
			while(i+4<s.size()&&s[i+1]=='a'&&s[i+2]=='m'&&s[i+3]=='p'&&s[i+4]==';')
				i+=4,c++;
			if(i+3<s.size()&&s[i+1]=='l'&&s[i+2]=='t'&&s[i+3]==';')
				i+=3,c++;
			else if(i+3<s.size()&&s[i+1]=='g'&&s[i+2]=='t'&&s[i+3]==';')
				i+=3,c++;
			else if(i+5<s.size()&&s[i+1]=='a'&&s[i+2]=='p'&&s[i+3]=='o'&&s[i+4]=='s'&&s[i+5]==';')
				i+=3,c++;
			else if(i+5<s.size()&&s[i+1]=='q'&&s[i+2]=='u'&&s[i+3]=='o'&&s[i+4]=='t'&&s[i+5]==';')
				i+=3,c++;
			if(res==-1)
				res=c;
			res=min(res,c);
		}
	}
	cout << max(res,0) << endl;
	return 0;
}

