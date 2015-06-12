#include <iostream>
#include <map>
using namespace std;

unsigned long long room[20];
unsigned long long gold[20], best;
unsigned long long N, K, M;

void search(int cur, unsigned long long sumhp, unsigned long long sumgold)
{
	if(sumhp>N)
		return;
	if(cur==M)
	{
		if(sumgold>best)
			best = sumgold;
		return;
	}
	
	search(cur+1, sumhp+room[cur], sumgold+gold[cur]);
	search(cur+1, sumhp, sumgold);
}

int main()
{
	unsigned long long hp;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		cin >> K >> gold[i];
		for(int j=0;j<K;j++)
		{
			cin >> hp;
			room[i] += hp;
		}
	}
	
	search(0, 0, 0);
	cout << best << endl;
	
	return 0;
}


