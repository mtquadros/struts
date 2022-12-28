#include "linkedlist.h"
#include <stdlib.h>
#include <assert.h>

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

	slnode* found;
	found = root;
	while (!found) {

		if (found->num == value)
			break;
		else
			found = found->next;
	}
#ifdef _DEBUG_ME_
	assert(found == NULL || found->num == value);
#endif
	return found;
}

void sl_remove(slnode* root, slnode* node) {
	slnode** indirect = &root;

	while ((*indirect) != node){
		indirect = &(*indirect)->next;
	}

	*indirect = node->next;
	// *indirect
#ifdef _DEBUG_ME_
	assert(slfind(root, (*indirect)->num));
#endif
}

void sl_insert(slnode* root,int value){
    slnode* prev = root;
    slnode* tmp;

    while (prev->next){
        if (prev->next->num < value)
            prev = prev->next;
        else
            break;
    }
    //prev->next == NULL || prev->next->num >= value
#ifdef _DEBUG_ME_
    assert(prev->next == NULL || prev->next->num >= value);
#endif // _DEBUG_ME_
    tmp = (slnode *) malloc(sizeof(slnode));
    tmp->next = prev->next;
    prev->next = tmp;

}


