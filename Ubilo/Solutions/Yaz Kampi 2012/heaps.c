#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node_t, *heap_t;
typedef struct edge_t edge_t;
struct edge_t {
	node_t *nd;
	edge_t *sibling;
	int len;
};
struct node_t {
	edge_t *edge;
	node_t *via;
	int dist;
	int name;
	int heap_idx;
};

#define BLOCK_SIZE (500002)
edge_t *edge_root = 0, *e_next = 0;
 
void add_edge(node_t *a, node_t *b, int d)
{
	if (e_next == edge_root) {
		edge_root = malloc(sizeof(edge_t) * (BLOCK_SIZE + 1));
		edge_root[BLOCK_SIZE].sibling = e_next;
		e_next = edge_root + BLOCK_SIZE;
	}
	--e_next;
 
	e_next->nd = b;
	e_next->len = d;
	e_next->sibling = a->edge;
	a->edge = e_next;
}
 
void free_edges()
{
	for (; edge_root; edge_root = e_next) {
		e_next = edge_root[BLOCK_SIZE].sibling;
		free(edge_root);
	}
}

heap_t *heap;
int heap_len;
 
void set_dist(node_t *nd, node_t *via, int d)
{
	int i, j;

	if (nd->via && d >= nd->dist) return;

	nd->dist = d;
	nd->via = via;
 
	i = nd->heap_idx;
	if (!i) i = ++heap_len;

	for (; i > 1 && nd->dist < heap[j = i/2]->dist; i = j)
		(heap[i] = heap[j])->heap_idx = i;
 
	heap[i] = nd;
	nd->heap_idx = i;
}
 
node_t * pop_queue()
{
	node_t *nd, *tmp;
	int i, j;
 
	if (!heap_len) return 0;

	nd = heap[1];
	tmp = heap[heap_len--];
 
	for (i = 1; i < heap_len && (j = i * 2) <= heap_len; i = j) {
		if (j < heap_len && heap[j]->dist > heap[j+1]->dist) j++;
 
		if (heap[j]->dist >= tmp->dist) break;
		(heap[i] = heap[j])->heap_idx = i;
	}
 
	heap[i] = tmp;
	tmp->heap_idx = i;
 
	return nd;
}

void calc(node_t *start)
{
	node_t *lead;
	edge_t *e;
 
	set_dist(start, start, 0);
	while ((lead = pop_queue()))
		for (e = lead->edge; e; e = e->sibling)
			set_dist(e->nd, lead, lead->dist + e->len);
}

int main(void)
{
	freopen("shortest.gir", "r", stdin);
	freopen("shortest.cik", "w", stdout);
	int N,M;
	int s,e;
	int i, j, c;
 	
 	scanf("%d%d", &N, &M);

	node_t *nodes = calloc(sizeof(node_t), N);
	for(i=0;i<N;i++)
		nodes[i].name = i;
	
	for(i=0;i<M;i++)
	{
		scanf("%d%d%d", &s, &e, &c);s--;e--;
		add_edge(nodes+s, nodes+e, c);
		add_edge(nodes+e, nodes+s, c);
	}

	heap = calloc(sizeof(heap_t), N + 1);
	heap_len = 0;
	
	scanf("%d%d", &s, &e);s--;e--;
 
	calc(nodes+s);
	
	if(!nodes[e].via)
		puts("YOK");
	else
		printf("%d\n", nodes[e].dist);

	return 0;
}
