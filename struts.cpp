//
//
// Exercises of data structures for interview preparation
//

#include <stdio.h>
#include "linkedlist.h"

int main()
{
	slnode* root = init_slist(20);
	
	sl_insert(root, 15);

	print_slist(root);

	sl_insert(root, 45);

	print_slist(root);



}


