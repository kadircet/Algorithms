#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[100000], b[100000];
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >>a[i];
		b[i]=a[i];
	}	
	
	sort(a, a+N);
	
	int diff = 0;
	for(int i=0;i<N;i++)
		diff += a[i]!=b[i];
		
	if(diff==2 || diff == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}


