#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		vector<double> naomi, ken;
		int N;
		cin >> N;
		naomi.resize(N), ken.resize(N);
		for(int i=0;i<N;i++)
			cin >> naomi[i];
		for(int i=0;i<N;i++)
			cin >> ken[i];
		
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		
		int kf=0, kr=N-1;
		int nf=0, nr=N-1;
		
		cout << "Case #" << t << ": ";
		int res=0;
		while(kf<=kr && nf<=nr)
		{
			while(kf<=kr && nf<=nr && ken[kf]>naomi[nf])
				nf++;
		
			while(kf<=kr && nf<=nr && naomi[nf]>ken[kf])
				res++, nf++, kf++;
		}
		cout << res << ' ';
		
		reverse(naomi.begin(), naomi.end());
		reverse(ken.begin(), ken.end());
		
		/*for(int i=0;i<N;i++)
			cout << naomi[i] << ' ';
		cout << endl;
		for(int i=0;i<N;i++)
			cout << ken[i] << ' ';
		cout << endl;*/
		
		res=0;
		nf=0, kf=0;
		bool kused[1001];
		memset(kused, 0, sizeof(kused));
		for(int i=0;i<N;i++)
		{
			if(naomi[i]>ken[kf])
			{
				int z=N-1;
				while(z>=kf && kused[z])z--;
				kused[z]=true;
				res++;
			}
			else
			{
				int j=kf;
				int last=j;
				while(j<N && naomi[i]<ken[j])
				{
					if(!kused[j])
						last=j;
					j++;
				}
				kused[last]=true;
			}
			while(kf<N && kused[kf])
				kf++;
			if(kf>=N)
				break;
		}
		cout << res << endl;
	}
	
	return 0;
}

