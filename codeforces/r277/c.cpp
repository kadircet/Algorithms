#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, p, first=-1, last=-1, alph='z'-'a'+1, d;
	string s;
	
	cin >> n >> p >> s;
	if(2*p>n)
		p=n-p+1;
	
	long long res=0;
	for(int l=0,r=n-1; l<=r;l++,r--)
	{
		if(s[l]!=s[r])
		{
			last=l+1;
			if(first==-1)
				first=l+1;
			
			d=abs(s[r]-s[l]);
			res+=min(d, alph-d);
		}
	}
	if(first!=-1)
		res+=min(abs(p-last), abs(p-first)) + last-first;
	cout << res << endl;
	return 0;
}

