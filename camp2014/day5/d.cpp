#include <iostream>
using namespace std;

int isPrime(int x)
{
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(x%2==0)
		return 0;
	for(int i=3;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	int N,res=0;
	cin >> N;
	for(int i=0;i<N;i++)
		res+=isPrime(i+1);
	cout << res << endl;
	
	return 0;
}


