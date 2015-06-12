#include <iostream>
#include <fstream>
using namespace std;

typedef struct _room
{
	int wolf;
	int sheep;
}room;

char map[250][250];
char vis[250][250];
room rooms[250*250];
int R,C;

void dfs(int r, int c, int n)
{
	if(vis[r][c] == 1)
		return;
	vis[r][c] = 1;
	if(map[r][c] == 'k')
		rooms[n].sheep += 1;
	else if(map[r][c] == 'v')
		rooms[n].wolf += 1;
	if(map[r][c] != '#')map[r][c] = n + '0';
	if(c<C-1 && map[r][c+1] != '#')
		dfs(r,c+1,n);
	if(c>0 && map[r][c-1] != '#')
		dfs(r,c-1,n);
	if(r<R-1 && map[r+1][c] != '#')
		dfs(r+1,c,n);
	if(r>0 && map[r-1][c] != '#')
		dfs(r-1,c,n);
}

int main()
{
	ifstream inp("koze.gir");
	ofstream oup("koze.cik");
	inp >> R >> C;
	
	for (int i=0;i<R;i++)
		for (int j=0;j<C;j++)
		{
			inp >> map[i][j];
			vis[i][j] = 0;
			rooms[j + i*j].wolf = 0;
			rooms[j + i*j].sheep = 0;
		}
	int n=0;
	for (int i=0;i<R;i++)
		for (int j=0;j<C;j++)
			if (vis[i][j] == 0 && map[i][j] != '#')
				dfs(i, j, n++);
	
	room total;
	total.sheep = total.wolf = 0;
	for (int i=0;i<n;i++)
		if (rooms[i].wolf >= rooms[i].sheep)
			total.wolf += rooms[i].wolf;
		else
			total.sheep += rooms[i].sheep;
	
	oup << total.sheep << " " << total.wolf << endl;
	
	return 0;
}

