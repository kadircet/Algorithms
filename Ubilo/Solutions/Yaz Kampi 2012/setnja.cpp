#include <iostream>
#include <fstream>
#include <vector>
#define LIM  10001
#define MOD  10000000
#define FILL 7
using namespace std;

string path;
int* tot;

void printResult(ostream& os, int *res)
{
	int i=LIM-1;
	while(res[i]==0)i--;
	os << res[i--];
	while(i>=0)
	{
		os.width(FILL);
		os.fill('0');
		os << right << res[i--];
	}
	os << endl;
}

void addToResult(int* result, int* x)
{
	int carry=0;
	int i=LIM-1;
	while(x[i]==0)i--;
	int size=i;
	i=0;
	while(i<=size)
	{
		result[i] = x[i] + result[i] + carry;
		carry=0;
		if(result[i] >= MOD)
		{
			carry = result[i]/MOD;
			result[i] %= MOD;
		}
		i++;
	}
	while(carry>0)
	{
		result[i] += carry;
		carry=0;
		if(result[i] >= MOD)
		{
			carry = result[i]/MOD;
			result[i] %= MOD;
		}
		i++;
	}
}

void mult(int* result, int* x, int m)
{
	int carry=0;
	int i=LIM-1;
	while(x[i]==0)i--;
	int size=i;
	i=0;
	while(i<=size)
	{
		result[i] = x[i] * m + carry;
		carry=0;
		if(result[i] >= MOD)
		{
			carry = result[i]/MOD;
			result[i] %= MOD;
		}
		i++;
	}
	while(carry>0)
	{
		result[i] += carry;
		carry=0;
		if(result[i] >= MOD)
		{
			carry = result[i]/MOD;
			result[i] %= MOD;
		}
		i++;
	}
}

void traverse(int* x, int pos)
{
	int* stars=new int[LIM];
	for(int i=0;i<LIM;i++)
		stars[i] =0;
	stars[0]=1;
	while(pos<path.length())
	{
		if(path[pos]=='L')
		{
			mult(x, x, 2);
		}
		else if(path[pos]=='R')
		{
			mult(x, x, 2);
			addToResult(x, stars);
		}
		else if(path[pos]=='*')
		{
			mult(x, x, 5);
			addToResult(x, stars);

			mult(stars, stars, 3);
		}
		pos++;
	}
	addToResult(tot, x);
	return;
}

int main()
{
	ifstream inp("setnja.gir");
	ofstream oup("setnja.cik");

	tot = new int[LIM];
	int *x = new int[LIM];
	for(int i=0;i<LIM;i++)	
		tot[i] = x[i] = 0;
	x[0] = 1;

	inp>>path;
	traverse(x, 0);
	printResult(oup, tot);
	return 0;
}

