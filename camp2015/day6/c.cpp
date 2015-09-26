#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


int arr[]={1,2,4,8,16,23,46,29,58,116,223,446,289,578,1156,1223,2446,2489,4789,5789,11578,
12356,12247,24449};

int rep[]={48889,77789,155578,111356,122227,244445};

int main()
{
	int n;
	cin >> n;
	
	if(n<=sizeof(arr)/sizeof(int))
		cout << arr[n-1] << endl;
	else
		cout << rep[(n-1-sizeof(arr)/sizeof(int))%(sizeof(rep)/sizeof(int))] <<endl;
	return 0;
}

