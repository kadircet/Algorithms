#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
unsigned long long int numbers[1024];

int main()
{
	ifstream inp("kompici.gir");
	ofstream oup("kompici.cik");

	string number;
	bool count[10];
	inp >> N;
	int t=0;
	for(int i=0;i<N;i++)
	{
		t=0;
		for(int j=0;j<10;j++)
			count[j] = false;
		inp >> number;
		
		for(int j=0;j<number.length();j++)
		{
			int n = number[j] - '0';
			if(!count[n])
			{
				t |= 1<<n;
				count[n] = true;
			}
		}
		numbers[t]++;
	}
	
	unsigned long long int pals=0;
	for(int i=0;i<1024;i++)
		for(int j=i;j<1024;j++)
		{
			int s1=i;
			int s2=j;
			if(i==j)
				pals+=numbers[i]*(numbers[i]-1)/2;
			else if(s1&s2)
				pals+=numbers[i]*numbers[j];
		}
	oup << pals << endl;

	return 0;
}

