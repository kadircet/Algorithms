#include <iostream>
using namespace std;

long long count[2001];

int main()
{
	long long N,C,S,x;
	cin >> S >> C >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> x;
		count[x]++;
	}
	
	long long best=0, price;
	for(int i=2000;i>=0;i--)
	{
		if(i!=2000)
			count[i] += count[i+1];
		long long prof = count[i]*i-(C+S*count[i]);
		if(prof>best)
		{
			best = prof;
			price = i;
		}
	}
	
	if(best==0)
		cout << "This winter is the last one!" << endl;
	else
		cout << price << endl;
	return 0;
}


