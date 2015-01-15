#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N,nsol;
vector<vector<int> > rows, cols;
ofstream oup("sea.cik");

bool checkMap(char** map)
{
	int c = 0;
	int q = 0;
	for(int i=0;i<N;i++)
	{
		q=0;
		for(int j=0;j<N;j++)
		{
			c=0;
			while(map[i][j] == '*')
			{
				c++;
				j++;
				if(j>=N)
					break;
			}
			if(c>0)
			{
				if(q==rows[i].size() || rows[i][q++]!=c)
					return false;
			}
		}
		//cout << q << " " << rows[i].size() << endl;
		if(q!=rows[i].size())
			return false;
	}
	for(int i=0;i<N;i++)
	{
		q=0;
		for(int j=0;j<N;j++)
		{
			c=0;
			while(map[j][i] == '*')
			{
				c++;
				j++;
				if(j>=N)
					break;
			}
			if(c>0)
			{
				if(q==cols[i].size() || cols[i][q++]!=c)
					return false;
			}
		}
		if(q!=cols[i].size())
			return false;
	}
	
	return true;
}

void printMap(char** map)
{
	nsol++;
	for(int i=0;i<N;i++, oup << endl)
		for(int j=0;j<N;j++)
			oup << map[i][j];
	oup << endl;
}

int checkRow(int r, char** map)
{
	int c=0;
	int q = 0;
	for(int i=0;i<N;i++)
	{
		c=0;
		while(i<N && map[r][i] == '*')
		{
			c++;
			i++;
		}
		if(c>0)
			if(q==rows[r].size() || rows[r][q++]!=c)
				return 1;
	}
	return 0;
}

int checkCol(int c, char** map)
{
	int t=0;
	int q = 0;
	for(int i=0;i<N;i++)
	{
		t=0;
		while(i<N && map[i][c]=='*')
		{
			t++;
			i++;
		}
		if(t>0)
		{
			if(q==cols[c].size() || cols[c][q++]!=t)
				return 1;
		}
	}
	if(q!=cols[c].size())
		return 1;
	return 0;
}

bool checkColC(int row, int col, char** map)
{
	int q=0;
	int t=0;
	for(int i=0;i<row;i++)
	{
		t=0;
		while(i<row && map[i][col]=='*')
		{
			t++;
			i++;
		}
		if(t>0)
		{
			if(q>=cols[col].size())
				return false;
			if(i>=row)
			{
				if(t > cols[col][q])
					return false;
			}
			else
			{
				if(t!=cols[col][q])
					return false;
			}			
			q++;
		}
	}
	return true;
}

void generate(int row, int col, char** map)
{
	if(col>=N)
		return;
	if(col==0 && row>0)
		if(checkRow(row-1, map)!=0)
			return;
	if(row>0)
		if(!checkColC(row, col, map))
			return;
	if(row==N-1 && col>0)
		if(checkCol(col-1, map)!=0)
			return;
	
	if(row>=N)
	{
		if(checkMap(map))
			printMap(map);
		return;
	}
	
	if(col==N-1)
	{
		int t=0;
		for(int i=0;i<N-1;i++)
			if(map[row][i]=='*')
				t++;
		for(int i=0;i<rows[row].size();i++)
			t-=rows[row][i];
		if(t==-1)
			map[row][col] = '*';
		else if(t==0)
			map[row][col] = '-';
		else
			return;
		generate(row+1, 0, map);
		return;
	}
	
	if(row==N-1)
	{
		int t=0;
		for(int i=0;i<N-1;i++)
			if(map[i][col]=='*')
				t++;
		for(int i=0;i<cols[col].size();i++)
			t-=cols[col][i];
		if(t==-1)
			map[row][col] = '*';
		else if(t==0)
			map[row][col] = '-';
		else
			return;
		generate(row, col+1, map);
		return;
	}
	
	if(rows[row].size()!=0 && cols[col].size()!=0)
	{
		map[row][col] = '*';
		generate(row, col+1, map);
	}
	
	map[row][col] = '-';
	generate(row, col+1, map);
}

int main()
{
	ifstream inp("sea.gir");
	
	inp >> N;
	int c;
	vector<int> current;
	for(int i=0;i<N;i++)
	{
		inp >> c;
		while(c!=0)
		{
			current.push_back(c);
			inp >> c;
		}
		rows.push_back(current);
		current.clear();
	}
	
	for(int i=0;i<N;i++)
	{
		inp >> c;
		while(c!=0)
		{
			current.push_back(c);
			inp >> c;
		}
		cols.push_back(current);
		current.clear();
	}
	char** map = new char*[N];
	for(int i=0;i<N;i++)
		map[i] = new char[N];
	
	generate(0,0,map);
	if(nsol==0)
		oup << "IMPOSSIBLE" << endl;
	return 0;
}

