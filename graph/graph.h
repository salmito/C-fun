#ifndef GRAPH_H
#define GRAPH_H

typedef struct node_t * node;
typedef struct edge_t * edge;

struct edge_t {
	node begin;
	node end;
};

struct node_t {
	void * ptr;
};


edge create_edge(node n1,node n2);
node create_node(void * ptr);

#endif
