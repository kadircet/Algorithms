#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		double c,f,x;
		cin >> c >> f >> x;
		
		double cps=2.0;
		double time=0;
		
		while(true)
		{
			if(x/cps > c/cps+x/(cps+f))
			{
				time += c/cps;
				cps += f;
			}
			else
			{
				time+=x/cps;
				break;
			}
		}
		cout.precision(7);
		cout << "Case #" << t << ": " << fixed << time << endl;
	}
	
	return 0;
}

