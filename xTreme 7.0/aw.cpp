#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int N;
vector<string> words;
vector<string> encrypt;
map<char, char> table;
vector<bool> matched;

string toupper(string c)
{
	for(int i=0;i<c.size();i++)
		c[i] = toupper(c[i]);
	return c;
}

int main()
{
	cin >> N;
	string line;
	for(int i=0;i<N;i++)
	{
		cin >> line;
		words.push_back(toupper(line));
		matched.push_back(false);
	}
	
	while(true)
	{
		cin >> line;
		if(cin.eof())
			break;
		encrypt.push_back(line);	
	}
	
	bool match = true;
	for(int i=0;i<encrypt.size();i++)
	{
		int size=encrypt[i].size();
		for(int j=0;j<words.size();j++)
			if(words[j].size() == size&&!matched[j])
			{
				match=true;
				for(int k=0;k<size&&match;k++)
				{
					for(int q=k+1;q<size;q++)
						if(words[j][k] == words[j][q] && encrypt[i][k] != encrypt[i][q])
						{
							match = false;
							break;
						}
						else if(words[j][k] != words[j][q] && encrypt[i][k] == encrypt[i][q])
						{
							match = false;
							break;
						}
				}
				if(match)
				{
					matched[j] = true;
					cout << encrypt[i] << ' ' << words[j] << endl;
					for(int k=0;k<words[j].size();k++)
						table[encrypt[i][k]] = words[j][k];
					break;
				}
			}
	}
	
	for(int i=0;i<encrypt.size();i++, cout << ' ')
		for(int j=0;j<encrypt[i].size();j++)
			cout << table[encrypt[i][j]];
	cout << endl;
	return 0;
}

