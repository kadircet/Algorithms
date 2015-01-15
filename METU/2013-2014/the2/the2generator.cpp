#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool use['z'-'a'+1];
string ops="&|>=-";

string gen(int last=0)
{
	int todo=rand()%2;
	int f,s,o;
	string res = "";
	o = rand()%ops.size();
	switch(todo)
	{
		case 0:
			f = rand()%('z'-'a'+1);
			s = rand()%('z'-'a'+1);
			while(!use[s])s = rand()%('z'-'a'+1);
			while(!use[f])f = rand()%('z'-'a'+1);
			if(ops[o]=='-')
			{
				res += ops[o];
				res += (char)(f+'a');
			}
			else
			{
				res += (char)(f+'a');
				res += ops[o];
				res += (char)(s+'a');
				res = "(" + res + ")";
			}
			return res;
		case 1:
			if(ops[o]!='-')
				return "(" + gen() + ops[o] + gen() + ")";
			return "-" + gen();
	}
	
	return "bisiktirgitamk";
}

int main()
{
	srand(time(NULL));
	
	for(int i=0;i<50;i++)
	{
		memset(use, 0, sizeof(use));
		int nc	= rand()%('z'-'a'+1)+1;
		int cc=0;
		while(cc<nc)
		{
			int r = rand()%('z'-'a'+1);
			while(use[r])r = rand()%('z'-'a'+1);
			use[r]=true;
			cc++;
		}
		cout << gen() << endl;
	}
	return 0;
}
