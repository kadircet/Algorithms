#include <iostream>
#include <fstream>
using namespace std;

class pack
{
	public:
		int o,n,w;
		friend istream& operator>>(istream&, pack&);
};

istream& operator>>(istream& is, pack& p)
{
	is >> p.o >> p.n >> p.w;
	return is;
}

pack p[1001];
int C[80][80];
int M,N,O;

int main()
{
	ifstream inp("ple.gir");
	ofstream oup("ple.cik");
	for(int i=0;i<80;i++)
		for(int j=0;j<80;j++)
			C[i][j] = -1;
	C[0][0] = 0;
		
	inp >> O >> N >> M;
	for(int i=0;i<M;i++)
		inp >> p[i];
	
	for(int k=0;k<1000;k++)	
		for(int i=N;i>=0;i--)
			for(int j=O;j>=0;j--)
			{
				if(C[i][j] != -1)
				{
					int tn = i+p[k].n;
					int to = j+p[k].o;
					if(tn>N)
						tn = N;
					if(to>O)
						to = O;
					int tw = C[i][j] + p[k].w;
					if(tw<C[tn][to] || C[tn][to] == -1)
						C[tn][to] = tw;
				}
			}
	oup << C[N][O] << endl;
	return 0;
}

