#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

void* mm_malloc(size_t size);

void mm_free(void* bp);

int mm_init();

void mm_close();

#endif
