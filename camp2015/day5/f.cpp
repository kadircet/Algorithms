#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#define mp(x,y) make_pair(x,y)
using namespace std;

string movs[] =
{
	"L1","L2","L3",
	"U1","U2","U3",
	"R1","R2","R3",
	"D1","D2","D3"
};

int fact[10];
vector<int > edges[363000];
/*map<int, bool> isterm;
map<int, pair<int,int> > pre;
map<int, bool> visited;*/
bool isterm[363000];
pair<int, int> pre[363000];
bool visited[363000];
pair<int, int> next[363000];

string domove(string s, int m)
{
	char t;
	if(m<3)
	{
		t=s[m*3];
		s[m*3]=s[m*3+1];
		s[m*3+1]=s[m*3+2];
		s[m*3+2]=t;
	}
	else if(m<6)
	{
		t=s[m-3];
		s[m-3]=s[m];
		s[m]=s[m+3];
		s[m+3]=t;
	}
	else if(m<9)
	{
		m%=3;
		t=s[m*3+2];
		s[m*3+2]=s[m*3+1];
		s[m*3+1]=s[m*3];
		s[m*3]=t;
	}
	else
	{
		m-=6;
		t=s[m+3];
		s[m+3]=s[m];
		s[m]=s[m-3];
		s[m-3]=t;
	}
	return s;
}

int getId(string a)
{
	int res=0;
	//for(int i=0;i<9;i++)
		//res=res*10+a[i]-'1';
	//return res;
	for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<9;j++)
			if(a[i]<a[j])
				a[j]--;
		a[i]--;
	}
	
	for(int i=0;i<9;i++)
		res+=(a[i])*fact[8-i];
	return res;
}

string getStr(int id)
{
	bool used[10];
	string res="000000000";
	for(int i=0;i<9;i++)
	{
		used[i]=false;
		res[i] = id/fact[8-i];
		id%=fact[8-i];
	}
	
	for(int i=0;i<9;i++)
	{
		int k=0,j;
		for(j=1;k<=res[i];j++)
				k+=!used[j];
		res[i]=j-1;
		used[j-1]=true;
	}
	//for(int i=0;i<9;i++)
		//res[i]+='0';
	return res;
}

/*void genGraph(string cur, int d=0)
{
	if(d>=200000)
		return;
	int tid,cid=getId(cur);
	
	string tmp;
	for(int i=0;i<6;i++)
	{
		tmp=domove(cur, i);
		tid=getId(tmp);
		if(!isterm[cid])
			edges[cid].push_back(tid*12+i);//make_pair(tid, i));
		if(edges[tid].size()==0)
			genGraph(tmp, d+1);
		if(!isterm[tid])
			edges[tid].push_back(cid*12+i+6);//make_pair(cid, i+6));
	}	
}*/

int bfs(string start)
{
	int tid=getId(start);
	string c,tmp;
	string toVisit[363000];
	int f=0,e=0;
	toVisit[e++]=start;//.push(start);
	visited[tid]=true;
	pre[tid]=make_pair(-1,-1);
	if(isterm[tid])
		return tid;
	while(f<e)//!toVisit.empty())
	{
		c=toVisit[f++];//toVisit.front();
		//c=getStr(cur);
		//toVisit.pop();
		/*for(int i=0;i<edges[cur].size();i++)
		{
			if(visited[edges[cur][i]/12])
				continue;
			visited[edges[cur][i]/12]=true;
			toVisit.push(edges[cur][i]/12);
			pre[edges[cur][i]/12]=make_pair(cur, edges[cur][i]%12);
			if(isterm[edges[cur][i]/12])
				return edges[cur][i]/12;
		}*/
		
		for(int i=0;i<12;i++)
		{
			tmp=domove(c, i);
			tid=getId(tmp);
			if(visited[tid])//.find(tid)!=visited.end())
				continue;
			visited[tid]=true;
			toVisit[e++]=tmp;//.push(tmp);
			pre[tid]=make_pair(getId(c), i);
			if(isterm[tid])//.find(tid)!=isterm.end())
				return tid;
		}
	}
	return -1;
}

/*int dfs(string start, int d, int dmax)
{
	if(d>=dmax)
		return -1;
	int id=getId(start),tid,q;
	visited[id]=true;
	string tmp;
	for(int i=0;i<12;i++)
	{
		tmp=domove(start, i);
		tid=getId(tmp);
		//if(visited.find(tid)!=visited.end())
			//continue;
		if(pre.find(tid)!=pre.end())
			continue;
		pre[tid]=make_pair(id, i);
		if(isterm.find(tid)!=isterm.end())
			return tid;
		q=dfs(tmp, d+1, dmax);
		if(q!=-1)
			return q;
		pre.erase(tid);
	}
	return -1;
}*/

void bfs1(string start)
{
	string tmp,tmp2;
	int tid,cid=getId(start), tid2;
	for(int i=0;i<12;i++)
	{
		tmp=domove(start,i);
		tid=getId(tmp);
		if(isterm[tid])
			continue;
		isterm[tid]=true;
		next[tid]=make_pair(cid, (i+6)%12);
		for(int j=0;j<12;j++)
		{
			if(i==j)
				continue;
			tmp2=domove(tmp, j);
			tid2=getId(tmp2);
			if(isterm[tid2])
				continue;
			isterm[tid2]=true;
			next[tid2]=make_pair(tid, (j+6)%12);
		}
	}
}

int main()
{
	fact[0]=1;
	for(int i=1;i<10;i++)
		fact[i]=fact[i-1]*i;
	isterm[getId(getStr(285303))]=true;
	isterm[getId(getStr(135289))]=true;
	isterm[getId(getStr(205759))]=true;
	isterm[getId(getStr(293805))]=true;
	isterm[getId(getStr(227590))]=true;
	isterm[getId(getStr(157120))]=true;
	isterm[getId(getStr(77576))]=true;
	isterm[getId(getStr(69074))]=true;
	next[285303]=make_pair(-1,-1);
	next[135289]=make_pair(-1,-1);
	next[205759]=make_pair(-1,-1);
	next[293805]=make_pair(-1,-1);
	next[227590]=make_pair(-1,-1);
	next[157120]=make_pair(-1,-1);
	next[77576]=make_pair(-1,-1);
	next[69074]=make_pair(-1,-1);
	bfs1(getStr(285303));
	bfs1(getStr(135289));
	bfs1(getStr(205759));
	bfs1(getStr(293805));
	bfs1(getStr(227590));
	bfs1(getStr(157120));
	bfs1(getStr(77576));
	bfs1(getStr(69074));

	string inp;
	char c;
	//genGraph(getStr(69074));
	//genGraph(getStr(77576));
		
	inp="";
	for(int i=0;i<9;i++)
	{
		cin >> c;
		inp+=c-'0';
	}
	c=0;
	int term=-1;
	if(isterm[getId(inp)])//.find(getId(inp))!=isterm.end())
		term=getId(inp);
	else
		term=bfs(inp);
	while(next[term].first!=-1)
	{
		pre[next[term].first]=make_pair(term, next[term].second);
		term=next[term].first;
	}
	/*while(term==-1 && c<10)
	{
		cout << (int)c << endl;
		//visited.clear();
		//pre.clear();
		term=dfs(inp, 0, c++);
	}*/
	//cout << term << endl;
	int res=0;
	vector<int> ops;
	for(;;)
	{
		if(term==getId(inp))
			break;
		ops.push_back(pre[term].second);
		term=pre[term].first;
	}
	cout << ops.size() << endl;
	for(int i=ops.size()-1;i>=0;i--)
		cout << movs[ops[i]] << endl;
	
	return 0;
}

