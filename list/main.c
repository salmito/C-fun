#include <stdio.h>
#include <string.h>

#include "list/list.h"

int strcmp_v(void * s1, void * s2) {
//	printf("%p, %p == %d\n",s1,s2,strcmp((char *)s1,(char *)s2));
	return !strcmp((char *)s1,(char *)s2);
}

int main(int argc, char ** argv) {
	list l=create_list();
	list_push(l,"String #1");
	list_push(l,"String #2");
	list_push(l,"String #3");
	dump_string_list(l);
	
	/*clean list*/
	list_pop(l);
	list_pop(l);
	list_pop(l);
	dump_string_list(l);

	list_push(l,"Apples");
	list_push(l,"Oranges");
	list_push(l,"Grapes");
	dump_string_list(l);

	if(list_remove(l,"Oranges",(*strcmp_v))) {
		printf("Oranges removed\n");
		dump_string_list(l);
	}

	list_push(l,"Strawberries");
	dump_string_list(l);

	if(!list_remove(l,"Oranges",(*strcmp_v))) {
		printf("Oranges not found\n");
	}
	dump_string_list(l);
	list_remove(l,"Strawberries",NULL);
	dump_string_list(l);
	
	return 0;
}
