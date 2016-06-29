#ifndef __BITREE_H
#define __BITREE_H

typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,*bitree;

void create_bitree(bitree *t);
void preorder_traverse(bitree t);
void inorder_traverse(bitree t);
void postorder_traverse(bitree t);

#endif
