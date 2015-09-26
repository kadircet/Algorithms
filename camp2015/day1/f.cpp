#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

struct trie
{
	bool end;
	trie* next[26];
	
	static void* operator new(size_t sz)
	{
		trie *res = (trie*)::operator new(sz);
		for(int i=0;i<26;i++)
			res->next[i]=NULL;
		res->end=false;
		return (void *)res;
	}
};

trie* root;

void insert(string& w, int pos=0, trie* cur=root)
{
	if(w.size()==pos)
	{
		cur->end=true;
		return;
	}
	if(cur->next[w[pos]-'a']==NULL)
		cur->next[w[pos]-'a'] = new trie;
	insert(w, pos+1, cur->next[w[pos]-'a']);
}

bool check(string& w, int pos=0, trie* cur=root)
{
	//if(pos==0) cout << "Checking: " << w << " ";
	if(cur==NULL)
	{
		//cout << 0 << endl;
		return false;
	}
	if(w.size()==pos)
	{
		//cout << cur->end << endl;
		return cur->end;
	}
	return check(w, pos+1, cur->next[w[pos]-'a']);
}

void printTrie(trie *cur, string w="")
{
	if(cur->end)
		cout << w << endl;
	for(int i=0;i<26;i++)
		if(cur->next[i]!=NULL)
			printTrie(cur->next[i], w+(char)('a'+i));
}

void cleanTrie(trie *cur=root)
{
	if(cur==NULL)
		return;
	for(int i=0;i<26;i++)
		if(cur->next[i]!=NULL)
			cleanTrie(cur->next[i]);
	free(cur);
}

map<string, bool> seen;

int main()
{
	char tmp;
	int K;
	cin >> K;
	for(int t=0;t<K;t++)
	{
		cleanTrie();
		root = new trie;
		seen.clear();
		int n,k,q,p,c=0;
		string w, line;
		cin >> n >> k >> q;
		for(int i=0;i<n;i++)
		{
			cin >> w;
			insert(w);
		}
		cin.read(&tmp, 1);
		for(int i=0;i<k;i++)
		{
			int j=0;
			getline(cin, line);
			p=0;
			while(j<line.size() && (line[j]<'a'||line[j]>'z'))j++;
			for(p=j;j<line.size();j++)
			{
				if(line[j]>='a'&&line[j]<='z')
					continue;
				w=line.substr(p, j-p);
				if(seen.find(w)==seen.end())
				{
					c+=check(w);
					seen[w]=true;
				}
				while(j<line.size() && (line[j]<'a'||line[j]>'z'))j++;
				p=j;
				j--;
			}
			w=line.substr(p, j-p);
			if(seen.find(w)==seen.end())
			{
				c+=check(w);
				seen[w]=true;
			}
		}
		if(c>=q)
			cout << "Danger" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
 
