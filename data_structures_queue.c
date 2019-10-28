/* 2019年10月28日 22:16:00 */
#include<stdio.h>
#include<malloc.h>

/* 循环队列的实现 */

// 循环队列的结构体定义
typedef struct {
	int front;
	int rear;
	int maxSize;
	Element * element;
}Queue;

// 创建一个能容纳mSize个单元的空队列
void Create(Queue *Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element = (ElemType *) malloc (sizeof(ElemType) *mSize); // 分配内存空间
	Q->front = Q->rear = 0 // 初始值为0
}

// 销毁一个已经存在的队列，即释放队列所占用的数组空间
void Destroy(Queue *Q)
{
	Q->maxSize = -1;
	free(Q->element);
	Q->front = Q->rear = -1;
}

// 判断队列是否为空
bool IsEmpty(Queue * Q)
{
	return Q->front = Q->rear;  // 当队头队尾在同一点上
}

// 判断队列是否已满
bool IsFull(Queue * Q)
{
	if((Q->rear+1) % Q->maxSize == Q->front) {  // 当对头为队尾相邻是，且队尾+1 恰等于对头即为已满
		return true;
	}
	else
	{
		return false;
	}
}

// 获取对头元素，并通过x返回
bool Front(Queue * Q, ElemType * x)
{
	if (IsEmpty(Q)) {
		return fasle;
	}
	else
	{
		*x = Q->element[Q->front]		
		pQ->front = (pQ->front+1) % Q->maxSize;
		return true;
	}
}

// 在队列中插尾中插入x
bool EnQueue(Queue * Q, ElemType x)
{
	if (IsFull(Q)) {
		return false;
	}
	else
	{
		Q->element[Q->rear] = x;
		Q->rear = (Q->rear+1) % Q->maxSize;
		return true;
	}
}

// 从队列中删除对头元素
bool DeQueue(Queue * Q)
{
	if (IsEmpty(Q)) {
		return fasle;
	}
	Q->front = (Q->front+1) % Q->maxSize;
	return true;
}

// 清除队列元素，但不释放空间
void Clear(Queue * Q)
{
	Q->front = Q->rear = 0;
}

