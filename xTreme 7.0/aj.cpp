#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<long long int> slopes;
	int N;
	long long int t;
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> t;
		slopes.push(t);
	}
	
	long long int res=0, m=0;
	while(!slopes.empty())
	{
		res+=slopes.top();
		slopes.pop();
		
		m =max(m, res);
	}
	
	cout << m << endl;
	return 0;
}

