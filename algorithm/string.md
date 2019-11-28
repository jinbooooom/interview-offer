### 交换两个字符串

```
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