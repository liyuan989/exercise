#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
	int (*func)(int, int);
	void* handle = dlopen("./lib.so", RTLD_LAZY);
	if (!handle)
	{
		printf("open so failed\n");
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	void* p = dlsym(handle, "func");
	if (!p)
	{
		printf("don't have symbol\n");
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	func = (int (*) (int, int))p;
	int a = func(2,3);
	printf("%d\n", a);
	if (dlclose(handle) < 0)
	{
		printf("close error\n");
		exit(1);
	}
	return 0;
}
