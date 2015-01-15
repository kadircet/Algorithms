#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long fib[130];

int main()
{
	fib[0]=0;fib[1] = 1;
	for(int i=2;i<90;i++)
		fib[i] = fib[i-1]+fib[i-2];
		
	long long K,pos;
	cin >> K;
	for(pos=2;;pos++)
		if(fib[pos]>K)
		{
			pos-=2;
			break;
		}

	double res=0;
	while(pos>=2)
	{
		long long A=fib[pos],a,b, B=fib[pos-1], k=K;
		a=A,b=B;
		double x,y;
		long long lastx,lasty,temp1,temp2,temp3,q;
		x=lasty=0,y=lastx=1;
		while(b!=0)
		{
			q=a/b;
			temp1=a%b;
			a=b;
			b=temp1;
			
			temp2=x;
			x=lastx-q*x;
			lastx=temp2;
			
			temp3=y;
			y=lasty-q*y;
			lasty=temp3;
		}
		x=(double)lastx*K, y=(double)lasty*K;
		
		if(x<=0)
		{
			double k=floor(-x/B)+1;
			x+=k*B,y-=k*A;
		}
		if(y<=0)
		{
			double k=floor(-y/A)+1;
			y+=k*A,x-=k*B;
		}
		if(x>=K)
		{
			double k = floor((K-y-1)/A);
			x-=k*B;
			y+=k*A;
		}
		if(y>=K)
		{
			double k = floor((K-x-1)/B);
			x+=k*A;
			y-=k*B;
		}
		if(x<=0 || y<=0 ||x>=K || y>=K)
		{
			pos--;
			continue;
		}

		double tmp=0;
		tmp=floor((y-1)/A);
		if(tmp>floor((K-x-1)/B))
			tmp = floor((K-x-1)/B);
		res+=tmp;
		
		tmp=floor((x-1)/B);
		if(tmp>floor((K-y-1)/A))
			tmp = floor((K-y-1)/A);
		res+=tmp;
		res++;
		pos--;
	}
	cout << res << endl;
	
	return 0;
}


