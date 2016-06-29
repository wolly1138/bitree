#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

#ifdef BI_THREAD
//记录刚刚访问过的节点
bitree pre;
#endif

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
#ifdef DEBUG
		printf("data=%c,p=0x%x\n",ch,*t);
#endif
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

#ifdef BI_THREAD
void inoder_threading(bitree p)
{
	if(p)
	{
		inoder_threading(p->lchild);

		if(!p->lchild)
		{
			p->ltag = THREAD;
			p->lchild = pre;
		}
		else
		{
			p->ltag = LINK;
		}

		if(!pre->rchild)
		{
			pre->rtag = THREAD;
			pre->rchild = p;
		}
		else
		{
			pre->rtag = LINK;
		}

		pre = p;

		inoder_threading(p->rchild);
	}
}

void inorder_traverse_thr(bitree t)
{
	bitree p;
	p = t->lchild;
#ifdef DEBUG
	printf("data=%c, p=0x%x, ltag=%d, rtag=%d,lchild=0x%x, rchild = 0x%x\n",\
			t->data,t,t->ltag,t->rtag,t->lchild,t->rchild);
#endif
	while(p != t)
	{
		while(p->ltag == LINK)
			p = p->lchild;
#ifdef DEBUG
		printf("data=%c, p=0x%x, ltag=%d, rtag=%d,lchild=0x%x, rchild = 0x%x\n",\
				p->data,p,p->ltag,p->rtag,p->lchild,p->rchild);
#else
		printf("%c",p->data);
#endif
		while(p->rtag == THREAD && p->rchild != t)
		{
			p = p->rchild;
#ifdef DEBUG
		printf("data=%c, p=0x%x, ltag=%d, rtag=%d,lchild=0x%x, rchild = 0x%x\n",\
				p->data,p,p->ltag,p->rtag,p->lchild,p->rchild);
#endif
			printf("%c",p->data);
		}

		p = p->rchild;
	}

	printf("\n");
}

#endif

void init_bitree(bitree *t)
{
#ifdef BI_THREAD
	//生成头节点
	*t = (bitree)malloc(sizeof(BiTNode));

	if(!*t)
			exit(1);

	(*t)->data = '.';

	//将数据节点生成在头节点的左侧
	(*t)->ltag = LINK;
	create_bitree(&(*t)->lchild);

	printf("\n");

	//右侧初始化为空
	(*t)->rtag = THREAD;
	(*t)->rchild = NULL;

	//首数据节点前驱为头节点
	pre = *t;

	//线索化序列，输入为数据分支
	inoder_threading((*t)->lchild);
	
	//尾数据右指针指向头节点
	pre->rtag = THREAD;
	pre->rchild = *t;

	//修改头节点后继为尾数据节点
	(*t)->rtag = THREAD;
	(*t)->rchild = pre;
#else
	create_bitree(t);
#endif
}

