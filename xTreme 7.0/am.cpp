#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > mat;
vector<vector<int> > dp;

void genPath(int r, int c)
{
	if(r==0)
	{
		cout << '[' << r << ',' << c << ']';
		return;
	}
	int m=dp[r-1][c>0?c-1:c], mc=c>0?c-1:c;
	if(dp[r-1][c] < m)
		m=dp[r-1][c], mc=c;
	if(c+1<mat[0].size() && dp[r-1][c+1] < m)
		m=dp[r-1][c+1], mc=c+1;
	genPath(r-1, mc);
	cout << '[' << r << ',' << c << ']';
}

int main()
{
	int r,c,t;
	cin >> r >> c;
	for(int i=0;i<r;i++)
	{
		vector<int> line;
		for(int j=0;j<c;j++)
		{
			cin >> t;
			line.push_back(t);
		}
		mat.push_back(line);
	}
	
	dp.push_back(mat[0]);
	for(int i=1;i<r;i++)
	{
		vector<int> line;
		for(int j=0;j<c;j++)
		{
			int m = dp[i-1][j];
			if(j<c-1)
				m = min(m, dp[i-1][j+1]);
			if(j>0)
				m = min(m, dp[i-1][j-1]);
			line.push_back(mat[i][j]+m);
		}
		dp.push_back(line);
	}
	
	int m = dp[r-1][0],mi=0;
	for(int i=1;i<c;i++)
		if(m > dp[r-1][i])
			m = min(dp[r-1][i], m), mi=i;
		
	/*for(int i=0;i<r;i++, cout << endl)
		for(int j=0;j<c;j++)
			cout << dp[i][j] << ' ';
	*/
	cout << "Minimum risk path = ";
	genPath(r-1, mi);
	cout << endl;
	cout << "Risks along the path = " << m << endl;
	return 0;
}

