#include <iostream>
using namespace std;

int pot[1000001];
int a[100001];
int N,M;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> a[i];
	
	int cur=1;
	for(int i=0;i<N;i++)
		for(int j=0;j<a[i];j++)
			pot[cur++]=i+1;
	
	cin >> M;
	for(int i=0;i<M;i++)
	{
		cin >> N;
		cout << pot[N] << endl;
	}
	
	return 0;
}
