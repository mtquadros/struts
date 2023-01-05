//
//
// Exercises of data structures for interview preparation
//

#include <stdio.h>
#include "linkedlist.h"


int main()
{
	slnode* root = init_slist(20);
	
	sl_insert(&root, 15);

	sl_insert(&root, 45);

	sl_insert(&root, 2);

	sl_insert(&root, 21);

	sl_insert(&root, 46);

	print_slist(root);



}


