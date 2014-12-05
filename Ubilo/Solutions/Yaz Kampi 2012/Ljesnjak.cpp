#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char* words[] = {"c=", "c-", "dz=", "d-", "s=", "z=", "lj", "nj" };

bool inWords(char* word, int s, int l)
{
	for(int i=0;i<8;i++)
	{
		if(strlen(words[i])!=l)
			continue;
		if(strncmp(words[i], word+s, l)==0)
			return true;
	}
	return false;
}

int main()
{
	char *cword = new char[100];
	ifstream inp("ljesnjak.gir");
	ofstream oup("ljesnjak.cik");
	
	inp >> cword;
	cout << cword;
	int l = strlen(cword);
	for(int i=0;i<strlen(cword)-1;i++)
		for(int j=1;j<4;j++)
			if(inWords(cword, i, j))
			{
				l-=j;
				l++;
				i+=j-1;
				break;
			}
	oup << l << endl;
	return 0;
}
