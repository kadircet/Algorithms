#include <iostream>
using namespace std;

int dp[1900][1900],M[1900];
int u[1900][1900];

int main()
{
	int N,H,I,tmp,t2;
	cin >> N >> H >> I;
	for(int i=0;i<N;i++)
	{
		cin >> t2;
		for(int j=0;j<t2;j++)
		{
			cin >> tmp;
			u[i][tmp-1]++;
		}
	}
	
	H--;
	for(int f=H;f>=0;f--)
		for(int b=0;b<N;b++)
		{
			dp[b][f]=u[b][f];
			if(f!=H)
				dp[b][f]+=dp[b][f+1];
			if(f+I<=H)
				dp[b][f]=max(dp[b][f], M[f+I]+u[b][f]);
			M[f]=max(M[f], dp[b][f]);
		}
	
	cout << M[0] << endl;
	return 0;
}

