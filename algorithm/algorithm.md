

## 数据结构

### 栈

### 队列

**队空与队满**

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

####二叉树
二叉树（Binary Tree）是另一种树形结构，它的特点是每个结点至多只有两颗子树（即二叉树中不存在度大于二的节点）。
并且，二叉树的子树有左右之分，其次序不能任意颠倒。

[二叉树的分类](https://www.cnblogs.com/sunshineliulu/p/7775063.html)

- 二叉搜索树
- 平衡二叉树（AVL）

[轻松搞定面试中的二叉树题目](https://blog.csdn.net/luckyxiaoqiang/article/details/7518888)

### 红黑树

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



## 基础操作

### 位运算交换两个数

```C++
void swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
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

### 反向打印链表

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

### 删除链表中重复的节点

> 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5 
>
>`ListNode* deleteDuplication(ListNode* pHead)`

```C++
// 递归方法本地调试通过，牛客网栈溢出
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
        while(pHead->val == pNext->val && pNext != nullptr)
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

### 链表中倒数第 k 个节点

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

### 链表中环的结点

>  给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。 
>
> `ListNode* EntryNodeOfLoop(ListNode* pHead)`

**提示：**

*假设有环，且知道环中节点的个数设为 n，那么设置两个指针 p1, p2 分别指向头节点，现在使 p2 先移动 n 步，p1 不动，再使 p1, p2 同时移动，那么当 p1, p2 相遇时，p1 指针指向的节点就是入口节点。*

***如何求环中节点个数 n?***

*设置两个指针，一快一慢，最开始都指向头节点。快指针 pFast 每次移动 2 步，慢指针 pSlow 每次移动 1 步，若 pFast 能到达尾节点，则说明无环；若 pFast 能相遇，说明有环，当相遇时，慢指针 pSlow 保持位置不变，快指针改为每次移动 1 步，直到再次与慢指针相遇，移动了多少步，环中就含有多少个节点。*


```C++
// 牛客网通过率0%，复杂度过高？
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
                pSlow = pFast->next;
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

### 反转链表

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

### 合并两个有序的链表

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



## 其他

### 用两个栈实现队列

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

