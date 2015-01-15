#include <iostream>
#include <fstream>
using namespace std;

int N,K;
string paint;

int repaint()
{
	int nChanged=0;
	for(int i=0;i<paint.length()-1;i++)
	{
		if(paint[i]==paint[i+1])
		{
			if(i==0 && paint.length()==2)
			{
				for(int k=0;k<K;k++)
					if('A'+k!=paint[i])
					{
						paint[i+1] = 'A'+k;
						//cout << paint << endl;
						nChanged++;
						break;
					}
			}
			else if(i!=paint.length()-2)
			{
				if(paint[i+1]==paint[i+2])
				{
					for(int k=0;k<K;k++)
						if('A'+k!=paint[i])
						{
							paint[i+1] = 'A'+k;
							++nChanged;
							break;
							//cout << paint << endl;
						}
				}
				else
				{
					bool changed=false;
					for(int k=0;k<K;k++)
						if('A'+k!=paint[i+1] && (i==0 || 'A'+k!=paint[i-1]))
						{
							changed=true;
							paint[i] = 'A'+k;
							++nChanged;
							break;
							//cout << paint << endl;
						}
					if(!changed)
					{
						for(int k=0;k<K;k++)
							if('A'+k!=paint[i])
							{
								changed=true;
								paint[i+1] = 'A'+k;
								++nChanged;
								break;
								//cout << paint << endl;
							}
					}
				}
			}
			else
			{
				bool changed=false;
					for(int k=0;k<K;k++)
						if('A'+k!=paint[i+1] && 'A'+k!=paint[i-1])
						{
							changed=true;
							paint[i] = 'A'+k;
							++nChanged;
							break;
							//cout << paint << endl;
						}
					if(!changed)
					{
						for(int k=0;k<K;k++)
							if('A'+k!=paint[i])
							{
								changed=true;
								paint[i+1] = 'A'+k;
								++nChanged;
								break;
								//cout << paint << endl;
							}
					}
			}
		}
	}
	return nChanged;
}

int main()
{
	ifstream inp("serit.gir");
	ofstream oup("serit.cik");
	
	inp >> N >> K;
	inp >> paint;
	oup << repaint() << endl;
	oup << paint << endl;
	return 0;
}

