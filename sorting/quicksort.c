#include <stdio.h>
#include <list/list.h>

list concatenate(list l1,long int el,list l2) {
	list ret=create_list();
	element cur=l1->head;
	while(cur) {
		list_push(ret,cur->ptr);
		cur=cur->next;
	}
	list_push(ret,(void *)el);
	cur=l2->head;
	while(cur) {
		list_push(ret,cur->ptr);
		cur=cur->next;
	}
	return ret;	
}

list quicksort(list l) {
	if(l->size<=1) return l;
	element cur=l->head;
	long int pivot=(long int)cur->ptr;
	list menor=create_list();
	list maior=create_list();
	
	cur=cur->next;
	while(cur) {
		if((long int)cur->ptr <= pivot)
			list_push(menor,cur->ptr);
		else
			list_push(maior,cur->ptr);
		cur=cur->next;
	}

	return concatenate(quicksort(menor),pivot,quicksort(maior));
}

list merge(list l1,list l2) {
	list ret=create_list();
	element cur1=l1->head;
	element cur2=l2->head;
	while(cur1 || cur2) {
		if(cur1 && cur2) {
		 if((long int)cur1->ptr<(long int)cur2->ptr) {
			list_push(ret,cur1->ptr);
			cur1=cur1->next;
		} else {
			list_push(ret,cur2->ptr);
			cur2=cur2->next;
		}
		} else {
		if(cur1) {
			list_push(ret,cur1->ptr);
			cur1=cur1->next;
		}
		if(cur2) {
			list_push(ret,cur2->ptr);
			cur2=cur2->next;
		}}
	}
	return ret;	
}


list mergesort(list l) {
	if(l->size<=1) return l;
	int middle=l->size/2;
	list left=create_list();
	list right=create_list();
	
	element cur=l->head;
	int i=1;

	while(cur) {
		if(i<=middle) list_push(left,cur->ptr);
		else list_push(right,cur->ptr);
		i++;
		cur=cur->next;
	}
	left=mergesort(left);
	right=mergesort(right);
	
	return merge(left,right);
}

int main() {
	list l=create_list();
	list_push(l,(void *)2);
	list_push(l,(void *)2900);
	list_push(l,(void *)3);
	list_push(l,(void *)50);
	list_push(l,(void *)20);
	list_push(l,(void *)30);
	list_push(l,(void *)80);
	list_push(l,(void *)12);
	dump_int_list(l);
	
	list l2=create_list();
	list_push(l2,(void *)1024);
	dump_int_list(concatenate(l,512,l2));

	dump_int_list(quicksort(l));
	dump_int_list(mergesort(l));
	

	return 0;
}
