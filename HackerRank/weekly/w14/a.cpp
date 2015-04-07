#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pos[100001];

int main()
{
	int N,K;
	vector<int> org;
	vector<int> sorted;
	
	cin >> N >> K;
	org.resize(N);
	for(int i=0;i<N;i++)
		cin >> org[i], pos[org[i]]=i;
	
	for(int i=0;i<N&&K>0;i++)
		if(org[i]!=N-i)
		{
			K--;
			int tmp=org[i];
			swap(org[i], org[pos[N-i]]);
			swap(pos[tmp],pos[N-i]);
		}
		
	for(int i=0;i<N;i++)
		cout << org[i] << ' ';
	cout << endl;
	return 0;
}
