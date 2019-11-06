/* 2019年11月6日 10:15:40 */
#include<stdio.h>
#include<malloc.h>

/* 二叉树的实现--孩子表示法 */

struct BinaryTreeNode {
	char data;
	struct BinaryTreeNode * lChild, * rChild;
};

/* 先序遍历 */

void PreOrderTransverse(struct BinaryTreeNode * t) {
	if (t == NULL) {
		return;
	}

	printf("%c  ", t->data);
	// 递归遍历左子树
	PreOrderTransverse(t->lChild);
	// 递归遍历右子树
	PreOrderTransverse(t->rChild);
}

/* 中序遍历 */

void InOrderTransverse(struct BinaryTreeNode * t) {
	if (t == NULL) {
		return;
	}

	// 递归遍历左子树
    InOrderTransverse(t->lChild);
	printf("%c  ", t->data);
	// 递归遍历右子树
	InOrderTransverse(t->rChild);
}

/* 后序遍历 */

void PostOrderTransverse(struct BinaryTreeNode * t) {
	if (t == NULL) {
		return;
	}

	// 递归遍历左子树
    PostOrderTransverse(t->lChild);
	// 递归遍历右子树
	PostOrderTransverse(t->rChild);
	printf("%c  ", t->data);
}

struct BinaryTreeNode * CreateBTree(void)
{
	 struct BinaryTreeNode * pA=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode ));
	 struct BinaryTreeNode * pB=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	 struct BinaryTreeNode * pC=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode ));
	 struct BinaryTreeNode * pD=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode ));
	 struct BinaryTreeNode * pE=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode ));
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';

	pA->lChild=pB;
	pA->rChild=pC;
	pB->lChild=pB->rChild=NULL;
	pC->lChild=pD;
	pC->rChild=NULL;
	pD->lChild=NULL;
	pD->rChild=pE;
	pE->lChild=pE->rChild=NULL;
	return pA;
}

int main() {
	struct BinaryTreeNode * T =  CreateBTree();
		// 先序遍历
	PreOrderTransverse(T);
	printf("\n");
		// 中序遍历
	InOrderTransverse(T);
	printf("\n");
		// 后序遍历
	PostOrderTransverse(T);
}
