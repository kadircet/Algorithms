#include <iostream>
using namespace std;

double prob[101][101][101];
bool visited[101][101][101];
int N,C;
char top[101];

double guess(int R, int B, int c)
{
	if(c>R+B || R<0 || B<0)
		return .0;
	if(c==0)
		return (R+B)==0;
	if(visited[R][B][c])
		return prob[R][B][c];
	
	visited[R][B][c] = true;
	if(R>B)
	{
		if(N-(R+B)<C)
		{
			if(top[N-(R+B)]=='R')
				prob[R][B][c] = guess(R-1, B, c-1);
			else
				prob[R][B][c] = guess(R, B-1, c);
		}
		else
			prob[R][B][c] = ((double)R/(R+B))*guess(R-1, B, c-1) + ((double)B/(R+B))*guess(R, B-1, c);
	}
	else if(R<B)
	{
		if(N-(R+B)<C)
		{
			if(top[N-(R+B)]=='R')
				prob[R][B][c] = guess(R-1, B, c);
			else
				prob[R][B][c] = guess(R, B-1, c-1);
		}
		else
			prob[R][B][c] = ((double)R/(R+B))*guess(R-1, B, c) + ((double)B/(R+B))*guess(R, B-1, c-1);
	}
	else
	{
		if(N-(R+B)<C)
		{
			if(top[N-(R+B)]=='R')
				prob[R][B][c] = .5*guess(R-1, B, c-1) + .5*guess(R-1, B, c);
			else
				prob[R][B][c] = .5*guess(R, B-1, c) + .5*guess(R, B-1, c-1);
		}
		else
			prob[R][B][c] = ((double)R/(R+B))*(.5*guess(R-1, B, c-1) + .5*guess(R-1, B, c)) + ((double)B/(R+B))*(.5*guess(R, B-1, c) + .5*guess(R, B-1, c-1));
	}
	
	return prob[R][B][c];
}

int main()
{
	int S;
	cin >> N >> S >> C;
	for(int i=0;i<C;i++)
		cin >> top[i];
		
	double res=0;
	for(int i=S+1;i<=N;i++)
		res+=guess(N/2, N/2, i)*100;
	
	cout.precision(10);
	cout << res << endl;
	return 0;
}

