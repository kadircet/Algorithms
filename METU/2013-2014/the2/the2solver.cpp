#include <iostream>
#include <stack>
using namespace std;

int value['z'-'a'+1], count['z'-'a'+1];
char chars['z'-'a'+1];
string inp;

string ops="&|>-=";

bool isOp(char c)
{
	for(int i=0;i<ops.size();i++)
		if(ops[i]==c)
			return true;
	return false;
}

int calc(char op, int left, int right)
{
	switch(op)
	{
		case '&':
			return left&right;
		case '|':
			return left|right;
		case '>':
			return !left|right;
		case '=':
			return left==right;
		case '-':
			return !right;
	}
	
	return 0;
}

int solve(string& inp, int start)
{
	stack<char> operators;
	stack<int> operands;
	
	for(int i=start;i<inp.size();i++)
	{
		if(inp[i]=='(')
		{
			operands.push(solve(inp, i+1));
			int open=1;
			for(i=i+1;i<inp.size();i++)
				if(open==0)break;
				else if(inp[i]=='(')open++;
				else if(inp[i]==')')open--;
			i--; 	
			if(!operators.empty())
			{
				int r=operands.top(),l;
				operands.pop();
				if(operators.top()!='-')
					l=operands.top(),operands.pop();
				
				operands.push(calc(operators.top(), l, r));
				operators.pop();
			}
		}
		else if(inp[i]==')')
			break;
		else if(isOp(inp[i]))
			operators.push(inp[i]);
		else
		{
			int cur = value[inp[i]-'a'];
			if(!operators.empty())
			{
				int r=cur, l;
				if(!operands.empty())
					l=operands.top();
				if(operators.top()!='-')
					operands.pop();
				
				cur = calc(operators.top(), l, r);
				operators.pop();
			}
			operands.push(cur);
		}
	}
	
	while(!operators.empty())
	{
		int r=operands.top(), l;
		operands.pop();
		
		if(operators.top()!='-')
			l=operands.top(), operands.pop();
		
		operands.push(calc(operators.top(), l, r));
		operators.pop();
	}
	
	return operands.top();
}

void generate(int pos, int n)
{
	if(pos==n)
	{	
		for(int i=0;i<n;i++)
			cout << (value[chars[i]-'a']==1?'T':'F') << ' ';
		cout << (solve(inp, 0)==1?'T':'F') << endl;
		return;
	}
	value[chars[pos]-'a']=1;
	generate(pos+1, n);
	value[chars[pos]-'a']=0;
	generate(pos+1, n);
}

int main()
{
	string line;
	while(cin.good())
	{
		cin >> line;
		if(!cin.good())
			break;
		inp += line;
	}
	
	for(int i=0;i<inp.size();i++)
		if(inp[i]>='a' && inp[i]<='z')
			count[inp[i]-'a']++;
	
	int nc=0;
	for(int i=0;i<'z'-'a'+1;i++)
		if(count[i]>0)
			chars[nc++]=i+'a';
			
	//cout << inp << endl;
	
	for(int i=0;i<nc;i++)
		cout << chars[i] << ' ';
	cout << 'R' << endl;
	
	generate(0, nc);
	return 0;
}

