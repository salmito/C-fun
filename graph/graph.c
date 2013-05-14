#include <stdlib.h>
#include "graph/graph.h"

edge create_edge(node n1,node n2) {
	edge e=malloc(sizeof (struct edge_t));
	e->begin=n1,e->end=n2;
	return e;
}

node create_node(void * ptr) {
	node n=malloc(sizeof (struct node_t));
	n->ptr=ptr;
	return n;
}

