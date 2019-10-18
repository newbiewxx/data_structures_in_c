/* 2019年10月18日 16:28:10 */
#include<stdio.h>
/*
线性表定义:
是零个或多个数据元素构成的线性序列，即为(a0, a1, a2, ....., an-1).
当n = 0 时，此时线性表为空表.
由于线性表是一对一的关系，除了首元素没有前驱，为元素没有后驱，因此为线性结构
线性表有两种典型的存储结构：
	1.顺序存储结构
	2.链式存储结构
顺序存储是指内存上连续的内存空间
第一个元素在内存上的存储地址为loc(a0),每个元素占用k个存储单元
则任意元素ai的内存存储地址为 :  loc(ai) = loc(a0) + i * k
这可以解释为什么数组的索引为什么要从0开始了
因为如果索引值从1开始，公式就应该为 loc(ai) = loc(a1) + (i - 1) * k
很明显，多了一个 (i - 1)的指令了，会资源和时间了。

线性表的顺序结构定义如下:  
*/

typedef struct {
	int n;  // 顺序表的长度，即数序表中的元素个数
	int maxLength;  // 顺序表允许的最大长度
	ElemType * element;  // 指针element指示数序表的存储空间首地址
} SeqList;
/* 注意，Elemtype 类型 :根据用户需要将它具体定义



/* 顺序表的基本运算的实现
顺序表的初始化运算是使用了动态分配数组空间方式构造的一个空的线性表，
动态分配数组空间可以有效利用存储空间的目的。
算法步骤：
1. 为顺序表L动态分配一维数组
2. 若动态分配一维数组失败，则返回出错信息，反则返回OK
 */



// 初始化
#define ERROR 0
#define OK 1
#define Overflow 2   // 表示上溢
#define Underflow 3  // 表示下溢
#define Nopresent 4	 // 表示元素不存在
#define Duplicate 5	 // 表示重复元素
typedef int Status;	// 自定义 int 类型为 Status
Status Init(Seqlist * L, int mSize) {
	L -> maxLength = msize;  // 顺序表的最大长度为mSize
	L -> n =0;  // 顺序表元素个数为0
	L -> element = malloc(sizeof(ElemType * mSize));  // 动态生成一维数组
	if (!L -> element)  // 如果分配的一位数组失败
		return ERROR;
	else
		return OK;
}
 

/* 查找 
算法步骤：
1. 判断所要查找的元素下标i是否越界，若越界，返回ERROR
2. 若下标i为越界，则去除element[i]的值通过x返回
*/

Status Find(Seqlist L, int i, ElemType * x) {
	if (i < 0 || i > L.n-1) {
		return ERROR;
	}else {
		* x = L.element[i];
	}
	return OK;
}


/* 插入
算法步骤：
1. 判断元素下标i是否越界，若已越界，返回ERROR
2. 判断存储空间是否已满，已满返回ERROR
3. 将元素(ai+1,........an-1)依次向后移动一个位置
4. 将新元素x放入下标i+1的位置
5. 表长+1
*/
Status Insert(Seqlist *L, int i, ElemType x) {
	int j;
	if (i < -1 || i > L -> n-1) {  // 判断下标i是否越界
		return ERROR;
	}
	if (L -> n == L -> maxLength) { // 判断数序表存储空间是否已满
		return ERROR;
	// 这是元素后移的关键实现代码
	for (j = L -> n-1; j > i; j--) {
		L -> element[j+1] = L -> element[j];  // 从后往前逐个后移元素
	}
	// 此时还空出了一个位置，即是i后面空出了一位
	L -> element[i+1] = x;   // 将新元素放入下标为i+1的位置
	L -> n = L -> n+1; // 表长+1
	return OK;
} 


/* 删除
算法步骤：
1. 判断元素下标i是否越界,若不越界，返回ERROR
2. 判断数序表是否为空，若为空，返回ERROR
3. 将元素(ai+1,...,an-1)依次向前移动一个位置
4. 表长-1
*/
Status Delete(Seqlist *L, int i) {
	int j;
	if (i < 0 || i > L -> n-1) {  // 下标是否越界
		return ERROR;
	}
	if (!L -> n) {  // 顺序表是否为空
		return ERROR;
	}
	// 这是元素前移的关键实现代码
	for (j = j+1; j < L -> n; j++) {
		L -> element[j-1] = L -> element[j];  // 从前往后逐个前移元素
	}
	L -> n --;  // 表长-1
	return OK;
}

/* 输出
算法步骤:
1. 判断顺序表是否为空，若为空,返回ERROR
2. 将元素(a0, a1, ......an-1)依次输出
*/

Status Output(Seqlist L) {
	int i;
	if (!L.n) // 判断顺序表是否为空
	return ERROR;
	for (i = 0; i < L.n; i++) {
		printf("%d", L.element [i]); // 从前往后逐个输出元素
	}
	return OK;
}

/* 撤销
释放内存
*/

void Destory(Seqlist * L) {
	(*L).n = 0;  // 元素个数改为0
	(*L).maxlength = 0; // 最大长度改为0
	free((*L).element); // 释放内存
}
