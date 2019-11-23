## STL

STL 主要由两部分组成：一是容器，二是操作容器的泛型算法。

容器一是包括 vector, list这两种顺序性容器，在顺序性容器身上主要进行迭代操作；二是包括 map 和 set 这两种关联容器，关联容器可以让我们快速查找容器的元素值。

### 所有容器的共同操作(包括string 类)

- == 和 != 返回 true 或者 false，两个容器是否相等

- = 赋值，将一个容易赋给另一个容器
- empty()
- size()
- clear() 删除所有元素
- begin() 
- end()
- insert() 将单一或者某一个范围的元素插入容器内
- erase() 将容器内的单一或者某一个范围内的元素删除

【ESC 76】

### 使用顺序性容器

顺序性容器就是维护一组排列有序，类型相同的元素。vector 和 list 是两个最主要的顺序性容器。

- vector 以一块连续性内存来存放数据，适合随机访问，不适合插入/删除（如果在末尾插入/删除效率一样，在中间插入/删除就需要移动元素）
- list 以双向链接而非连续内存来存储内容，适合插入删除而不适合随机访问。
- deque 以连续内存存储数据，但是只能对最前端/末端的元素进行插入/删除操作

#### vector

- vector<int> vec;  产生空的容器
- vector<int> vec(1024): 创建一个vector,元素个数为1024，对int 和double这种算术类型，不给初值，默认就是 0.
- vector<int> vec(1024, 42):创建一个vector，元素个数为1024,且值均为42
- vector<int> vec(begin,end):复制[begin,end)区间内另一个数组的元素到vector中，begin和end为指针或者迭代器
- vec.push_back()
- vec.pop_back()

```C++
vector<vector<char> >vec(row,vector<char>(col,'#'));//二维数组初始化
```

[C++ vector的用法（整理）](https://blog.csdn.net/wkq0825/article/details/82255984)

[vector容器详细方法·菜鸟教程](https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html)

#### Map

```C++
#include<iostream>
#include <map>
#include <string>
map<string, int> words;

words["good"] = 1;  //键 good 的值是 1
//如果一个key不在words钟，其默认值就为0
words["bad"];  // 0
//比如你想知道 words 中是否有 "python",第一种方法可以直接把 key当索引使用，
//但缺点是，若本无这个键，这样做就会添加这个键，虽然默认值为 0
if (words["python"]) {
    do something;  //如果 words 中有 "python"
}
//第二种做法是用map自带的find()函数。
map<string, int>::iterator it;
it = words.find("Python");
if (it != words.end() {
    do something;
    std::cout << it->second;
    //it->first 是 key，it->second 是 value
}
//第三种做法是利用map的count()函数
if (words.count("python")) {
    do something;
}
```

#### Set

Set 由一群 key 组合而成，对于任何 key 值，set 只能存一份。

C++ 中，set 元素默认按照 less-than 顺序排列，这点跟 python 不一样，python里的 set 是无序的。
```C++
int ia[] = {3, 8, 8, 5, 3, 1, 5, 1};
vector<int> vec(ia, ia+8);
set<int> iset(vec.begin(), vec.end());
set<int>::iterator it = iset.begin();
for (; it != iset.end(); ++it)
    cout << *it << ' ';
//输出 1 3 5 8
```

- insert()
- set_intersection()
- set_union()
- set_difference()
- set_symmetric_difference()

### 算法

#### sort

```C++
#include <algorithm>
/* 函数sort(first, last, comp)；
first : 待排序数组起始地址；
last : 待排序数组结束地址；
comp : 排序方式，该参数是可省参数，如果省略则以升序方式排序；
*/
int vec[] = { 5, 1, 9, 4, 6, 7, 2, 0, 1 };
sort(vec, vec + 9); //就地改变，未使用 comp，默认按升序排列 
```

```C++
 bool comp(int a, int b) {
     return a > b;  //自己写排序规则，大的放在前面
 }
int vec[] = { 5, 1, 9, 4, 6, 7, 2, 0, 1 };
sort(vec, vec + 9, comp); //使用 comp，按自己的规则降序排列
```

#### STL方法

- 更多【ESC 78-92】
- [C/C++STL常用容器用法总结常用容器](https://blog.csdn.net/weixin_41162823/article/details/79759081)
- [STL·语雀](https://www.yuque.com/huihut/interview/stl_document)
- [C++/boost数据结构](https://zhuanlan.zhihu.com/p/73000084)

