#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inp;
int len, cur;

char avaib[] = "|&->=()";

char value['z'-'a'+1];
int nc, idx['z'-'a'+1], count['z'-'a'+1];

int isAvaib(char c)
{
	int i;
	for(i=0;i<strlen(avaib);i++)
		if(avaib[i]==c)
			return 1;
	return 0;
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
			return (!left)|right;
		case '=':
			return left==right;
	}
	
	return 0;
}

int solve(int start, int end, int* res)
{
	int i,lastres=0,curres=0;
	char curop=0;
	for(i=start;i<end;i++)
	{
		if(inp[i]=='(')
		{
			i+=1+solve(i+1, end, &curres);
			if(curop=='-')
				curres = !curres;
			else if(curop)
				curres = calc(curop, lastres, curres);
		}
		else if(inp[i]==')')
		{
			*res = curres;
			return i-start;
		}
		else if(isAvaib(inp[i]))
		{
			if(inp[i]=='-')
			{
				if(inp[i+1]=='(')
				{
					i+=2+solve(i+2, end, &curres);
					curres = !curres;
				}
				else if(inp[i+1] == '-')
				{
					i++;
					continue;
				}
				else
				{
					curres = !value[idx[inp[i+1]-'a']-1];
					i++;
				}
				if(curop)
					curres = calc(curop, lastres, curres);
			}
			else
				curop=inp[i];
		}
		else if(inp[i]>='a' && inp[i]<='z')
		{
			if(curop=='&')
				curres = lastres & value[idx[inp[i]-'a']-1];
			else if(curop=='|')
				curres = lastres | value[idx[inp[i]-'a']-1];
			else if(curop=='=')
				curres = lastres == value[idx[inp[i]-'a']-1];
			else if(curop=='>')
				curres = (!lastres) | value[idx[inp[i]-'a']-1];
			else if(curop=='-')
				curres = !value[idx[inp[i]-'a']-1];
			else
				curres = value[idx[inp[i]-'a']-1];
		}
		
		lastres = curres;
	}

	*res = curres;
	return i-start;
}

void generate(int pos, int n)
{
	int res=0, i;
	if(pos==n)
	{
		for(i=0;i<n;i++)
			printf("%c ", value[i]?'T':'F');
		
		solve(0, cur, &res);
		printf("%c\n", res?'T':'F');
		
		return;
	}
	
	value[pos]=1;
	generate(pos+1, n);
	value[pos]=0;
	generate(pos+1, n);
}

int main()
{
	char temp;
	
	len = 1024;
	inp = malloc(sizeof(char)*len);
	
	while(scanf("%c", &temp)!=EOF)
	{
		if(temp>='a' && temp<='z')
		{
			if(idx[temp-'a']<=0)
				count[temp-'a']++;
			inp[cur++]=temp;
		}
		else if(isAvaib(temp))
			inp[cur++]=temp;
		
		if(cur==len)
		{
			len*=2;
			inp = realloc(inp, sizeof(char)*len);
		}
	}
	inp[cur]=0;
	
	for(temp=0;temp<'z'-'a'+1;temp++)
		if(count[(int)temp]>0)
		{
			printf("%c ", temp+'a');
			idx[(int)temp]=++nc;
		}
	puts("R");
	
	generate(0, nc);
	
	return 0;
}

