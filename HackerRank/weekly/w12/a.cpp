#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> w;
	cin >> n;
	
	w.resize(n);
	for(int i=0;i<n;i++)
		cin >> w[i];
	
	int cost=0;
	sort(w.begin(), w.end());
	for(int i=0;i<w.size();i++)
	{
		cost++;
		int j=i;
		while(i<w.size() && w[i]-w[j]<=4)
			i++;
		if(i!=w.size())i--;
	}
	cout << cost << endl;
	return 0;
}

