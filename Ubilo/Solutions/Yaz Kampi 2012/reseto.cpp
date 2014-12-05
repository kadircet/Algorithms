#include <iostream>
#include <fstream>
using namespace std;

bool numbers[2001];

int main()
{
	ifstream inp("reseto.gir");
	ofstream oup("reseto.cik");
	
	int N,K;
	inp >> N >> K;
	for(int i=2;i<=N;i++)
	{
		while(numbers[i])i++;
		for(int j=i;j<=N;j+=i)
		{
			if(numbers[j])
				continue;
			numbers[j] = true;
			K--;
			if(K<=0)
			{
				oup << j << endl;
				return 0;
			}
		}
	}
	return 0;
}

