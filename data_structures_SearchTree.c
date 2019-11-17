/* 2019年11月17日 16:28:42 */
#include<stdio.h>

/* 二叉搜索树的查找  利用递归查找 */
BSTNode * SearchRecursion(BSTNode * t, ElemType element) {
	if (t == null) {  // 当前结点为空时，返回NULL
		printf("ERROR\n");
		return NULL;
	}

	if (t->Element.Key == Element.Key) {  // 如果值相同则返回该节点
		return t;  
	}

	else if (t->Element.Key > Element.Key) {  // 如果查找值小于当前结点，则从该节点左子树查找
		SearchRecursion(t->Lchild, Element);
	}
	
	else {									  // 如果查找值大于当前结点，则从该节点右子树查找
		SearchRecursion(t->Rchild, Element);
	}
}


/* 二叉搜索树的插入 利用递归插入 */
BSTNode * CreateNode(ElemType element) {   // 创建新插入节点
	BSTNode *p = (BSTNode *) malloc (sizeof(BSTNode));
	if (NULL == p) {
		return NULL;
		p->Element.Key = element.Key;
		p->Lchild = p->Rchild = NULL;
		return p;
	}
}

Status Insert(BSTNode * t, ElemType Element) {
	if (t == NULL) {  // 当节点为空节点时，插入新结点
		t = CreateNode(element);
	}

	else if (t->Element.Key > element.Key) { // 当插入值小于当前节点值，则从该节点左子树找插入点
		t->Lchild = Insert(t->Lchild, element);
	}

	else if (t->Element.Key < element.Key) { // 当插入值大于当前节点值，则从该节点右子树找插入点
		t->Rchild = Insert(t->Rchild, element);
	}
	
	else if (t->Element.Key == element.Key) {  // 当插入值等于当前节点值，则从该节点重新标志
		return Duplicate; 
	}
	return OK;
}

/* 二叉搜索树的删除 */
Status Delete(BSTNode *t, int key, ElemType element) {
	if (t == NULL) {
		return NotPresent;
	}

	BSTNode *p = t; *prev;
	while (p && p->Element.Key != key) {
		prev = p;
		if (p->Element.Key > key) {
			p = p->Lchild;
		}
		else {
			p = p->Rchild;
		}
	}

	if (p == NULL) {
		return ERROR;
	}

	ElemType.Key = Key; 

	if (p->Lchild && p->Rchild) {
		BSTNode * min = p->Rchild;  // 右子树最小节点
		prev = p;
		while (min->Lchild) {  // 找到右子树最小节点
			prev = min;
			min = min->Lchild;
		}
		p->Element.Key = min->Element.Key;  // 把找到的右子树的最小值与p进行值交换 

		if (prev->Rchild == min) {
			prev->Rchild = min->Rchild;
		}
		else {
			prev->Lchild = min->Rchild;
		}
		free(min);
		min = NULL;
	}
	else {
		if (prev->Lchild == p) {  // p为左子树的情况
			prev->Lchild = p->Lchild ? p->Lchild : p->Rchild;
		}
		else if { // p为右子树的情况
			prev->Rchild = p->Lchild ? p->Lchild : p->Rchild;
		}
		free(p);
		p = NULL;
	}
	return OK;
}
