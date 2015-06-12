#include <iostream>
using namespace std;

int first[4][4], sec[4][4];

int main()
{
	int T,f,s;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> f;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> first[i][j];
		cin >> s;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> sec[i][j];
				
		int count=0,pos=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(first[f-1][i]==sec[s-1][j])
					count++, pos=i;
		
		cout << "Case #" << t << ": ";
		if(count==0)
			cout << "Volunteer cheated!";
		else if(count>1)
			cout << "Bad magician!";
		else
			cout << first[f-1][pos];
		cout << endl;
	}
	
	return 0;
}

