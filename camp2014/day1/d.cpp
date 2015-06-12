#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> c;
int mycount[500][100000];
int arr[100000], q[500], sarr[100000];
vector<int> numbers;

int main()
{
	int N,M,d=0;
	
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		sarr[i] = arr[i];
	}
	sort(sarr, sarr+N);
	
	d=1;
	for(int i=1;i<N;i++)
	{
		if(sarr[i-1]!=sarr[i])
		{
			c.push_back(d);
			d=0;
		}
		d++;
	}
	c.push_back(d);
	
	d=0;
	int nc=0;
	for(int i=0;i<N;i++)
		if(i==N-1 || sarr[i]!=sarr[i+1])
		{
			if(c[d++]>=sarr[i])
				q[nc++] = sarr[i];
		}	
	
	for(int i=0;i<nc;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(j!=0)
				mycount[i][j] = mycount[i][j-1];
			mycount[i][j] += arr[j] == q[i];
		}
	}
		
	for(int i=0;i<M;i++)
	{
		int l,r;
		cin >> l >> r;
		r--;l--;
		
		int res=0;
		for(int j=0;j<nc;j++)
			if((mycount[j][r] - mycount[j][l] + (arr[l]==q[j]))==q[j])
				res++;
		cout << res << endl;
	}
	return 0;
}

