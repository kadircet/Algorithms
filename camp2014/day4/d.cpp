#include <iostream>
#include <set>
#define MOD 1000000007ULL
using namespace std;

unsigned long long res;
int arr[8];
bool check[9];
void gen(int n, int k)
{
	if(n==k)
	{
		bool found=false;
		for(int i=0;i<k;i++)
		{
			check[i]=0;
			if(arr[i] == 1)
				check[i] = found=true;
		}
		
		if(!found)
			return;
		found = false;
		
		for(int t=0;t<k;t++)
		{
			for(int i=0;i<k;i++)
				if(!check[i] && check[arr[i]-1])
					check[i] = found = true;
			if(!found)
				break;
		}
		
		int t=0;
		for(int i=0;i<k;i++)
			t += check[i];
		if(t==k)
			res=(res+1)%MOD;
		return;
	}
	
	for(int i=1;i<=k;i++)
	{
		arr[n] = i;
		gen(n+1, k);
	}
}

int main()
{
	int n,k;
	cin >> n >> k;
	
	gen(0,k);
	for(int i=0;i<n-k;i++)
		res = (res*(n-k))%MOD;
	
	cout << res << endl;
	return 0;
}


