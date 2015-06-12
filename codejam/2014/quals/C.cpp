#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		int r,c,m;
		cin >> r >> c >> m;
		
		bool found=false;
		cout << "Case #" << t << ":" << endl;
		
		int space = r*c-m;
		
		if(r==1 || c==1)
		{
			for(int x=0;x<r;x++, cout << endl)
				for(int y=0;y<c;y++)
					if(x==0 && y==0)
						cout << 'c';
					else if(x*c+y<space)
						cout << '.';
					else
						cout << '*';
			found=true;
		}
		
		if(!found)
		for(int i=0;i<=min(r,c);i++)
			if(space==i*i)
			{
				for(int x=0;x<r;x++, cout << endl)
					for(int y=0;y<c;y++)
						if(x==0 && y==0)
							cout << 'c';
						else if(x<i && y<i)
							cout << '.';
						else
							cout << '*';
				found=true;
				break;
			}
			else if(space<i*i)
			{
				i--;
				space -= i*i;
				if(space>=2 && space<=i)
				{
					for(int x=0;x<r;x++, cout << endl)
						for(int y=0;y<c;y++)
							if(x==0 && y==0)
								cout << 'c';
							else if((x<i && y<i)||(y==i && space-->0))
								cout << '.';
							else
								cout << '*';
					found = true;
				}
				else if(space>=4)
				{
					space-=2;
					for(int x=0;x<r;x++, cout << endl)
						for(int y=0;y<c;y++)
							if(x==0 && y==0)
								cout << 'c';
							else if((x<i && y<i)||(y==i && space-->0)||(x==i && (y<2 || space-->0)))
								cout << '.';
							else
								cout << '*';
					found = true;
				}
				break;
			}
		
		if(!found)
			cout << "Impossible" << endl;
	}
	
	return 0;
}

