#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
	int ln=0;
	string line;
	srand(time(NULL));
	
	while(cin.good())
	{
		cin >> line;
		if(!cin.good())
			break;
			
		int manip = rand()%100;
		for(int i=0;i<manip;i++)
		{
			int pos=rand()%line.size();
			int todo=rand()%2;
			int times=rand()%100+1;
			switch(todo)
			{
				case 0:
					line.insert(pos, "\n");
					break;
				case 1:
					for(int j=0;j<times;j++)
						line.insert(pos, " ");
					break;
			}
		}	
		
		stringstream filename;
		filename << "case_" << ln++ << ".in";
		
		ofstream file;
		file.open(filename.str().c_str());
		file << line << endl;
		file.close();
	}
}

