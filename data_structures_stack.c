/* 2019年10月23日 13:27:06 */
#include<stdio.h>

/*
堆栈(简称栈):  限定插入和删除操作都在表的同一端进行操作的线性表
允许插入和删除的一端称为栈顶(top),另一端称为栈底(bottom)，若无堆栈中无元素，为空栈。
设元素a0,a1.....an依次进栈，但元素出栈和进栈完全相反，就有(FILO)的特点:先进后出.
堆栈也分为顺序栈和链式结构栈
顺序栈可以用一维数组来实现，结构定义如下:
*/


// 堆栈结构体定义
typedef struct
{
	int top;
	int maxSize;
	ElemType * element;
}Stack;

// 创建一个能容纳mSize个单元的空堆栈
void Create(Stack * S, int mSize)
{
	S->maxSize = mSize-1;  // 最大栈顶位置下标
	S->element = (ElemType *) malloc (sizeof(ElemType)*mSize;
	s->top = -1;
}

// 销毁一个已经存在的堆栈，即释放堆栈所占的数组空间
void Destroy(Stack * S)
{
	S->maxSize = -1;
	free(S->elenment);
	s->top = -1;
}

// 判断堆栈是否为空栈，是则返回TRUE,不是则返回FALSE
bool isEmpty(Stack * S)
{
	return S->top == -1;
}

// 判断堆栈是否已满，慢则返回TRUE，不是则返回FALSE
bool isFull(Stack * S)
{
	return S->top == S->maxSize;
}

// 获取栈顶元素，并通过x返回，操作成功，返回TRUE，否则返回FASLE
bool Top(Stack * S, ElemType  x)
{
	if (isEmpty(S)) {  // 判断是否为空
		return FALSE;
	}
	x = S->element[S->top];
	return TRUE;
}

// 在栈顶插入元素x,入栈操作，成功返回TRUE,否则返回FASLE
bool Push(Stack * S, Element  x)
{
	if (isFull(S)) { // 判断是否已满
		return FALSE;
	}
	S->top++;
	S->element[S->top] = x;
	return TRUE;
}

// 删除栈顶元素，出栈操作，操作成功，返回TRUE,否则返回FALSE
bool Pop(Stack * S)
{
	if (isEmpty(S)) { // 判断是否为空
		return FASLE;
	}
	S->top--;
	return TRUE;
}

// 清楚栈中全部元素，但并不释放空间
void Clear(Stack * S)
{
	S->top = -1;
}
