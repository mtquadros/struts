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

	slnode* tmp = NULL;

	while (*root) {
		if ((*root)->num == value){
            tmp = *root;
            *root = tmp->next;
            free(tmp);
            return;
		}
		root = (*root)->next;
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
        if (node->num > value)
            break;
        prev = node;
        node = node->next;
    }
    slnode *tmp = (slnode *) malloc(sizeof(slnode));
    tmp->num = value;

// prev == NULL  && node == ADDR
// prev == ADDR  && node == ADDR
// prev == ADDR  && node == NULL  && ((num > value) ||

    if (prev == NULL){
        //atualiza root
        tmp->next = *root;
        *root = tmp;
    }
    else{
        //insere entre prev e node
        tmp->next = prev->next;
        prev->next = tmp;
    }


#ifdef _DEBUG_ME_
    assert(prev->next == NULL || prev->next->num >= value);
	assert(root->num <= root->next->num);
#endif // _DEBUG_ME_

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


