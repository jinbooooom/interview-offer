



## 数据结构

### 栈

先进后出

### 队列

后进先出

**循环队列队空与队满**

队空条件为：front==rear
队满条件为：(rear+1)%QueueSize==front

### 链表

**循环链表**

循环链表(circular linked list)是另一种形式的链式存储结构，
它与单链表不同在于表中最后一个指针域指向头节点。整个链表形成一个环。

**双向链表**

单向链表只能顺指针往后寻找其他节点。若要寻查节点的直接前趋，则需要从表头指针出发。
为克服单链表的这种单向性的缺点，可利用双向链表（double linked list）。  
双向链表的节点中有两个指针域，其一指向直接后继，另一指向直接前趋。

### [树](https://blog.csdn.net/g360z247j123/article/details/51858563)

树的递归定义如下:
一棵树是一些节点的集合。这个集合可以为空集或非空集；
若树非空，则它由称为根(root)的节点r以及0个或多个非空的(子)树T1，T2，…Tk组成，
这些子树中每一棵树都被来自根r的一条有向的边(edge)所连接。 

**二叉树**

[二叉树的分类](https://www.cnblogs.com/sunshineliulu/p/7775063.html)

[轻松搞定面试中的二叉树题目](https://blog.csdn.net/luckyxiaoqiang/article/details/7518888)

二叉树（Binary Tree）是另一种树形结构，它的特点是每个结点至多只有两颗子树（即二叉树中不存在度大于二的节点）。并且，二叉树的子树有左右之分，其次序不能任意颠倒。

#### 最优二叉树：赫夫曼树(Huffman)

从树的一个结点到另一个结点之间的分支构成这两个结点之间的路径，结点的带权路径长度为从该结点到树根之间的路径长度与结点上权的乘积。树的带权路径长度为树中**所有叶子节点**的带权路径长度之和。

其中，带权路径长度最小的二叉树被称为最优二叉树或赫夫曼树。

#### 二叉排序树(Binary Sort Tree, BST)

或者是一棵空树；

或者是具有下列性质的二叉树：

- 若它的左子树不为空，则左子树上所有的结点的值均小于它的根结点的值；
- 若它的右子树不为空，则右子树上所有的结点的值均大于它的根结点的值；
- 它的左右子树也都是二叉排序树。

#### **平衡二叉树（Balanced Binary Tree, AVL）**

AVL 不是 Balanced Binary Tree 的缩写，是它的发明者  Adelse-Velskil 和 Landis 的缩写。

定义：

或者是一棵空树；

或者是具有下列性质的二叉树：

- 它的左子树和右子树都是平衡二叉树，且左子树和右子树的深度之差的绝对值不超过 1。

#### 红黑树

红黑树是每个节点都带有颜色属性的二叉查找树，颜色或红色或黑色。在二叉查找树强制一般要求以外，对于任何有效的红黑树我们增加了如下的额外要求:

性质1. 节点是红色或黑色。

性质2. 根节点是黑色。

性质3 每个红色节点的两个子节点都是黑色。(从每个叶子到根的所有路径上不能有两个连续的红色节点)

性质4. 从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。

这些约束强制了红黑树的关键性质:  从根到叶子的最长的可能路径不多于最短的可能路径的两倍长。结果是这个树大致上是平衡的。因为操作比如插入、删除和查找某个值的最坏情况时间都要求与树的高度成比例，这个在高度上的理论上限允许红黑树在最坏情况下都是高效的，而不同于普通的二叉查找树。

要知道为什么这些特性确保了这个结果，注意到性质3导致了路径不能有两个毗连的红色节点就足够了。最短的可能路径都是黑色节点，最长的可能路径有交替的红色和黑色节点。因为根据性质4所有最长的路径都有相同数目的黑色节点，这就表明了没有路径能多于任何其他路径的两倍长。

## 排序

![](sources\sort.jpg)

### 插入排序

```C++
void insert(int *arr, int len)
{
	int i, j, t;
	for (i = 1; i < len; ++i)
	{
		t = arr[i];
		for (j = i - 1; j >= 0 && t < arr[j]; --j)
			arr[j + 1] = arr[j];
		arr[j + 1] = t;
	}
}
```

### 冒泡排序

```C++
void bubble(int *arr, int len)
{
	int t;
	for (int i = 0; i < len - 1; ++i)
		for (int j = 0; j < len - i - 1; ++j)
			if (arr[j] > arr[j + 1])
				t = arr[j], arr[j] = arr[j + 1], arr[j + 1] = t;
}
```

### 选择排序

```C++
void select(int *arr, int len)
{
	int i, j, k, t;
	for (i = 0; i < len - 1; ++i)
	{
		k = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] < arr[k])
				k = j;
		if (k != i)
			t = arr[i], arr[i] = arr[k], arr[k] = t;
	}
}
```



### 快速排序

```C++
int partition(int *arr, int low, int high)
{
	int key = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];
		while (low < high && arr[low] <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = key;
	return low;
}

void quick(int *arr, int start, int end)
{
	int pos;
	if (start < end)
	{
		pos = partition(arr, start, end);
		quick(arr, start, pos - 1);
		quick(arr, pos + 1, end);
	}
}
```

### 归并排序

```C++
void Merge(int *arr, int low, int mid, int high)
{
	int i, k;
	int *tmp = (int *)malloc((high - low + 1) * sizeof(int));
	int left_low = low, left_high = mid;
	int right_low = mid + 1, right_high = high;
	for (k = 0; left_low <= left_high && right_low <= right_high; k++)
		if (arr[left_low] <= arr[right_low])
			tmp[k] = arr[left_low++];
		else
			tmp[k] = arr[right_low++];
	if (left_low <= left_high)
		for (i = left_low; i <= left_high; i++)
			tmp[k++] = arr[i];
	if (right_low <= right_high)
		for (i = right_low; i <= right_high; i++)
			tmp[k++] = arr[i];
	for (i = 0; i<high - low + 1; i++)
		arr[low + i] = tmp[i];
	free(tmp);
}

void Merge_sort(int *arr, unsigned int first, unsigned int last)
{
	int mid = 0;
	if (first < last)
	{
		mid = (first + last) / 2;
		Merge_sort(arr, first, mid);
		Merge_sort(arr, mid + 1, last);
		Merge(arr, first, mid, last);
	}
}
```



## 字符串库函数实现

### 交换两个字符串

```C++
// 引用符号 & 去掉就不能交换了，用引用指针代表传的指针是实参而不是形参，s1, s2便不是一个临时的拷贝。
void swap(char *&s1, char *&s2)  
{
	char *tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

int main(int argc, char* argv[]) {
	char * s1 = "hello ";
	char * s2 = "world ";
	cout << s1 << s2 << endl;
	swap(s1, s2);
	cout << s1 << s2 << endl;
	system("pause");
}
/* 打印
hello world
world hello
*/
```

### 将数字转化为字符串

```C++
void int2str(int n, char *str)
{
	int num = n > 0 ? n : -n;
	if (str == nullptr)
		return;

	char buf[10] = " ";
	int i = 0, j = 0;
	while(num)
	{
		buf[i++] = num % 10 + '0';
		num /= 10;
	}
	
	int len = n > 0 ? i : ++i;
	str[len] = '\0';
	if (n < 0)
	{
		j = 1;
		str[0] = '-';
	}

	for (; j < len; ++j)
	{
		str[j] = buf[len - 1 - j];
	}
}
```

### 将字符串转换为数字

```C++
int str2int(const char *str)
{
	int tmp = 0;
	const char *ptr = str;
	if (*ptr == '-' || *ptr == '+')
	{
		++ptr;
	}

	while (*ptr != '\0')
	{
		if (*ptr < '0' || *ptr > '9')
		{
			break;
		}
		tmp = tmp * 10 + *ptr - '0';
		++ptr;
	}
	ptr = str;  // 重新让 ptr 指向字符数组的首地址 
	if (*ptr == '-')
		tmp = -tmp;
	return tmp;
}
```

### 实现字符串赋值函数 strcpy

```C++
char *strcpy(char *strDst, char *strSrc)  // 返回 char* 的目的是可以链式使用
{
	if (strDst == nullptr || strSrc == nullptr)
		return nullptr;

	char *strDstCopy = strDst;
	while ((*strDst++ = *strSrc++) != '\0');
	return strDstCopy;
}
```

### 实现计算字符串长度的函数 strlen

```C++
int myStrlen(const char *str)
{
	assert(str != nullptr);			// 需要头文件 #include <assert.h>
	//if (str == nullptr) return 0;
	const char *p = str;
	while (*str++ != '\0');
	return str - p - 1;
}
```

### 实现字符串中子串的查找函数 strstr

[leetcode 28 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr)

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

```C++
// 返回索引的形式：例如 haystack:“abcde”，needle:”bcd“，返回 1
int strStr(string haystack, string needle) {
        if (!needle.size())
            return 0;
        if (!haystack.size())
            return -1;
        
        int i = 0, j = 0;
    
    	// haystack.size() - needle.size() + 1是无符号整型，
        // 有符号与无符号比较，自动把有符号转换成无符号
        while (i < int(haystack.size() - needle.size() + 1))
        {
            while (j  < needle.size())
            {
                if (haystack[i] != needle[j])
                {
                    i = i - j + 1;
                    j = 0;
                    break;
                }
                else
                {
                    ++i;
                    ++j;  
                }
            }
            if (j == needle.size())
            return i - j;  
        }
        return -1;
    }
```

```C++
// 返回指针的形式:例如 src:"abcdef"，sub:"cde"，
// 那么 strstr(src, sub) 会返回 src 中的字符 'c' 的地址，打印出来就是 "cdef"
// 如果想得到偏移量（索引），让 strstr 的返回值减去 src 的首地址。
const char *strstr(const char *src, const char* sub)
{
	if (src == nullptr || sub == nullptr) 
		return src;
	const char *psrc, *psrcCopy = src;
	const char *psub;

	while (*src)
	{
		psrc = src;
		psub = sub;
		do
		{
			if (!*psub)
				return src;
		} while (*psub++ == *psrc++);
		src += 1;
	}
	return psrcCopy;
}
```

### 实现字符串比较函数 strcmp

```C++
int myStrcmp(const char *src, const char *dst)
{
	if (src != nullptr && dst == nullptr)
		return *src;
	else if (src == nullptr && dst == nullptr)
		return 0;
	else if (src == nullptr && dst != nullptr)
		return -*dst;

	while (*src && *dst && *src == *dst)
	{
		src++;
		dst++;
	}
	return *src - *dst;
}
```

### 实现字符串连接函数 strcat

```C++
char *myStrcat(char *dst, char *src)
{
	assert(src != nullptr && dst != nullptr);	// src 与 dst 非空
	assert(dst != src);							// 不能让一个字符串与其本身连接

	char *dstCopy = dst;
	while (*dst)
		dst++;
	while (*dst++ = *src++);
	return dstCopy;
}
```

### 字符串中各单词反转，而单词内部结构不变

例子：将` ”I am from Shanghai“ `转换为 `”Shanghai from an I“`。

思路：字符指针 start 指向单词首位，字符指针 end 指向空格的前一位，对 start 和 end 区间的单词反转。则原单词为转换为 `”I ma morf iahgnahs“`，再对整个字符串进行反转。

## 链表

### [反向打印链表](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 输入一个链表，按链表从尾到头的顺序返回一个`ArrayList。 `
>
> 函数定义`vector<int> printListFromTailToHead(ListNode* head)`

```C++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(nullptr) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head == nullptr)
            return vec;
        
        stack<ListNode*> stk;
        ListNode* pNode = head;
        
        while(pNode)
        {
            stk.push(pNode);
            pNode = pNode->next;
        }
        
        while(!stk.empty())
        {
            pNode = stk.top();
            vec.push_back(pNode->val);
            stk.pop();
        }
        return vec;
    }
};
```

### 删除链表的节点

> 给定单向链表的头指针和节点指针，定义一个函数在O(1)时间内删除该节点。
>
> 函数定义`deleteNode(ListNode* pListHead, ListNode* pToBeDeleted)`

**提示：**

*链表 a->b->c->d->e->f，假设要删除 d，只需要将 d->val 赋给 c->val，然后让 c->next = d->next 就好。*

```C++
void deleteNode(ListNode* pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == nullptr || pToBeDeleted == nullptr)
		return;
	if (pToBeDeleted->next != nullptr)  // 要删除的节点不是尾节点
	{
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if(pListHead == pToBeDeleted)	// 链表只有一个节点，删除头节点
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}
	else								// 链表中有多个节点，且要删除的节点是尾节点
	{
		ListNode* pNode = pListHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}
```

### [删除链表中重复的节点](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=3&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5 
>
>`ListNode* deleteDuplication(ListNode* pHead)`

```C++
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)  // 链表为空或者只有一个节点
            return pHead;
        ListNode* pNext = pHead->next;
        if(pHead->val != pNext->val)
        {
            pHead->next = deleteDuplication(pNext);
            return pHead;
        }
        while(pHead->val == pNext->val && pNext->next != nullptr)
        {
            pNext = pNext->next;
        }
        if(pHead->val != pNext->val)        // 说明 pHead 到 pNext 之前的值都重复，应该删去
        {
            pHead = deleteDuplication(pNext);
            return pHead;
        }
        else								// 从 pHead 到尾节点的节点值都重复，全部删去
        {
            pHead = nullptr;
            return pHead;
        }
    }
};
```

### [链表中倒数第 k 个节点](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 输入一个链表，输出该链表中倒数第k个结点。 
>
>`ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)`

**提示：**

*倒数第 k 个结点就意味着该结点再走 k-1 次就可以到达尾结点，那么当一个快指针先从头结点处移动 k-1 次，然后快指针与慢指针同时移动，当快指针到底尾节点，慢指针就刚好到达了倒数第 k 个结点*

```C++
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0)  // 倒数第 0 个节点不存在
            return nullptr;
        ListNode* pSlow = pListHead;
        ListNode* pFast = pListHead;
        unsigned int cnt = 1;
        while (cnt < k)
        {
            if (pFast->next)    
                pFast = pFast->next;
            else            // 当 k 超过链表长度的时候
                return nullptr;
            cnt++;
        }
        while(pFast->next)
        {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
```

### [链表中环的入口结点](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=3&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>  给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。 
>
> `ListNode* EntryNodeOfLoop(ListNode* pHead)`

**提示：**

*假设有环，且知道环中节点的个数设为 n，那么设置两个指针 p1, p2 分别指向头节点，现在使 p2 先移动 n 步，p1 不动，再使 p1, p2 同时移动，那么当 p1, p2 相遇时，p1 指针指向的节点就是入口节点。*

***如何求环中节点个数 n?***

*设置两个指针，一快一慢，最开始都指向头节点。快指针 pFast 每次移动 2 步，慢指针 pSlow 每次移动 1 步，若 pFast 能到达尾节点，则说明无环；若 pFast 能相遇，说明有环，当相遇时，慢指针 pSlow 保持位置不变，快指针改为每次移动 1 步，直到再次与慢指针相遇，移动了多少步，环中就含有多少个节点。*


```C++
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        int NodeOfLoop = 1;
        
        while (pFast)
        {
            if (pFast->next && pFast->next->next)
            {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
            }
            else
                return nullptr;
            
            if (pFast == pSlow)
            {
                pFast = pFast->next;
                //NodeOfLoop++;
                while (pFast != pSlow)
                {
                    pFast = pFast->next;
                    NodeOfLoop++;
                }
                if (NodeOfLoop == 1)        // 环中只有一个结点，pSlow 就是环的入口结点
                    return pSlow;
                break;
            }
        }
        
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while (NodeOfLoop)
        {
            p2 = p2->next;
            NodeOfLoop--;
        }
        while (p1 != p2)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};
```

### [反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>  输入一个链表，反转链表后，输出新链表的表头。 
>
> `ListNode* ReverseList(ListNode* pHead)`

**提示：**

*用多个指针分别记录当前节点，以及它的前驱和后继。*


```C++
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr)  // 链表为空或者只含有一个结点
            return pHead;

        ListNode* pre = nullptr;
        ListNode* pNode = pHead;
        ListNode* pNext = pNode->next;
        pNode->next = pre;
        
        while (pNext)
        {
            if (pNext->next)
            {
                ListNode* pNextNext = pNext->next;
                pre = pNode;
                pNode = pNext;
                pNext = pNextNext;
                pNode->next = pre;
            }
            else
            {
                pNext->next = pNode;
                return pNext;
            }
        }
    }
};
```

### [合并两个有序的链表](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>  输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。 
>
> `ListNode* Merge(ListNode* pHead1, ListNode* pHead2)`

**提示：**

*非常类似归并排序的归并过程：*

*若两链表任何一个为空，则返回剩下的那一个；*

*若均不为空，则找到两个链表中值小的那个，添加到新链表尾部；*

*若最后有某一个链表为空，说明它的节点都被添加到新链表上，直接把另一个非空链表剩下部分添到到新链表尾部*


```C++
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        else if (pHead2 == nullptr)
            return pHead1;
        
        ListNode* head = nullptr;
        if (pHead1->val < pHead2->val)
        {
            head = pHead1;
            pHead1 = pHead1->next;
        }
        else 
        {
            head = pHead2;
            pHead2 = pHead2->next;
        }
        
        ListNode* p = head;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
                p = p->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
                p = p->next;
            }
        }
        
        if (pHead1)
            p->next = pHead1;
        else if (pHead2)
            p->next = pHead2;
        return head;
    }
};
```



## 树

### [根据前序和中序重建二叉树](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都**不含重复**的数字。例如输入前序遍历序列 {1,2,4,7,3,5,6,8} 和中序遍历序列 {4,7,2,1,5,3,8,6}，则重建二叉树并返回。
>
> `TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)`

**提示：**
*知道前序遍历 pre = [1,2,4,7,3,5,6,8]，则根节点的值必然是 pre[0]，由于中序遍历会以根节点把树分成左右两部分，所以找到 pre[0] 在中序遍历列表中的位置（设为 index），就可以以 index 为分界线分别找到左右子树的前序中序序列。*

*左子树前序 left_pre 范围是 pre 中的 [1, index + 1）*

*左子树中序 left_vin 范围是 vin 中的 [0, index)*

*右子树前序 right_pre 范围是 pre 中的 [index + 1, end)*

*右子树中序 right_vin 范围是 vin 中的 [index + 1, end)*

```C++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        int rootValue = pre[0];
        TreeNode *tree = new TreeNode(rootValue);
        vector<int>::iterator itIndex = find(vin.begin(), vin.end(), rootValue);
        int index = itIndex - vin.begin();
        vector<int> left_pre(pre.begin() + 1, pre.begin() + index + 1);
        vector<int> left_vin(vin.begin(), vin.begin() + index);
        vector<int> right_pre(pre.begin() + index + 1, pre.end());
        vector<int> right_vin(vin.begin() + index + 1, vin.end());
        tree->left = reConstructBinaryTree(left_pre, left_vin);
        tree->right = reConstructBinaryTree(right_pre, right_vin);
        return tree;
    }
};
```
Python 版本足够精炼
```Python
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        if pre and tin:
            tree = TreeNode(pre[0])
            p = tin.index(pre[0])  # 下标 p 将 tin 分成左子树和右子树两部分
            # 找到每一个子数的 root 节点的下标，再将其分为左子树和右子树
            tree.left = self.reConstructBinaryTree(pre[1:p+1], tin[:p])
            tree.right = self.reConstructBinaryTree(pre[p+1:], tin[p+1:])
            return tree
```

### [树的子结构](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>  输入两棵二叉树 A，B，判断 B 是不是 A 的子结构。（ps：我们约定空树不是任意一个树的子结构 )
>
>  `bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)`

```C++
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr)  // 空树不是任何一个树的子结构
        {
            if (pRoot1->val == pRoot2->val)  // 根节点相等的时候，才逐个比较两树的结点
                result = isSubTree(pRoot1, pRoot2);
            if (!result)  // 根结点虽相同，但其他结点不同时，寻找 pRoot1 的左右子节点中是否有子树 pRoot2
                result = HasSubtree(pRoot1->left, pRoot2) || 
                		HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
    
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)  // 只要 pRoot2 为空，就说明遍历完了子树，返回 true
            return true;
        if (pRoot1 == nullptr)  // 必须先判断 pRoot2，在判断 pRoot1 是否为空
            return false;
        if (pRoot2->val != pRoot1->val)
            return false;
        else
            return isSubTree(pRoot1->left, pRoot2->left) && 
            		isSubTree(pRoot1->right, pRoot2->right);
    }
};
```

### [树的镜像](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 操作给定的二叉树，将其变换为原二叉树的镜像。
>
> 二叉树的镜像定义： 
>
> ```markdown
> 	 源二叉树
> 		8
>  	   /  \
>  	  6   10
>  	 / \  / \
>  	5  7 9 11
>  	镜像二叉树
>  	    8
>  	   /  \
>  	  10   6
>  	 / \  / \
>  	11 9 7  5
> ```
> `void Mirror(TreeNode *pRoot)`

```C++
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return;
        TreeNode *pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```

### [对称的二叉树](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。 
>
> `bool isSymmetrical(TreeNode* pRoot)`

```C++
// 法一：
// 判断树的左子结点与右子节点是否相等，若是，则递归判断下去
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return same(pRoot->left, pRoot->right);
    }
    
    bool same(TreeNode* pL, TreeNode* pR)
    {
        if (pL == nullptr && pR == nullptr)  // 左右结点同时为空，对称
            return true;
        if (pL == nullptr || pR == nullptr)  // 左右节点一个为空一个不为空，就说明不对称
            return false;
        if (pL->val != pR->val)
            return false;
        else 
            return same(pL->left, pR->right) && same(pL->right, pR->left);
    }
};
```

```C++
// 法二：若树对称，那么按根左右顺序打印的结果肯定和按根右左的顺序打印的结果一样
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return true;
        vector<TreeNode*> vLR, vRL; 
        traversalLR(pRoot, vLR);
        traversalRL(pRoot, vRL);
        // 有指针的比较大小一定要先判断指针是否为空，提领空指针会报段错误
        for (unsigned int i = 0; i < vLR.size(); ++i)
            if (vLR[i] == nullptr && vRL[i] == nullptr)
                continue;
            else if (vLR[i] == nullptr || vRL[i] == nullptr)
                return false;
            else if(vLR[i]->val != vRL[i]->val)
                return false;
        return true;
    }
    // 前序遍历，铵根左右的顺序把结点指针都存放到 vec 里（传引用）
    void traversalLR(TreeNode* pRoot, vector<TreeNode*>& vec)
    {
        if (pRoot == nullptr)
            vec.push_back(pRoot);
        else
        {
            vec.push_back(pRoot);
            traversalLR(pRoot->left, vec);
            traversalLR(pRoot->right, vec);
        }
    }
    // 按根右左的顺序把结点指针都存放到 vec 里（传引用）
    void traversalRL(TreeNode* pRoot, vector<TreeNode*>& vec)
    {
        if (pRoot == nullptr)
            vec.push_back(pRoot);
        else
        {
            vec.push_back(pRoot);
            traversalRL(pRoot->right, vec);
            traversalRL(pRoot->left, vec);
        }
    }
};
```

### 从上往下打印二叉树

> 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
>
> ```markdown
>          8
>      6        10
> 5    7    9    11
> 输出数组：
> {8 6 10 5 7 9 11}
> ```
> `vector<int> PrintFromTopToBottom(TreeNode* root) `


```C++
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec;
        if (root == nullptr)
            return vec;

        queue<TreeNode*> queueNode;
        queueNode.push(root);

        while (!queueNode.empty())
        {
            TreeNode* pNode = queueNode.front();
            queueNode.pop();
            vec.push_back(pNode->val);
            if (pNode->left)
                queueNode.push(pNode->left);
            if (pNode->right)
                queueNode.push(pNode->right);
        }
        return vec;
    }
};
```

#### 按层打印二叉树

> 从上往下**按层**打印出二叉树的每个节点，同层节点从左至右打印。
>
> ```markdown
>        8
>    6      10
> 5   7    9  11
> 输出二维数组：
> {{8} 
> {6 10} 
> {5 7 9 11}}
> ```
> `vector<vector<int> > Print(TreeNode* pRoot)`

```C++
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vec2d;
            if (pRoot == nullptr)
                return vec2d;
            
            vector<int> vec;
            // C++11 中 vector 可以像数组一样用花括号初始化，且等于号可以省。
            vector<TreeNode*> vecNode {pRoot}; 
            while (!vecNode.empty())
            {
                vector<TreeNode*> thisLayer(vecNode);
                for (int i = 0; i < thisLayer.size(); ++i)
                {
                    vec.push_back(thisLayer[i]->val);
                }
                vec2d.push_back(vec);
                vec.clear();
                vecNode.clear();
                for (int i = 0; i < thisLayer.size(); ++i)
                {
                    if (thisLayer[i]->left != nullptr)
                        vecNode.push_back(thisLayer[i]->left);
                    if (thisLayer[i]->right != nullptr)
                        vecNode.push_back(thisLayer[i]->right);
                }
                thisLayer.clear();
            }
            return vec2d;
        }
};
```

#### 按“之”字形打印二叉树

> 从上往下**按层**打印出二叉树的每个节点，同层节点从左至右打印，且奇数层从左到右打印，偶数层从右往左打印，设根节点所在的层为第一层（奇数层）。
>
> ```markdown
>         8
> 	6       10
>  5   7    9  11
> 输出二维数组：
> {{8} 
> {10 6} 
> {5 7 9 11}}
> ```
> `vector<vector<int> > Print(TreeNode* pRoot)`

```C++
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vec2d;
            if (pRoot == nullptr)
                return vec2d;
            int deep = 1;
            vector<int> vec;
            vector<TreeNode*> vecNode {pRoot}; 
            
            while (!vecNode.empty())
            {
                vector<TreeNode*> thisLayer(vecNode);
                if (deep % 2 == 0) 
                    reverse(thisLayer);
                for (int i = 0; i < thisLayer.size(); ++i)
                {
                    vec.push_back(thisLayer[i]->val);
                }
                vec2d.push_back(vec);
                vec.clear();
                vecNode.clear();
                if (deep % 2 == 0)  //翻转完了再翻转回来
                    reverse(thisLayer);
                
                for (int i = 0; i < thisLayer.size(); ++i)
                {
                    if (thisLayer[i]->left != nullptr)
                        vecNode.push_back(thisLayer[i]->left);
                    if (thisLayer[i]->right != nullptr)
                        vecNode.push_back(thisLayer[i]->right);
                }
                thisLayer.clear();
                deep++;
            }
            return vec2d;
        }
    
    void reverse(vector<TreeNode*>& vec)
    {
        int length = vec.size();
        for (int i = 0; i < length/2; ++i)
        {
            TreeNode* pTmp = vec[i];
            vec[i] = vec[length - 1 - i];
            vec[length - 1 - i] = pTmp;
        }
    }
};
```

### 二叉树中和为某一值的路径

> 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。         
>
> ```markdown
>            10         
>           /   \       
>         5      12   
>        /  \    
>      4     7
> ```
>
> 如找和为 22 的路径，则输出：[[10, 5, 7], [10, 12]]如找和为 15 的路径，则输出 [[]]，虽然从 10->5 是一个路径，但不是题目中描述的从根节点到叶子节点的路径
>
> `vector<vector<int> > FindPath(TreeNode* root,int expectNumber)`

```C++
class Solution {
public:
    vector<vector<int> > vec2d;
    vector<int> vec;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == nullptr) //【1】
            return vec2d;
        vec.push_back(root->val);
        // 【2】处：路径指的是从根结点到叶子结点
        if (root->val == expectNumber && root->left == nullptr && root->right == nullptr) //【2】
            vec2d.push_back(vec);
        if (root->left) //【3】
            FindPath(root->left, expectNumber - root->val);
        if (root->right) //【4】
            FindPath(root->right, expectNumber - root->val);
        // 【5】处：假设从根节点到某叶子结点的路径满足条件，那么肯定在【2】处被添加到 vec2d 里的，
        // 显然，【3】【4】处的 if 内是进不去的，此时只要 vec 不为空，就弹出最后面的元素。
        if (!vec.empty()) //【5】
            vec.pop_back();
        return vec2d;
    }
};
```

## 排序和搜索

### [数组中重复的数字](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组 {2,3,1,0,2,5,3}，那么对应的输出是重复的数字 2 或者 3。
>
> `bool duplicate(int numbers[], int length, int* duplication)`

**提示：**

*数组长度是 n，数组元素范围是 0 ~ n-1，如果数组经处理满足 array[index] = index，那就一个萝卜一个坑，没有重复的了。*

```C++
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length == 0)
            return false;
        // 检查数据是否在区间[0, length-1]内
        for (int i = 0; i < length; ++i)
        {
            if (numbers[i] < 0 || numbers[i] >= length)
                return false;
        }
        
        for (int i = 0; i < length; ++i)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;        // 有重复的数字
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;                   // 没有重复数字
    }
    
    void swap(int& x, int& y)
    {
        int t = y;
        y = x;
        x = t;
    }
};
```

### [二维数组中的查找](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
>
> `bool Find(int target, vector<vector<int> > array) `

**提示：**

*将 target 与数组右上角所在的元素比较：*   

- *相等：返回找到了*  

- *小于：该元素所在的那一列里肯定是找不到的，只会存在于该元素左边所在的矩形区域*
- *大于：该元素所在的那一行里肯定是找不到的，只会存在于该元素下方所在的矩形区域*

```C++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        const int rows = array.size();
        const int cols = array[0].size();
        int r = 0, c = cols - 1;
        
        while (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            if (array[r][c] == target)
                return true;
            else if (target > array[r][c])
                r++;
            else 
                c--;
        }
        return false;
    }
};
```

### [调整数组顺序使奇数在偶数前面](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
>
> `void reOrder(vector<int> &arr)`
>
> 【假设保证奇数和奇数，偶数和偶数之间的相对位置不变，又如何做？】 

```C++
// 此方式类似如快排过程的 partition，不保证相对位置不变，但时间复杂度为 O(n)
class Solution {
public:
	void reOrder(vector<int> &arr) {
		if (arr.empty())
			return;
		vector<int>::iterator p1 = arr.begin(), p2 = arr.end() - 1;
		while (p1 < p2)
		{
			while (isOdd(*p1) && p1 < p2)
				p1++;
			while (!isOdd(*p2) && p1 < p2)
				p2--;
			if (p1 < p2)
			{
				int tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
			}
		}
	}
	bool isOdd(int n)
	{
		return n & 1;
	}
};
```

如果想保证奇数和奇数，偶数和偶数之间的相对位置不变，可以使用稳定性排序比如冒泡排序，只是需要改变比较大小的条件。

## 动态规划

### [青蛙跳台阶](https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
>
>`int jumpFloor(int number)`

**提示：**

*设 n 级台阶有 f(n) 中跳法，青蛙最后一次跳，有两种跳法：*   

*若最后一次跳只跳一个台阶则前面的 n-1 级有 f(n-1) 种方法，若最后一次跳只跳两个台阶则前面的 n-2 级有 f(n-2) 种方法*


```C++
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)
            return 0;
        else if (number == 1 || number == 2)
            return number;
        int fn_1 = 2, fn_2 = 1; // f(n-1) 与 f(n-2)
        int fn;
        for (int i = 3; i <= number; ++i)
        {
            fn = fn_1 + fn_2;  // f(n) = f(n-1) + f(n-2)
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};
```

#### [变态跳台阶](https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
>
> `int jumpFloorII(int number) `

**提示：**
*设 n 级台阶有 f(n) 中跳法，青蛙最后一次跳，有 n 种跳法：*
*若最后一次跳只跳 1 个台阶则前面的 n-1 级有 f(n-1) 种方法*
*若最后一次跳只跳 2 个台阶则前面的 n-1 级有 f(n-2) 种方法*
 *...*
*若最后一次跳只跳 n-1 个台阶则前面的 1 级有 f(1) 种方法*
*若最后一次跳只跳 n 个台阶只有 1 种方法，（一步直接跳上来)*
*所以 f(n) = f(n-1) + f(n-2) + ... + f(1) + 1   (1)*
*把 n - 1 代入上式 n 中得：*
*f(n-1) = f(n-2) + f(n-3) + ... + f(1) + 1   (2)*
*(1) - (2) 可得 f(n) = 2f(n-1)*

```C++
class Solution {
    
public:
    int jumpFloorII(int number) {
        if (number <= 0)
            return 0;
        else if (number == 1)
            return number;
        int fn = 1;
        for (int i = 2; i <= number; ++i)
            fn *= 2;
        return fn;
    }
};
```

### [剪绳子](https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&tqId=33257&tPage=4&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。 
>
> `int cutRope(int number)`

**提示：**

*dp[n] = max(dp[n], dp[n] - dp[j])*

```C++
class Solution {
public:
    int cutRope(int number) {
        int *dp = new int[number + 1];
        dp[0] = 0, dp[1] = dp[2] = 1, dp[3] = 2;  // 绳子必须得剪一次
        if (number < 4) return dp[number];
        for (int i = 0; i < 4; ++i)
            dp[i] = i;
        int max = 0;
        for (int i = 4; i <= number; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = dp[j] * dp[i - j];
                dp[i] = dp[i] > max ? dp[i] : max;
            }
        }
        return dp[number];
    }
};
```

## 图与回溯

## 巧妙

### 位运算交换两个数

```C++
void swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
```

### [二进制中 1 的个数](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

**提示：**

*一种方法是将数字 n 右移，与 1 与，但这样可能会引起死循环，因为当 n 为负数的时候，n 的最高位补码为 1，这样一直右移，最终这个数字就会变成 0xFFFFFFFF，而陷入死循环。为了避免死循环，设置 flag = 1，将 flag 左移，在 32 位机器上 flag 移动 32 次就会变成 0，跳出 while 循环。*

```C++
int numberOf1(int n)
{
    unsigned int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;
        flag = flag << 1;
    }
    return count;
}
```

### [数值的整数次方](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 求 base 的 exponent 次方

**提示：**

*比如求 3的 31次方 result，如果知道 3 的 15 次方为 a，那么可知 3 的 30次方为 = a \* a ，由于 31 为奇数所以再在 3 的 30 次方基础上再乘以 3，时间复杂度 O(logn)。*

```C++
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;
        double result = Power(base, exponent >> 1);
        result *= result;
        if (exponent & 1)  // 奇数与 1 位与为 true
            result *= base;
        return result;
    }
};
```



## 其他

### [用两个栈实现队列](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

```C++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                int data = stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
        // 将 stack1 里的数据放入栈 stack2 后，stack2还是空的，
        // 说明 stack1 本身就是空的，此时就不能出队了,应该报错
        if(stack2.empty())    
            cout << "queue is empty" << endl;
        int data = stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1;        // 队尾，进队
    stack<int> stack2;        // 队头，出队
};
```

### [最小栈](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

>  定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。 
>
> 需要实现方法 push, pop, top, min.

```C++
class Solution {
    stack<int> stk;
    stack<int> minstk;
public:
    void push(int value) {
        if (minstk.empty() || value <= minstk.top())
            minstk.push(value);
        stk.push(value);
    }
    void pop() {
        if (minstk.top() == stk.top())
        {
            minstk.pop();
            stk.pop();
        }
        else
            stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minstk.top();
    }
};
```

### [栈的压入、弹出序列](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

> 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

**提示：**

*新建一个临时栈，模拟按 pushV 入栈，按 popV 出栈*

```C++
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size())
            return false;
        int length = pushV.size(); 
        int idPush = 0, idPop = 0;
        stack<int> stk;
        while (idPush < length && idPop < length)
        {
            if (stk.empty())
                stk.push(pushV[idPush++]);
            else if(stk.top() != popV[idPop])
                stk.push(pushV[idPush++]);
            
            while (!stk.empty() && stk.top() == popV[idPop])
            {
                stk.pop();
                idPop++;
            }
        }
        // 退出循环有两种情况：
        // 一、idPush 等于 idPop 等于 length，此时 stk 为空，说明 popV 是弹出序列
        // 二、idPush 等于 length，已经压入了最后一个元素，但 stk.top() 还是不等于 popV[idPop]
        if (stk.empty())
            return true;
        else
            return false;
    }
};
```



### [正则表达式匹配](https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&tPage=3&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)

> 请实现一个函数用来匹配包括'.'和'\*'的正则表达式。模式中的字符'.'表示任意一个字符，而'\*'表示它前面的字符可以出现任意次（包含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab\*ac\*a"匹配，但是与"aa.a"和"ab\*a"均不匹配

```C++
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;
        else if (*str != '\0' && *pattern == '\0')
            return false;
        else if (*str == '\0' && *pattern == '\0')
            return true;
        // 当 pattern 不是指向 "\0" 的时候
        if (*(pattern + 1) == '*')    // pattern 第二个字符为 '*'，情况考虑复杂
        {
            if (*str == *pattern || (*pattern == '.' && *str != '\0'))
                return match(str + 1, pattern + 2)     // aab 和 a*a*b
                        || match(str + 1, pattern)     // aab 和 a*b
                        || match(str, pattern + 2);    // aab 和 a*a*a*a*a*b
            else // *str 与 *pattern 不匹配，如 bac 和 a*bac
                return match(str, pattern + 2);
        }
        else if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return match(str + 1, pattern + 1);
        else
            return false;
    }
};
```

