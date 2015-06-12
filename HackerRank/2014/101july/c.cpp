#include <iostream>
#include <string>
#define N 314159
#define MOD 1000000007
using namespace std;

long pow[N+100000+10];
string a,b;

long pow2(int n)
{
	if(pow[n]!=0)
		return pow[n];
	
	pow[n] = pow2(n/2);
	pow[n] = (pow[n]*pow[n])%MOD;
	if(n%2)
		pow[n] = (pow[n]*2)%MOD;
		
	return pow[n];
}

string rev(string x)
{
	string y = "";
	for(int i=x.size()-1;i>=0;i--)
		y += x[i];
	return y;
}

int main()
{
	pow[0] = 1;
	cin >> a >> b;
	a = rev(a);
	b = rev(b);
	
	long A=0, Ainv=0;
	for(int i=0;i<a.size();i++)
		if(a[i]==0)
			Ainv = (Ainv + pow2(i))%MOD;
		else
			A = (A + pow2(i))%MOD;
	
	long res=0;
	for(int i=0;i<a.size();i++)
		res = (res + (((((a[i]-'0')*(N-i))%MOD)*pow2(i))%MOD))%MOD;
	for(int i=b.size();i<a.size();i++)
		res = (res + (((((a[i]-'0')*(i-b.size()+1))%MOD)*pow2(i))%MOD))%MOD;
		
	for(int i=0;i<min(a.size(), b.size());i++)
		res = (res + (((b[i]-'0')*((pow2(N+i+1)-pow2(a.size()+1)+MOD)%MOD))%MOD))%MOD;
	
	for(int i=a.size();i<b.size();i++)
		res = (res + (((b[i]-'0')*((pow2(N+i+1)-pow2(i)+MOD)%MOD))%MOD))%MOD;
	
	for(int i=0;i<min(a.size(), b.size());i++)
		if(b[i]==1)
			res = (res + Ainv)%MOD;
		else
			res = (res + A)%MOD;
	cout << res << endl;
	return 0;
}

