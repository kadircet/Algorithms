#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int base10(string n)
{
	int res=0;
	for(int i=n.size()-1;i>=0;i--)
		res += (n[i]-'0')*(1<<(n.size()-i-1));
	return res;
}

int main()
{
	int n,c;
	string inp;
	cin >> n >> c;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<c/8;j++)
		{
			cin >> setw(8) >> inp;
			cout << base10(inp) << endl;
		}
	}
	return 0;
}

