#include "linkedlist.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


// simple linked list functions
// return the root of a new simple linked list
slnode* init_slist(int num) {
	slnode* root = (slnode*) malloc(sizeof(slnode));

	root->num = num;
	root->next = NULL;

	return root;
}

// returns the first node equals to value if it exists otherwise returns null;
slnode* sl_find(slnode * root, int value) {

	while (root) {

		if (root->num == value)
			break;
		else
			root = root->next;
	}
#ifdef _DEBUG_ME_
	assert(root == NULL || root->num == value);
#endif
	return root;
}

void sl_remove(slnode** root, int value) {
	slnode** indirect = root;
	/* ------------------------------------ -
	slnode* prev = NULL;
	slnode* node = *root;
	while (node->num != value) {
		prev = node;
		node = node->next;
	}

	if (prev == NULL) {
		*root = node->next;
	}
	 ------------------------------------- */

	while ((*indirect)->num != value){
		indirect = &(*indirect)->next;
	}

#ifdef _DEBUG_ME_
	slnode* tmp = *indirect;
#endif
	*indirect = (*indirect)->next;

#ifdef _DEBUG_ME_
	assert(slfind(root, tmp->num));
#endif
}

void sl_insert(slnode* root, int value){
    slnode* prev = root;
    slnode* tmp;

    while (prev->next){
        if (prev->next->num < value)
            prev = prev->next;
        else
            break;
    }
    // prev->next == NULL || prev->next->num >= value
#ifdef _DEBUG_ME_
    assert(prev->next == NULL || prev->next->num >= value);
	assert(root->num <= root->next->num);
#endif // _DEBUG_ME_

    tmp = (slnode *) malloc(sizeof(slnode));
	
	// always inserted after current node
    tmp->next = prev->next;
	tmp->num = value;
    prev->next = tmp;
}

void print_slist(slnode* root)
{
	while (root) {
		printf("%d, ", root->num);
	}
}


