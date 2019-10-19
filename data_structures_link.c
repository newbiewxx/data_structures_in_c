/* 2019年10月19日 15:30:13 */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

/*
链式存储存储结构的线性表称之为链表，常见有三种
1. 单链表
2. 双链表
3. 循环链表

 单链表的类型定义：
 */
 typedef struct Node
 {
	int n;   // 存放数据域
	struct Node * link; // 存放指针域
 }Node; // 结构体类型变量
 
 typedef int Status;  // 自定义整形类型名
 typedef struct Node SingleList;  // 自定义结构体类型名

 // 初始化，构建一个空的单链表 , first为头指针
Status Init(SingleList * L)
{
	L -> first = NULL; // 指向为空
	L -> n = 0; // 数据域为0
	return 1; // 创建空链表成功
}

/* 查找
算法步骤：
1. 判断i是否越界
2. 从头结点开始顺着单链表往下找
3. 将ai的值通过x返回
*/

Status find(SingleList L, int i, int *  x) {
	Node * p; // 创建一个结构体指针变量
	int j;
	if (i<0 || i>L.n-1) {  // 判断是否越界
		return 0;
	}
	p = L.first;
	for (j=0; j<i; j++) {  // 把元素ai之前的数全部遍历
		p = p -> link;  // 指针依次下移
	}
	*x = p -> n;  // 通过x返回ai的值
	return 1;
}

/* 插入
算法步骤
1. 判断i是否越界，若越界，则返回0
2. 查找ai，指针p指向此结点 
3. 生成新结点，将新结点的数据域插入x，将q指向此结点
4. 若i=-1，新结点q插在头结点前，成为新的头结点，若i>-1，将q所指向的结点插在p所指向的结点之后
5. 单链表元素+1，返回1
*/
Status Insert(SingleList * L, int i, int x)
{	
	Node * p, * q;
	int j;
	if (i<-1 || i > L->n-1) {
		return 0;
	}
	p = L -> first;
	for (j=0; j<i; j++) {  // 从头开始查找ai
		p = p -> link;
	}
	q= (Node *)malloc(sizeof(Node));  // 动态生成一个新结点
	q -> n = x; // 给数据域赋值
	if (i > -1) {  // 不插在头结点前
		q -> link = p ->link;
		p -> link = q;
	}
	else  // 插在头结点前，称为新的头结点
	{
		q -> link = L.first;
		L.first = q;
	}
	L -> n++;  // 链表元素+1
	return 1;
}

/* 删除
算法步骤
1. 若i已经越界或为单链表为空，返回0
2. 查找元素ai的直接前驱ai-1,并令指针q指向它
3. 若i=0，则从单链表中删除头结点，若i>0,则使p指向ai所在的结点，并从单链表中删除ai
4. 释放p所致指向结点的存储空间
5. 单链表元素个数-1，返回1
*/

Status Delete(SingleList * L, int i)
{	
	int j;
	Node * p,* q;
	if (!L->n)  // 判断是否为空，为空，返回0 
	{
		return 0;
	}
	q = L -> first; // 将q作为头指针
	p = L -> first; // 将q作为头指针
	for (j=0; j<i-1;j++) {
		q = q -> link; // 指针后移,最终q指向ai-1的地址
	}
	if (i == 0) {
		L -> first = L -> first -> link; // 删除头结点
	}
	else
	{	
		p = q -> link;  // p指向ai的地址
		q -> link = p -> link;  // 将q指向 ai+1的地址
	}
	free(p); // 释放p结点所指向的存储空间
	L ->n--;  // 链表长-1
	return 1;
}


/* 输出
算法步骤:
1. 首先判断链表是否为空
2. 将元素依次输出
*/

Status Output(SingleList L)
{
	Node * p;
	if (!L.n) {
		return 0;
	}
	p = L.first; // 将头指针给p
	while (p)
	{
		printf("%d", p -> element);
		p = p -> link;
	}
	return 1;
}


/* 撤销，防止内存泄漏 */
void Destory(SingleList * L) 
{
	Node * p;
	while (L -> frist)
	{
		p = L -> frist -> link;  // 保存后继结点地址，防止"断链"
		free(L -> first);  // 
		L -> first = p; 
	}
}


