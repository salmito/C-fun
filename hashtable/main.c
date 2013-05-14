#include <stdio.h>

#include "hashtable/hashtable.h"

int main(int argc,char ** argv) {
	hashtable h=create_hashtable(10);
	hashtable_set(h,"Key1","Strawberries");
	hashtable_set(h,"Key1","Apples");
	hashtable_set(h,"Key3","Banana");
	printf("Key3=%s\n",hashtable_get(h,"Key3"));
	printf("Key1=%s\n",hashtable_get(h,"Key1"));
	return 0;
}
