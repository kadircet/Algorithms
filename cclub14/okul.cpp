#include <iostream>
#include <string>
using namespace std;

string numbers[] = {"sifir", "bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz",
					"dokuz", "on"};
string groups[] = {"sifirli", "birli", "ikili", "uclu", "dortlu", "besli", "altili",
					"yedili", "sekizli", "dokuzlu", "onlu"};
int main()
{
	int T;
	string N,F;
	
	cin >> T;
	while(T--)
	{
		cin >> N >> F;
		int cur=0, idx=0;
		for(int i=0;i<=F.size();i++)
		{
			if(i==F.size() || F[i]=='-')
			{
				//cout << cur << " : ";
				int count=1;
				char last=N[idx];
				for(int j=1;j<=cur;j++)
				{
					if(N[idx+j]!=last || j==cur)
					{
						if(1<count && count<=10)
							cout << groups[count] << ' ' << numbers[last-'0'] << ' ';
						else if(count==1)
							cout << numbers[last-'0'] << ' ';
						else
							for(int k=0;k<count;k++)
								cout << numbers[last-'0'] << ' ';
						
						count = 1;
						last = N[idx+j];
					}
					else
						count++;
				}
				idx+=cur;
				cur=0;
				if(i==F.size())
					break;
				i++;
			}
			
			cur *= 10;
			cur += F[i]-'0';
		}
		cout << endl;
	}
	
	return 0;
}

