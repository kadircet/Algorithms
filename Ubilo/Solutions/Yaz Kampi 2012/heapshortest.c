#include <stdio.h>
#include <stdlib.h>

typedef struct _edge
{
	int from,to;
	int cost;
}edge;

edge heap[500000];
int deg[100000];
char visited[100000];
int last=0;

void swap(edge* e1, edge* e2)
{
	edge t = *e1;
	*e1 = *e2;
	*e2 = t;
}

void swim(int pos)
{
	for(;pos>0 && heap[pos/2].cost > heap[pos].cost;)
	{
		swap(&heap[pos/2], &heap[pos]);
		pos/=2;
	}
}

void sink(int pos)
{
	for(;heap[2*pos].cost < heap[pos].cost || heap[2*pos+1].cost < heap[pos].cost;)
	{
		if(2*pos+1>last)
			break;
		int ch=2*pos;
		if(heap[ch+1].cost < heap[ch].cost)
			ch++;
		swap(&heap[ch], &heap[pos]);
		pos = ch;
	}
}

void push(edge val)
{
	heap[++last] = val;
	swim(last);
}

edge pop()
{
	edge val = heap[1];
	swap(&heap[1], &heap[last--]);
	sink(1);
	return val;
}

int isEmpty()
{
	return last==0;
}

int main()
{
	freopen("shortest.gir", "r", stdin);
	freopen("shortest.cik", "w", stdout);
	int N,M,i;
	int s,e,c;
	edge tmp;
	
	scanf("%d%d", &N, &M);
	edge **edges = malloc(sizeof(edge*)*(N+1));
	for(i=0;i<N;i++)
		edges[i] = malloc(sizeof(edge)*(M+1));
	
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d", &s, &e, &c);s--;e--;
		tmp.from = s;tmp.to = e;tmp.cost = c;
		edges[s][deg[s]++] = tmp;
		edges[e][deg[e]++] = tmp;
	}
	scanf("%d%d", &s, &e);s--;e--;
	tmp.from=s;tmp.to=e;
	
	for(i=0;i<deg[s];i++)
		push(edges[s][i]);
	
	while(!isEmpty())
	{
		tmp = pop();
		if(visited[tmp.to])
			continue;
		visited[tmp.to] = 1;
		
		if(tmp.to==e)
		{
			printf("%d\n", tmp.cost);
			return 0;
		}
		s=tmp.to;
		c=tmp.cost;
		for(i=0;i<deg[s];i++)
		{
			tmp = edges[s][i];
			tmp.cost += c;
			push(tmp);
		}
	}
	puts("YOK");
	return 0;
}

