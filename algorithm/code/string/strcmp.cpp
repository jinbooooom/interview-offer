#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

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


int main(int argc, char* argv[]) {

	char str[100] = "12";
	char dst[10] = "123";
	char *tmp = nullptr;
	cout << myStrcmp(tmp, dst) << endl;
	system("pause");
}

