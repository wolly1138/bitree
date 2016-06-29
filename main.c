#include <stdio.h>
#include "bitree.h"

bitree root;

int main(int argc, char* argv[])
{
	init_bitree(&root);
#ifdef BI_THREAD
	inorder_traverse_thr(root);
#else
	printf("\nPreoder:");
	preorder_traverse(root);
	
	printf("\nInoder:");
	inorder_traverse(root);

	printf("\nPostoder:");
	postorder_traverse(root);

	printf("\n");
#endif
	return 0;	
}

