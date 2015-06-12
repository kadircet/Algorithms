#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

string reverse(string s)
{
	string res=s;
	for(int i=0;i<s.size();i++)
		res[i] = s[s.size()-i-1];
	string res2="";
	for(int i=0;i<4-s.size();i++)
		res2 += '0';
	return res2+res;
}

string toHex(int n)
{
	if(n>0xFFFF)
		return "FFFF";
	if(n<=0)
		return "0000";
	string res="";
	string digs="0123456789ABCDEF";
	while(n>0)
	{
		res+=digs[n%16];
		n/=16;
	}
	return reverse(res);
}

int main()
{
	char c;
	scanf("%c", &c);
	
	bool error=false, number=false;
	int n=0;
	stack<int> ops;
	while(c!='\n')
	{
		if(!ops.empty() && (ops.top()<0 || ops.top()>0xFFFF))
		{
			error=true;
			break;
		}
		c=toupper(c);
		n*=16;
		if(c>='0' && c<='9')
		{
			n+=c-'0';
			number=true;
		}
		else if(c>='A' && c<='F')
		{
			n+=c-'A'+10;
			number=true;
		}
		else if(c==' ' && number)
		{
			n/=16;
			ops.push(n);
			//cout << "pushed: " << n << endl;
			n=0;
			number=false;
		}
		else if(c=='+')
		{
			if(ops.size()<2)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			int op2=ops.top();
			ops.pop();
			
			ops.push(op1+op2);
		}
		else if(c=='-')
		{
			if(ops.size()<2)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			int op2=ops.top();
			ops.pop();
			
			ops.push(op2-op1);
		}
		else if(c=='&')
		{
			if(ops.size()<2)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			int op2=ops.top();
			ops.pop();
			
			ops.push(op1&op2);
		}
		else if(c=='|')
		{
			if(ops.size()<2)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			int op2=ops.top();
			ops.pop();
			
			ops.push(op1|op2);
		}
		else if(c=='~')
		{
			if(ops.size()<1)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			
			int res = ~(unsigned int)op1 & 0xFFFF;
			ops.push(res);
		}
		else if(c=='X')
		{
			if(ops.size()<2)
			{
				error=true;
				break;
			}
			int op1=ops.top();
			ops.pop();
			int op2=ops.top();
			ops.pop();
			
			ops.push(op1^op2);
		}
		if(scanf("%c", &c)==EOF)
			break;		
	}
	if(error || ops.size()!=1)
		cout << "ERROR" << endl;
	else
		cout << toHex(ops.top()) << endl;
	return 0;
}

