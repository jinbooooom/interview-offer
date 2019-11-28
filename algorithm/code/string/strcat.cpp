#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

char *myStrcat(char *dst, char *src)
{
	assert(src != nullptr && dst != nullptr);
	assert(dst != src);

	char *dstCopy = dst;
	while (*dst)
		dst++;
	while (*dst++ = *src++);
	return dstCopy;
}


int main(int argc, char* argv[]) {

	char str[50] = "abc";
	char dst[100] = "123";
	char *tmp = nullptr;
	cout << myStrcat(dst, str) << endl;
	system("pause");
}

