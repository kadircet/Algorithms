#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 1000000
int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774,
                   777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444,
                   7447, 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474,
                   44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477,
                   47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744,
                   74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744, 77747,
                   77774, 77777, 444444, 444447, 444474, 444477, 444744, 444747,
                   444774, 444777, 447444, 447447, 447474, 447477, 447744, 447747,
                   447774, 447777, 474444, 474447, 474474, 474477, 474744, 474747,
                   474774, 474777, 477444, 477447, 477474, 477477, 477744, 477747,
                   477774, 477777, 744444, 744447, 744474, 744477, 744744, 744747,
                   744774, 744777, 747444, 747447, 747474, 747477, 747744, 747747,
                   747774, 747777, 774444, 774447, 774474, 774477, 774744, 774747,
                   774774, 774777, 777444, 777447, 777474, 777477, 777744, 777747,
                   777774, 777777};

/*void genLucky(int n)
{
	if(n>MAX)
		return;
	
	if(n!=0)
		lucky.push_back(n);
	genLucky(10*n+4);
	genLucky(10*n+7);
}*/

bool isLucky(int n)
{
	while(n>0)
	{
		if(n%10!=4 && n%10!=7)
			return false;
		n/=10;
	}
	return true;
}

					//0: untouched
int state[MAX+1];	//1: inqueue
					//2: visited
int parent[MAX+1];
int toVisit[MAX+1];
int r,f;
					
int minCount(int n)
{
	toVisit[r++]=n;
	parent[n] = 0;

	while(r!=f)
	{
		int c = toVisit[f++];
		
		if(state[c]==2)	//visited - actually not possible :)
			continue;
		state[c] = 2;	//mark visited
			
		if(isLucky(c))	//WELL WELL WELL
			return c;
		
		for(int i=0;i<sizeof(lucky)/sizeof(int) && lucky[i]<c;i++)
			if(state[c-lucky[i]]==0)	//untouched
			{
				toVisit[r++] = c-lucky[i];
				parent[c-lucky[i]]=c;
				state[c-lucky[i]]=1;	//inqueue
			}
	}
	
	return 0;
}

int main()
{
	//genLucky(0);
	//sort(lucky.begin(), lucky.end());
	
	int N;
	cin >> N;
	int res = minCount(N);
	if(res==0)
		cout << -1 << endl;
	else
	{
		vector<int> numbers;
		int k=res;				//get the first lucky number found
		numbers.push_back(k);	//put it into the numbers array
		while(parent[k]!=0)		//go for its parent!
		{
			numbers.push_back(parent[k]-k);	//the difference between its parent
											//and the current number is
											//the lucky number we've subtracted
			k = parent[k];	//take the next number
		}
		cout << numbers.size() << endl;
		for(int i=0;i<numbers.size();i++)
			cout << numbers[numbers.size()-1-i] << " ";	//the array is in reverse order
														//so print it reverse :D
		cout << endl;
	}
	return 0;
}

