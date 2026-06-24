// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p;

	if (size == 0)
		return NULL;

	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (p == MAP_FAILED)
		return NULL;

	if (mem_list_add(p, size) < 0) {
		munmap(p, size);
		return NULL;
	}

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p;
	size_t total_size;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return NULL;

	total_size = nmemb * size;
	p = malloc(total_size);

	if (p != NULL)
		memset(p, 0, total_size);

	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *iter;
	size_t length;

	if (ptr == NULL)
		return;

	iter = mem_list_find(ptr);

	if (iter == NULL)
		return;

	length = iter->len;
	mem_list_del(ptr);
	munmap(ptr, length);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *new_ptr;
	struct mem_list *iter;
	size_t old_size;

	if (ptr == NULL)
		return malloc(size);

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	iter = mem_list_find(ptr);
	if (iter == NULL)
		return NULL;

	old_size = iter->len;
	if (size <= old_size)
		return ptr;

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return NULL;

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return NULL;

	total_size = nmemb * size;
	return realloc(ptr, total_size);
}
