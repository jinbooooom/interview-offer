#include <iostream>
#include <stdlib.h>
using namespace std;

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

int main(int argc, char* argv[]) {
	int n = 0;
	char str[10] = "-123";
	cout << n << endl;
	n = str2int(str);
	cout << n << endl;
	system("pause");
}

