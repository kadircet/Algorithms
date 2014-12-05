#include <iostream>
using namespace std;

int main()
{
	int to7, to4;
	string a,b;
	
	cin >> a >> b;
	
	to7=to4=0;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i])
			if(b[i]=='4')
				to4++;
			else
				to7++;
	
	int res=to7+to4-min(to7, to4);
	
	cout << res << endl;
	return 0;
}

