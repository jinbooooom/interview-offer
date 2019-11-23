### 位运算交换两个数

```C++
void swap(int &x, int &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}
```

