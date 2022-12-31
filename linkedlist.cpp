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

	while (root != NULL) {

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
	slnode* prev = NULL;
	slnode* node = *root;
	while (node->num != value) {
		prev = node;
		node = node->next;
	}

	if (prev == NULL) {
		*root = node->next;
	}

#ifdef _DEBUG_ME_
	slnode* tmp = *indirect;
#endif

#ifdef _DEBUG_ME_
	assert(slfind(root, tmp->num));
#endif
}

void sl_insert(slnode** root, int value){
    slnode* prev = NULL;
    slnode* node = *root;

    while (node){
        if (node->num < value)
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

void free_slist(slnode** root) {
	slnode* next = NULL;

	while(*root){
		next = (*root)->next;
		free(*root);
		*root = next;
	}
}

void print_slist(slnode* root)
{
	while (root != NULL) {
		printf("%d, ", root->num);
		root = root->next;
	}
}


