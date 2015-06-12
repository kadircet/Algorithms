#include <iostream>
#include <algorithm>
using namespace std;

bool used[100];
int a[100], b[100];

int main()
{
	int n,m;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	cin >> m;
	for(int i=0;i<m;i++)
		cin >> b[i];
		
	sort(a, a+n);
	sort(b, b+m);
	
	int res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(used[j])
				continue;
			if(abs(a[i]-b[j])<2)
			{
				used[j]=true;
				res++;
				break;
			}
		}
	cout << res << endl;
	return 0;
}

