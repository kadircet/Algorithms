#include <iostream>
#include <map>
using namespace std;

map<string, bool> dict;
string cipher;

string ceaser(string w, int k)
{
	for(int i=0;i<w.size();i++)
		w[i] = (w[i]+k-'A')%26 + 'A';
	return w;
}

int main()
{
	cin >> cipher;
	
	int n;
	cin >> n;
	
	string word;
	for(int i=0;i<n;i++)
	{
		cin >> word;
		dict[word] = true;
	}
	return 0;
}

