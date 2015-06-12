#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int mat[100][100];
vector<int> numbers;

int gcd(int a, int b)
{
	if(a==0)
		return b;
	return gcd(b%a, a);
}

int main()
{
	int N,M,d;
	cin >> N >> M >> d;
	
	int g=0,t;
	long sum=0,res=0;
	for(int i=0;i<N*M;i++)
	{
		cin >> t;
		mat[i/M][i%M] = t;
		sum+=t;
		g = gcd(g, t);
		numbers.push_back(t);
	}
	
	sort(numbers.begin(), numbers.end());
	
	sum = numbers[numbers.size()/2];

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			if(abs(mat[i][j]-sum)%d!=0)
			{
				cout << -1 << endl;
				return 0;
			}
			res+=abs(mat[i][j]-sum)/d;
		}
	cout << res << endl;
	
	return 0;
}


