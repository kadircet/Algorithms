#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> S;
int main()
{
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
		S.push_back(s[i]);
	sort(S.begin(), S.end());
	
	for(int i=0;i<S.size();i++)
		cout << S[i];
	cout << endl;
	return 0;
}

