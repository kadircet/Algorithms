#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int N;
long res;
bool used[101];
int count['z'+1];
string cars[101];

void generate(int cur, string last)
{
	if(cur==N)
	{
		int c=1;
		char prev=last[0];
		for(int i=1;i<last.size();i++)
		{
			if(prev==last[i])
				c++;
			else if(count[prev]==c)
				prev = last[i], c=1;
			else
				return;
		}
		res++, res%=MOD;
	}
	else
	{
		for(int i=0;i<N;i++)
			if(!used[i])
			{
				used[i]=true;
				generate(cur+1, last+cars[i]);
				used[i]=false;
			}
	}
}

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> N;
		memset(count, 0, sizeof(count));
		for(int i=0;i<N;i++)
		{
			cin >> cars[i];
			used[i]=false;
			for(int j=0;j<cars[i].size();j++)
				count[cars[i][j]]++;
		}
		
		res=0;
		generate(0, "");
		cout << "Case #" << t << ": " << res << endl;
	}
	
	return 0;
}

