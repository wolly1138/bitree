#include <stdio.h>
#include "bitree.h"

int main(int argc, char* argv[])
{
	bitree root;

	create_bitree(&root);

	printf("\nPreoder:");
	preorder_traverse(root);
	
	printf("\nInoder:");
	inorder_traverse(root);

	printf("\nPostoder:");
	postorder_traverse(root);

	printf("\n");
	return 0;	
}

