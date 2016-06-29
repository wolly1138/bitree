#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

void create_bitree(bitree *t)
{
	TElemType ch;
	char *temp;
	scanf("%c",&ch);
	
	if(ch == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (bitree)malloc(sizeof(BiTNode));

		if(!*t)
			exit(1);
		
		(*t)->data = ch;

		create_bitree(&(*t)->lchild);
		create_bitree(&(*t)->rchild);
	}
	
}

void preorder_traverse(bitree t)
{
	if(t == NULL)
		return;

	printf("%c",t->data);
	preorder_traverse(t->lchild);
	preorder_traverse(t->rchild);
}

void inorder_traverse(bitree t)
{
	if(t == NULL)
		return;

	preorder_traverse(t->lchild);
	printf("%c",t->data);
	preorder_traverse(t->rchild);
}

void postorder_traverse(bitree t)
{
	if(t == NULL)
		return;

	preorder_traverse(t->lchild);
	preorder_traverse(t->rchild);
	printf("%c",t->data);
}

