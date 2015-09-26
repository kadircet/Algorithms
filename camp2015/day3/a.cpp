#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	cout << max(max(n,k),m) << endl;
	return 0;
}
