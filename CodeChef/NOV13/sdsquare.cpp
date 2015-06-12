#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int count[100001];

bool isOk(long long x)
{
	vector<bool> use(10);
	use[0]=use[1]=use[4]=use[9]=true;
	
	while(x>0)
	{
		if(!use[x%10])
			return false;
		x/=10;
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	count[0] = 0;
	for(int i=1;i<100001;i++)
	{
		count[i] = count[i-1] + isOk(((long long)i)*i);
		//if(isOk(((long long)i)*i))
			//cout << ((long long)i)*i << endl;
	}
	long long a,b;
	//srand(time(NULL));
	while(T--)
	{
		cin >> a >> b;
		cout << count[(int)sqrt(b)] - count[(int)ceil(sqrt(a))-1] << endl;
		/*
		int res=0;
		a=rand()%100000000+1;
		b=rand()%(100000000-a)+a+1;
		for(long long i=a;i<=b;i++)
		{
			if(sqrt(i)==(int)sqrt(i))
				res+=isOk(i);
			//if(isOk(i*i))
			//	cout << i*i << endl;
		}
		if(res!=count[(int)sqrt(b)] - count[((int)sqrt(a))-1])
			cout << "HMM:" <<  a << ' ' << b << endl;
		cout << count[(int)sqrt(b)] - count[((int)sqrt(a))-1] << ' ';
		cout << res << endl;
		*/
	}
	return 0;
}

