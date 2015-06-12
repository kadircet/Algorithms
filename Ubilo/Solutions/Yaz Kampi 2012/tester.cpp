#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	ofstream oup("azalan.gir");
	oup << 100000 << endl;
	for(int i=0;i<100000;i++)
		oup << rand() << endl;
	return 0;
}

