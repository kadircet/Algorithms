#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int containsSeven(int a)
{
    stringstream ss;
    ss << a;
    string str=ss.str();
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '7')
            return 1;
    }
    return 0;
}
int isTurningPoint(int a)
{
    if(a%7==0 || containsSeven(a))
    {
        return 1;
    }
    return 0;
}
int main()
{
 	map<int, int> asdf;
    int t; //number of test cases
    cin >> t;
    int orders[t]; //favourite numbers for orders
    int cn=1, dir=1;
    for(int i=1;i<=10100;i++)
    {
    	asdf[i] = cn;
    	if(isTurningPoint(i))
    		dir *= -1;
    	cn+=dir;
    	if(cn==0)cn=1337;
    	if(cn>1337)cn%=1337;
    }
    for(int i=0;i<t;i++)
    {
    	cin >> cn;
    	cout << asdf[cn] << endl;
    }
     
    return 0;
}

