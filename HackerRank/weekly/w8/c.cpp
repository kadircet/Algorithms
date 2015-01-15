#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long mat[3][3] =
{
	{1, 1, 0},
	{0, 0, 1},
	{1, 0, 0}
};
long start[3] = {4,3,2};

vector<vector<long> > expmat(int pow, vector<vector<long> >& mmat)
{
	if(pow==1)
		return mmat;
	
	vector<vector<long> > nmat(3, vector<long>(3)), rmat(3, vector<long>(3));
	rmat = expmat(pow/2, mmat);
	
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			nmat[i][j] = 0;
	
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				nmat[i][j] = (nmat[i][j]+rmat[i][k]*rmat[k][j])%MOD;
	if(pow&0x01)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				rmat[i][j] = 0;
				
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					rmat[i][j] = (rmat[i][j]+nmat[i][k]*mmat[k][j])%MOD;
		return rmat;
	}
	return nmat;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long N;
		cin >> N;
		
		if(N<4)
			cout << N+1;
		else
		{
			N-=3;
			vector<vector<long> > qmat(3, vector<long>(3));
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					qmat[i][j] = mat[i][j];
			qmat = expmat(N, qmat);
			
			long res = 0;
			for(int i=0;i<3;i++)
				res = (res + start[i]*qmat[i][0])%MOD;
			cout << res;
		}
		cout << endl;
	}
	
	return 0;
}

