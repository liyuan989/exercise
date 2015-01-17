#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/mman.h>

#include "MemoryPool.h"

#define WSIZE               4                                               //word size
#define DSIZE               8                                               //double word size
#define CHUNKSIZE          (1 << 12)                                        //extand heap by this size
#define MAX_HEAP           (1024 * CHUNKSIZE)

#define MAX(x, y)	       ((x) > (y) ? (x) : (y))

#define PACK(size, alloc)  ((size) | (alloc))                               //pack size and allocated into a word

#define GET(p)             (*(unsigned int*)(p))
#define PUT(p, val)        (*(unsigned int*)(p) = (val))

#define GET_SIZE(p)        (GET(p) & ~0x7)                                  //get block size
#define GET_ALLOC(p)       (GET(p) & 0x1)                                   //get block allocated

#define HDRP(bp)           ((char*)(bp) - WSIZE)                            //get head poiter
#define FTRP(bp)           ((char*)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)       //get foot pointer

#define NEXT_BLKP(bp)      ((char*)(bp) + GET_SIZE(HDRP(bp)))               //get next block poiter
#define PREV_BLKP(bp)      ((char*)(bp) - GET_SIZE(((char*)(bp) - DSIZE)))  //get previous poiter

static char* mem_heap;
static char* mem_brk = NULL;
static char* mem_max_addr;
static char* heap_listp;

static void mem_init();
static void* mem_sbrk(int size);
static void* extend_heap(int length);
static void* merge(void* bp);
static void* find_fit(size_t adjust_size);
static void place(void* bp, size_t adjust_size);

void* mm_malloc(size_t size)
{
	char* bp;
	size_t adjust_size;
	if (size == 0)
	{
		return NULL;
	}
	else if (size < 0)
	{
		adjust_size = DSIZE;
	}
	else
	{
		adjust_size = (size + DSIZE + DSIZE - 1) / DSIZE * DSIZE;
	}

	if ((bp = (char*)find_fit(adjust_size)) != NULL)
	{
		place(bp, adjust_size);
		return bp;
	}

	size_t extand_size = MAX(adjust_size, CHUNKSIZE);
	if ((bp = (char*)extend_heap(extand_size / WSIZE)) == NULL)
	{
		return NULL;
	}

	place(bp, adjust_size);
	return bp;
}

void mm_free(void* bp)
{
	size_t size = GET_SIZE(HDRP(bp));
	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size, 0));
	merge(bp);
}

static void mem_init()
{
	mem_heap = (char*)mmap(NULL, MAX_HEAP, PROT_EXEC | PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANON, 0, 0);
	if (mem_heap == (char*)-1)
	{
		fprintf(stderr, "mmap error: %s\n", strerror(errno));
		exit(0);
	}
	mem_brk = mem_heap;
	mem_max_addr = mem_heap + MAX_HEAP;
}

static void* mem_sbrk(int size)
{
	char* orld_brk = mem_brk;
	if (size < 0 || (mem_brk + size > mem_max_addr))
	{
		fprintf(stderr, "error: mem_sbrk failed: ran out of memory range\n");
		return (void*)-1;
	}
	mem_brk += size;
	return (void*)orld_brk;
}

int mm_init()
{
	if (mem_brk == NULL)
	{
		mem_init();
	}
	if ((heap_listp = (char*)mem_sbrk(4 * WSIZE)) == (char*)-1)
	{
		return -1;
	}

	PUT(heap_listp, 0);
	PUT(heap_listp + 1 * WSIZE, PACK(DSIZE, 1));
	PUT(heap_listp + 2 * WSIZE, PACK(DSIZE, 1));
	PUT(heap_listp + 3 * WSIZE, PACK(0, 1));
	heap_listp += 2 * WSIZE;

	if (extend_heap(CHUNKSIZE / WSIZE) == NULL)
	{
		return -1;
	}
	return 0;
}

void mm_close()
{
	if (munmap(mem_heap, MAX_HEAP) == -1)
	{
		fprintf(stderr, "%s :%s", "munmap error", strerror(errno));
		exit(0);
	}
}

static void* extend_heap(int length)
{
	char* bp;
	int size = (length % 2) ? (length + 1) * WSIZE : length * WSIZE;

	if ((bp = (char*)mem_sbrk(size)) == (char*)-1)
	{
		return NULL;
	}

	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size, 0));
	PUT(FTRP(NEXT_BLKP(bp)), PACK(0, 1));
	return merge((void*)bp);
}

static void* merge(void* bp)
{
	int prev_alloc = GET_ALLOC(HDRP(PREV_BLKP(bp)));
	int next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
	int size = GET_SIZE(HDRP(bp));

	if (prev_alloc && next_alloc)
	{
		return bp;
	}
	else if (prev_alloc && !next_alloc)
	{
		size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
		PUT(HDRP(bp), PACK(size, 0));
		PUT(FTRP(bp), PACK(size, 0));
	}
	else if (!prev_alloc && next_alloc)
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		PUT(FTRP(bp), PACK(size, 0));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	else
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(HDRP(NEXT_BLKP(bp)));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
		bp = PREV_BLKP(bp);
	}
	return bp;
}

static void* find_fit(size_t adjust_size)
{
	for (void* bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp))
	{
		if (!GET_ALLOC(HDRP(bp)) && (adjust_size <= GET_SIZE(HDRP(bp))))
		{
			return bp;
		}
	}
	return NULL;
}

static void place(void* bp, size_t adjust_size)
{
	size_t size = GET_SIZE(HDRP(bp));
	size_t left_size = size - adjust_size;

	if (left_size >= DSIZE)
	{
		PUT(HDRP(bp), PACK(adjust_size, 1));
		PUT(FTRP(bp), PACK(adjust_size, 1));
		PUT(HDRP(NEXT_BLKP(bp)), PACK(left_size, 0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(left_size, 0));
	}
	else
	{
		PUT(HDRP(bp), PACK(size, 1));
		PUT(FTRP(bp), PACK(size, 1));
	}
}
