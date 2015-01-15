#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int lds(vector<int> a)
{
	vector<int> b;
	int u, v;
	b.push_back(0);

	for (int i = 1; i < a.size(); i++) 
	{
		if (a[b.back()] > a[i])
		{
			b.push_back(i);
			continue;
		}
		for (u = 0, v = b.size()-1; u < v;)
		{
			int c = (u + v) / 2;
			if (a[b[c]] > a[i]) u=c+1; else v=c;
		}
		if (a[i] > a[b[u]])
			b[u] = i;
	}
	return b.size();
}

int LDS(vector<int> A)
{
    int N = A.size(),i;
    set<int, greater<int> > s;
    set<int, greater<int> >::iterator k;
    for (i=0;i<N;i++)
    {
        if (s.insert(A[i]).second)
        {
           k = s.find(A[i]);
           k++;
           cout << *k << endl;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}

int main()
{
	ifstream inp("azalan.gir");
	ofstream oup("azalan.cik");
	int N;
	inp >> N;
	vector<int> A;
	int k;
	for(int i=0;i<N;i++)
	{
		inp >> k;
		A.push_back(k);
	}

	oup << LDS(A) << endl;
	return 0;
}

