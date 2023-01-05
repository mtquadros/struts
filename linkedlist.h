#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#define _DEBUG_ME_

// ---------------------------------------
// Simple linked list node
typedef struct slnode {
	int num;
	slnode *next;
} slnode;


// simple linked list functions
// return the root of a new simple linked list
slnode * init_slist(int num);

// returns the first node equals to value if it exists otherwise returns null;
slnode * sl_find(slnode* root, int value);

void sl_remove(slnode** root, int value);

void sl_insert(slnode** root,int value);

void print_slist(slnode* root);

void free_slist(slnode** root);

#endif
