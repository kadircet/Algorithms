#include <iostream>
#include <vector>
using namespace std;

bool got[2000001];
int M[2000001];

int main()
{
	int n;
	vector<int> A;
	cin >> n;
	A.resize(n);
	for(int i=0;i<n;i++)
		cin >> A[i], got[A[i]]=1;
	
	for(int i=0;i<=2000000;i++)
		if(got[i])
			M[i] = i;
		else
			M[i] = M[i-1];
	
	int m=0;	
	for(int i=2;i<=1000000;i++)
		if(got[i])
			for(int j=2*i-1;j<=2000000;j+=i)
				m = max(m, M[j]%i);
	cout << m << endl;
	
	return 0;
}
