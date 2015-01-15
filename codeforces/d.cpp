#include <iostream>
using namespace std;

int T[200001], w[200001], n[200001], W, N;

void compute()
{
	int pos=2, cnd=0;
	T[0] = -1;
	T[1] = 0;
	
	while(pos<W)
	{
		if(w[pos-1]==w[cnd])
		{
			cnd++;
			T[pos++] = cnd;
		}
		else if(cnd>0)
			cnd = T[cnd];
		else
			T[pos++] = 0;
	}
}

long long res=0;
void search()
{
	int m=0,i=0;
	while(m+i<N)
	{
		if(w[i]==n[m+i])
		{
			if(i==W-1)
			{
				res++;
				m=m+i-T[i];
				i=T[i];
			}
			else
				i++;
		}
		else
		{
			if(T[i]>-1)
			{
				m=m+i-T[i];
				i=T[i];
			}
			else
			{
				i=0;
				m++;
			}
		}
	}
}

int main()
{
	cin >> N >> W;
	if(W==1)
	{
		cout << N << endl;
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		cin >> n[i];
		if(i>0)
			n[i-1] = n[i]-n[i-1];
	}
	N--;
	
	for(int i=0;i<W;i++)
	{
		cin >> w[i];
		if(i>0)
			w[i-1] = w[i]-w[i-1];
	}
	W--;
	compute();
	search();
	
	cout << res << endl;
	return 0;
}

