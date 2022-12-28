#ifndef _LINKEDLIST_
#define _LINKEDLIST_

// ---------------------------------------
// Simple linked list node
typedef struct {
	int num;
	slnode *next;
} slnode;


// simple linked list functions
// return the root of a new simple linked list
slnode * init_slist(int num);

// returns the first node equals to value if it exists otherwise returns null;
slnode * sl_find(slnode* root, int value);

void sl_remove(slnode* root, slnode* node);

#endif