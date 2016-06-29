#ifndef __BITREE_H
#define __BITREE_H

//使用线索化二叉树
#define BI_THREAD

//打印调试信息
#define DEBUG

typedef char TElemType;

#ifdef BI_THREAD
typedef enum
{
	LINK,
	THREAD
}pTag;
#endif

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
#ifdef BI_THREAD
	pTag ltag;
	pTag rtag;
#endif
}BiTNode,*bitree;

void create_bitree(bitree *t);
void preorder_traverse(bitree t);
void inorder_traverse(bitree t);
void postorder_traverse(bitree t);
void init_bitree(bitree *t);

#endif
