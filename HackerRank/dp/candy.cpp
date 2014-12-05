#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int candy[100001], N;
int orgrating[100001];

int getMax(int pos)
{
	if(pos==0)
		return orgrating[pos]!=orgrating[pos+1]?candy[pos+1]:0;
	if(pos==N-1)
		return orgrating[pos]!=orgrating[pos-1]?candy[pos-1]:0;
	return max(orgrating[pos]!=orgrating[pos-1]?candy[pos-1]:0,
		orgrating[pos]!=orgrating[pos+1]?candy[pos+1]:0);
}

int main()
{
	pair<int, int> rating[100001];
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> rating[i].first;
		rating[i].second=i;
		orgrating[i]=rating[i].first;
	}
	sort(rating, rating+N);
	
	for(int i=0;i<N;i++)
		candy[rating[i].second] = getMax(rating[i].second)+1;
		
	int res=0;
	for(int i=0;i<N;i++)
		res+=candy[i];
	cout << res << endl;
	
	return 0;
}

