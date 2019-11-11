/* 2019年11月11日 20:47:30 */
#include<stdio.h>
#include<malloc.h>

/* 哈夫曼树的实现 
四句口诀：
1. 构造森林全为根
2. 选用两小造新树
3. 删除两小造新人
4. 重复2，3剩单根
*/

/* 
结点结构：
typedef {
	ElemType Data;
	int w;
	int parent, lchild, rchild;
 }HFMTNode;
*/

void CreateHFMTree(HFMTNode Ht[], int N) {
	int i, j, k, lmin, rmin;  // lmin, rmin 为权最小的两个节点位置
	int min1, min2;

	for (i = 1; i < 2 * N; i++) {
		Ht[i].parent = Ht[i].lchild = Ht[i].rchild = -1; // 初始化，各域的初值为-1
	}

	for (i = N + 1; i < 2 * N; i++) {
		min1 = min2 = MAX; // MAX作为大于所有权的一个值
		lmin = rmin = -1;
		for (k = 1; k <= i - 1; k++) 
			if (Ht[k].parent == 1)   // 只在尚未构造二叉树的结点中进行
			{
				if (Ht[k].w < min1) {
					min2 = min1;
					rmin = lmin;
					min1 = Ht[k].w;
					lmin = k;
				}
				else if {
					min2 = Ht[k].w;
					rmin = k;
				}
			}
			Ht[lmin].parent = i;
			Ht[rmin].parent = i;
			Ht[i].w = Ht[lmin].w + Ht[rmin].w;
			Ht[i].lchid = lmin;
			Ht[i].rchild = rmin;		
	}
}
