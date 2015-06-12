#include <iostream>
#include <cstring>
using namespace std;

string inputs[101], norep[101];
int rep[101][101];
int grep[101][101];

int main()
{
	int N,T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> N;
		int nm=0;
		
		for(int i=0;i<N;i++)
			cin >> inputs[i];
		
		memset(grep, 0, sizeof(grep));
		for(int i=0;i<N;i++)
		{
			norep[i] = "" + inputs[i][0];
			rep[i][0] = 1;
			for(int j=1;j<inputs[i].size();j++)
				if(inputs[i][j]!=inputs[i][j-1])
				{
					norep[i] += inputs[i][j];
					rep[i][j] = 1;
				}
				else
					rep[i][j] = rep[i][j-1]+1;
		}
		
		bool found = false;
		
		cout << "Case #" << t << ": ";
		for(int i=0;i<N-1;i++)
			if(norep[i]!=norep[i+1])
			{
				cout << "Fegla Won" << endl;
				found = true;
				break;
			}
		if(found)
			continue;
		
		int ng=0;
		for(int i=0;i<N;i++)
		{
			ng=0;
			grep[i][ng]=1;
			for(int j=1;j<inputs[i].size();j++)
				if(inputs[i][j]==inputs[i][j-1])
					grep[i][ng]++;
				else
				{
					ng++;
					grep[i][ng]=1;
				}
		}
		
		int maxi, mini, cmin, cmax;
		int res=0;
		
		for(int i=0;i<ng;i++)
		{
			while(true)
			{
				maxi=mini=cmin=cmax=0;
				for(int j=0;j<N;j++)
				{
					if(grep[j][i]>grep[maxi][i])
						maxi = j;
					if(grep[j][i]<grep[mini][i])
						mini = j;
				}
			
				for(int j=0;j<N;j++)
				{
					if(grep[j][i]==grep[maxi][i])
						cmax++;
					if(grep[j][i]==grep[mini][i])
						cmin++;
				}
				
				if(cmax==cmin && cmax==N)
					break;
					
				mini=grep[mini][i], maxi=grep[maxi][i];
			
				if(cmax>cmin)
				{
					for(int j=0;j<N;j++)
						if(grep[j][i]==mini)
							grep[j][i]++;
				
					res += cmin;
				}
				else
				{
					for(int j=0;j<N;j++)
						if(grep[j][i]==maxi)
							grep[j][i]--;
				
					res += cmax;
				}
			}
		}
		
		cout << res << endl;
	}
	return 0;
}

