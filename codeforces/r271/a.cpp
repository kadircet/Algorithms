#include <iostream>
using namespace std;

char* map[]=
{
	"qwertyuiop",
	"asdfghjkl;",
	"zxcvbnm,./"
};

char L[256], R[256];

int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<10;j++)
		{
			R[map[i][j]] = j>0?map[i][j-1]:0;
			L[map[i][j]] = j<9?map[i][j+1]:0;
		}
	
	string s;
	char t;
	cin >> t;
	cin >> s;
	for(int i=0;i<s.size();i++)
		if(t=='L')
			cout << L[s[i]];
		else
			cout << R[s[i]];
	cout << endl;
	
	return 0;
}

