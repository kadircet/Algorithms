#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int target=0;

class state
{
    public:
        int x;
        string ops;  
};

bool checkState(int x)
{
	return x==target;
}

state A(state s)
{
    int x = s.x;
	int r=0;
	while(x>0)
	{
        r*=10;
        r+=x%10;
        x/=10;
    }
    state c;
    c.x = r;
    c.ops = s.ops + 'A';
	return c;
}

state B(state s)
{
    state c;
    int x = s.x;
    int a[8],i=0;
    while(x>0)
	{
        a[i++]=x%10;
        x/=10;
    }
    for(int i=0;i<3;i++)
    {
        swap(a[3-i], a[2-i]);
        swap(a[4+i], a[5+i]);
    }
    int r=0;
    for(int i=0;i<8;i++)
    {
        r*=10;
        r+=a[7-i];
    }
	c.x = r;
	c.ops = s.ops + 'B';
	return c;
}

state C(state s)
{
    int x = s.x;
    int r=0;
    int a[8],i=0;
    while(x>0)
	{
        a[i++]=x%10;
        x/=10;
    }
    
    swap(a[1], a[2]);
    swap(a[2], a[5]);
    swap(a[5], a[6]);
    for(int i=0;i<8;i++)
    {
        r*=10;
        r+=a[7-i];
    }
    state c;
    c.x = r;
    c.ops = s.ops + 'C';
	return c;
}

void printBoard(int x)
{
    cout << x/10000 << endl;
    x%=10000;
    while(x>0)
    {
        cout << x%10;
        x/=10;
    }
    cout << endl;
}

bool contains(vector<int> v, int x)
{
	for(unsigned int i=0;i<v.size();i++)
		if(v[i] == x)
			return true;
	return false;
}

int BFS(ostream& os)
{
	vector<int> visited;
	queue<state> toVisit;
	state s;
	s.x = 12345678;
	s.ops = "";
	toVisit.push(s);
	
	while(!toVisit.empty())
	{
		state cState = toVisit.front();
		toVisit.pop();
		
		vector<int>::iterator lBound = lower_bound(visited.begin(), visited.end(), cState.x);
		if(lBound==visited.end() || *lBound!=cState.x)
			visited.insert(lBound, cState.x);
		else
			continue;

		if(checkState(cState.x))
		{
            os << cState.ops.length() << endl;
            os << cState.ops << endl;
			break;
        }
		
		if(cState.ops[cState.ops.size()-1]!='A')
			toVisit.push(A(cState));
		bool _try=false;
		for(int i=0;i<3;i++)
		{
			if(cState.ops[cState.ops.size()-i-1]!='B')
			{
				_try = true;
				break;
			}
		}
		if(_try)
			toVisit.push(B(cState));
		_try=false;
		for(int i=0;i<3;i++)
		{
			if(cState.ops[cState.ops.size()-i-1]!='C')
			{
				_try = true;
				break;
			}
		}
		if(_try)
			toVisit.push(C(cState));
	}
	return 0;
}

int main()
{
	ifstream inp("msquare.gir");
	ofstream oup("msquare.cik");
	
	int d;
	for(int i=0;i<8;i++)
	{
		target*=10;
		inp >> d;
		target+=d;
	}
	BFS(oup);
	return 0;
}

