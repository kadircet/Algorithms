#include <iostream>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
  
  int T,A,B;
  cin >> T;
  while(T--)
  {
    cin >> A >> B;
    int s,e;
    for(int i=0;i*i<A;i++)
      s = i;
    for(int i=s;i*i<=B;i++)
      e = i;
    cout << e-s << endl;
  }
  return 0;
}

