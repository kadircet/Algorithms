#include <iostream>
#include <cstring>
using namespace std;

bool visited[1001][1001];
bool found = false;
int a,b,c;

void dfs(int x, int y)
{
	if(x==c || y==c)
		found = true;
		
	if(x<0 || y<0 || visited[x][y] || found)
		return;
	visited[x][y] = true;
	
	//a->b
	int ny = min(y+x, b);
	int nx = x - (ny-y);
	dfs(nx, ny);
	
	//b->a
	nx = min(x+y, a);
	ny = y - (nx-x);
	dfs(nx, ny);
	
	//a->0
	dfs(0, y);
	
	//b->0
	dfs(x, 0);
	
	//X->a
	dfs(a, y);
	//X->b
	dfs(x, b);
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> a >> b >> c;
		memset(visited, 0, sizeof(visited));
		found = false;
		
		dfs(a, b);
		dfs(a, 0);
		dfs(0, b);
		
		if(found)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	
	return 0;
}

