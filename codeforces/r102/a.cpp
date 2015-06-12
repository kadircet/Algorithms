#include <iostream>
using namespace std;

int main()
{
	long long m=0, M=0;
	long long N,a,b,c;
	bool isFirst=true;
	cin >> N;
	
	for(a=1;a*a*a<=N;a++)
	{
		if(N%a)
			continue;
		for(b=a;b*b<=N/a;b++)
		{
			if((N/a)%b)
				continue;
			
			c=N/a/b;
			if(isFirst)
			{
				m=M=(a+1)*(b+2)*(c+2)-N;
				isFirst=false;
			}
			
			m = min(m, (a+1)*(b+2)*(c+2)-N);
			M = max(M, (a+1)*(b+2)*(c+2)-N);
			m = min(m, (a+2)*(b+2)*(c+1)-N);
			M = max(M, (a+2)*(b+2)*(c+1)-N);
			m = min(m, (a+2)*(b+1)*(c+2)-N);
			M = max(M, (a+2)*(b+1)*(c+2)-N);
		}
	}
		
	cout << m << ' ' << M << endl;
	
	return 0;
}

