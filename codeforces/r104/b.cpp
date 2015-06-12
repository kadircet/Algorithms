#include <iostream>
using namespace std;

int main()
{
	int a1,a2,a3,a4;//4 7 47 74
	cin >> a1 >> a2 >> a3 >> a4;
	
	string res;
	if(max(a3,a4)-min(a3,a4)>1)
	{
		cout << -1 << endl;
	}
	else if(a3==a4)
	{
		for(int i=0;i<a3;i++)
			res += "47";
		a1-=a3;
		a2-=a3;
		a3=a4=0;
		if(a1<0 || a2<0)
			cout << -1 << endl;
		else
		{
			for(int i=0;i<a1-1;i++)
				cout << 4;
			if(a1==0)
			{
				if(a2>0)
				{
					cout << 7;
					a2--;
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
			}
			cout << res;
			for(int i=0;i<a2;i++)
				cout << 7;
			if(a1!=0)
				cout << 4;
			cout << endl;
		}
	}
	else if(a3>a4)
	{
		for(int i=0;i<a3;i++)
			res += "47";
		a1-=a3;
		a2-=a3;
		a3=a4=0;
		if(a1<0 || a2<0)
			cout << -1 << endl;
		else
		{
			for(int i=0;i<a1;i++)
				cout << 4;
			cout << res;
			for(int i=0;i<a2;i++)
				cout << 7;
			cout << endl;
		}
	}
	else
	{
		for(int i=0;i<a4;i++)
			res += "74";
		a1-=a4;
		a2-=a4;
		if(a1<0 || a2<0)
			cout << -1 << endl;
		else
		{
			bool q=0;
			if(a1>0)
			{
				res[0] = '4';
				cout << 7;
				a1--;
			}
			if(a2>0)
			{
				res[res.size()-1]='7';
				a2--;
				q=1;
			}
			for(int i=0;i<a1;i++)
				cout << 4;
			cout << res;
			for(int i=0;i<a2;i++)
				cout << 7;
			if(q)
				cout << 4;
			cout << endl;
		}
	}
	
	return 0;
}

