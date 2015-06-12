#include <iostream>
#include <vector>
#include <string>
using namespace std;

int C[7][7];

int comb(int n, int r)
{
	if(C[n][r])
		return C[n][r];
	if(n==r || r==0)
		return C[n][r]=1;
	return C[n][r]=comb(n-1, r)+comb(n-1, r-1);
}

int main()
{
	int N,m,t;
	m=0;
	cin >> N;
	
	string line;
	vector<string> seq;
	vector<int> outs, seqi, count1;
	for(int i=0;i<N;i++)
	{
		cin >> line;
		seq.push_back(line);
		m = max(m, (int)line.size());
	}
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> t;
		outs.push_back(t-1);
	}
	
	int tot1=0;
	for(int i=0; i<seq.size(); i++)
	{
		int n=0;
		count1.push_back(m-seq[i].size());
		tot1+=m-seq[i].size();
		for(int j=0;j<m-seq[i].size();j++)
			n+= 1<<j;
	}
	
	
	if(tot1>m)
	{
		cout << "Possible Alignments: 0" << endl;
		for(int i=0;i<outs.size();i++)
			cout << "There is no alignment at position: " << outs[i]+1 << endl;
	}
	else
	{
		vector<int> nalign;
		int mt=m, tot1t=tot1;
		while(tot1t<=mt)
		{
			int res=1, used1=0;
			for(int i=0;i<seq.size();i++)
			{
				res *= comb(mt-used1, count1[i]+mt-m);
				used1 += count1[i]+mt-m;
			}
			nalign.push_back(res);
			//cout << res << endl;
			mt++;
			tot1t+=seq.size();
		}
		
		for(int i=0;i<outs.size();i++)
		{
			int sum=0,used1=0;
			int size=m;
			while(size-m<nalign.size() && sum<outs[i])
				sum += nalign[size++-m];
			size--;
			if(sum<outs[i] || outs[i] < 0)
				cout << "There is no alignment at position: " << outs[i]+1 << endl;
			else
			{
				vector<bool> used(size);
				outs[i]-=sum-nalign[size-m];
				mt=m, tot1t=tot1;
				for(int i=0;i<seq.size();i++)
				{
					int q=nalign[size-m]/comb(size-used1, count1[i]);
					while(used[q])q++;
						used[q]=true;
					used1 += count1[i]+mt-m;
				}
			}
		}
	}
	
	return 0;
}

