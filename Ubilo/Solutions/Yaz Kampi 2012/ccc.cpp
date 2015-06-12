#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inp("ccc.gir");
	ofstream oup("ccc.cik");
	
	string a;
	inp >> a;
	oup << a << endl;
	return 0;
}

