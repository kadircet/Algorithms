#include <iostream>
#include <cstdio>
using namespace std;

int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isLeap(int n)
{
	if(n%4)
		return 0;
	if(n%100)
		return 1;
	if(n%400)
		return 0;
	return 1;
}

int nday(int m, int y)
{
	if(m!=1)
		return mon[m];
	return mon[1]+isLeap(y);
}

int main()
{
	int d=26,m=2,y=2014;
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		d++;
		if(d>nday(m-1, y))
		{
			m++;
			d=1;
		}
		if(m>12)
			m=1, y++;
	}
	printf("%02d.%02d.%d\n", d,m,y);
	return 0;
}


