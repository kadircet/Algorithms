#include <iostream>
using namespace std;

char mod(char c, int mod)
{
	
}

int main()
{
	string text, cipher;
	cin >> text;
	while(text!=".")
	{
		cin >> cipher;
		
		for(int i=0;i<cipher.size();i++)
			cipher[i] = mod(cipher[i]-text[i], 26);
		
		cin >> text;
	}
	return 0;
}

