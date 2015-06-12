#include <iostream>
#include <fstream>
using namespace std;

bool **image;
int N;

bool** getQuadrant(bool **inp, int n, int k)
{
	bool **quadrant = new bool*[n];
	switch(k)
	{
		case 0:
			quadrant = inp;
			break;
		case 1:
			for(int i=0;i<n;i++)
				quadrant[i] = inp[i+n];
			break;
		case 2:
			for(int i=0;i<n;i++)
				quadrant[i] = inp[i]+n;
			break;
		case 3:
			for(int i=0;i<n;i++)
				quadrant[i] = inp[i+n]+n;
			break;
	}
	return quadrant;
}

int* count(bool **inp, int n)
{
	int *counts = new int[2];
	counts[0] = counts[1] = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			counts[inp[i][j]?1:0]++;
	return counts;
}

int drawPic(bool **inp, int n)
{
	if (n<=1)
		return 0;
	if(n==2)
	{
		bool foundZero=false, foundOne=false;
		int error=2;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				if(!foundOne && inp[i][j])
				{
					error--;
					foundOne = true;
				}
				else if(!foundZero && !inp[i][j])
				{
					error--;
					foundZero = true;
				}
			}
		return error;					
	}
	int max_0, max_1;
	max_0 = max_1 = 0;
	bool **quadrants[4];
	int *counts[4];
	int errors[4];
	for(int i=0;i<4;i++)
	{
		quadrants[i] = getQuadrant(inp, n/2, i);
		counts[i] = count(quadrants[i], n/2);		
		errors[i] = -1;
	}
	int min_error = 512*512;
	for(int i=0;i<3;i++)
		for(int j=i+1;j<4;j++)
		{
			if(counts[i][0]>counts[j][0])
			{
				max_0 = i;
				max_1 = j;
			}
			else
			{
				max_1 = i;
				max_0 = j;
			}
			int error = n*n/2 - counts[max_0][0] - counts[max_1][1];
			for(int k=0;k<4;k++)
			{
				if(error>=min_error)
					break;
				if(k==max_0 || k==max_1)
					continue;
				if(errors[k]==-1)
					errors[k] = drawPic(quadrants[k], n/2);
				error += errors[k];
			}
			if(error < min_error)
				min_error = error;
		}
	return min_error;
}

int main()
{
	ifstream inp("Slikar.gir");
	ofstream oup("Slikar.cik");
	inp >> N;
	image = new bool*[N];
	for(int i=0;i<N;i++)
	{
		char c;
		image[i] = new bool[N];
		for(int j=0;j<N;j++)
		{
			inp >> c;
			image[i][j] = c=='1';
		}
	}
	oup << drawPic(image, N) << endl;
	return 0;
}

