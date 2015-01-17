#include "MutexLock.h"
#include <stdio.h>

using namespace blink;

int main(int argc, char const *argv[])
{
	MutexLock mutex;
	MutexLockGuard mutex_guard(mutex);
    mutex.trylock();
	if (mutex.isLocked())
	{
		printf("islocked\n");
	}
	else
	{
		printf("non-locked\n");
	}

	if (mutex.isLockedByCurrentThread())
	{
		printf("locked by current thread\n");
	}
	else
	{
		printf("non-locked by current thread\n");
	}
	mutex.getMutex();
	return 0;
}
