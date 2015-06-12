#include <iostream>
using namespace std;

double s[10000001], sum;

int main()
{
	int N;
	cin >> N;
	
	s[0] = 0, s[1] = 1;
	for(int i=2;i<=N;i++)
	{
		s[i] = (double)i/(i-1)*((double)(i+1)/2+sum/i);
		sum += s[i];
	}
	cout.precision(10);
	cout << s[N] << endl;
	return 0;
}

