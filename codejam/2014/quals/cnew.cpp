#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		int R,C,M;
		cin >> R >> C >> M;
		
		cout << "Case #" << t << ":" << endl;
		bool found=false;
		for(int c=0;c<C && !found;c++)
			for(int r=0;r<R && !found;r++)
			{
				int m=r*C+c*R-c*r;
				if(m==M && ((R-r!=1||R==1) && (C-c!=1||C==1))||(R-r==C-c && R-r==1))
				{
					for(int i=0;i<R;i++, cout << endl)
						for(int j=0;j<C;j++)
							if(i==j && i==0)
								cout << 'c';
							else if(i<R-r && j<C-c)
								cout << '.';
							else
								cout << '*';
					found = true;
					break;
				}
				if(m>M)
					break;
				if(m+(R-r)>M && C-c>2)
				{
					int space = R-r-(M-m);
					if(space>=2)
					{
						for(int i=0;i<R;i++, cout << endl)
							for(int j=0;j<C;j++)
								if(i==j && i==0)
									cout << 'c';
								else if((i<R-r && j<C-c-1)||(j==C-c-1 && space-->0))
									cout << '.';
								else
									cout << '*';
						found = true;
						break;
					}
				}
				if(m+(C-c)>M && R-r>2)
				{
					int space=C-c-(M-m);
					if(space>=2)
					{
						for(int i=0;i<R;i++, cout << endl)
							for(int j=0;j<C;j++)
								if(i==j && i==0)
									cout << 'c';
								else if((i<R-r-1 && j<C-c)||(i==R-r-1 && space-->0))
									cout << '.';
								else
									cout << '*';
						found = true;
						break;
					}
				}
				/*if(m+R+C-r-c>M && R-r>2 && C-c>2)
				{
					int need = M-m;
					for(int x=0;x<min(need, C-c);x++)
					{
						if(x==C-c-1)
							continue;
						if(need-x==R-r-1)
							continue;
						
						if(need-x<=R-r)
						{
							int y=need-x;
							for(int i=0;i<R;i++, cout << endl)
								for(int j=0;j<C;j++)
									if(i==j && i==0)
										cout << 'c';
									else if((i<R-r-1 && j<C-c-1)||(i==R-r-1 && y-->0)||(j==C-c-1 && x-->0))
										cout << '.';
									else
										cout << '*';
							found = true;
							break;
						}
					}
				}*/
			}
		if(!found)
			cout << "Impossible" << endl;
	}
	
	return 0;
}

