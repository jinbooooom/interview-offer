#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int myStrlen(const char *str)
{
	assert(str != nullptr);			// 需要头文件 #include <assert.h>
	//if (str == nullptr) return 0;
	const char *p = str;
	while (*str++ != '\0');
	return str - p - 1;
}


int main(int argc, char* argv[]) {

	char str[100] = "-123456789";
	char dst[10] = "abcdef";
	char *tmp = nullptr;
	cout << myStrlen(str) << ' ' << myStrlen(dst) << ' ' << myStrlen(tmp) << endl;
	system("pause");
}

