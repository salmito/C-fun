#include <stdio.h>

#include "list/list.h"
#include "graph/graph.h"

void dump_graph(list g) {
	element cur=g->head;
	while(cur) {
		printf("%s -> %s\n",(char *)((node)((edge)cur->ptr)->begin)->ptr,(char *)((node)((edge)cur->ptr)->end)->ptr);
		cur = cur->next;
	}
}

int main() {
	list graph=create_list();
	
	node n1=create_node("Node 1");
	node n2=create_node("Node 2");
	node n3=create_node("Node 3");
	
	edge e1=create_edge(n1,n2);
	edge e2=create_edge(n2,n3);
	edge e3=create_edge(n3,n1);
	
	list_push(graph,e1);
	list_push(graph,e2);
	list_push(graph,e3);
	
	dump_graph(graph);
	
	return 1;
}
