#include <iostream>
using namespace std;

bool used[100001];

int main()
{
	int n,k;
	cin >> n >> k;
	
	for(int l=1,h=k+1,i=0;i<n && l<h;i++)
	{
		if(i%2)
		{
			cout << h << ' ';
			used[h]=true;
			h--;
		}
		else
		{
			cout << l << ' ';
			used[l]=true;
			l++;
		}
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
			cout << i << ' ';
	cout << endl;
	
	return 0;
}

