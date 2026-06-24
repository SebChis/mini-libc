// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *start = destination;

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';
	destination = start;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *start = destination;

	size_t i = 0;
	for (i = 0; i < len && *source != '\0'; i++) {
		*destination = *source;
		destination++;
		source++;
	}

	while (i < len) {
		*destination = '\0';
		destination++;
		i++;
	}

	destination = start;

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *start = destination;

	while (*destination != '\0')
		destination++;

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';
	destination = start;

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *start = destination;

	while (*destination != '\0')
		destination++;

	while (*source != '\0' && len > 0) {
		*destination = *source;
		destination++;
		source++;
		len--;
	}

	*destination = '\0';
	destination = start;

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		str1++;
		str2++;
	}

	if (*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (*str1 != '\0' && *str2 != '\0' && len > 0) {
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		str1++;
		str2++;
		len--;
	}

	if (len == 0)
		return 0;

	if (*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char character = (char)c;

	while (*str != '\0') {
		if (*str == character)
			return (char *)str;
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char character = (char)c;
	char *last = NULL;

	while (*str != '\0') {
		if (*str == character)
			last = (char *)str;
		str++;
	}

	return last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0')
		return (char *)haystack;

	while (*haystack != '\0') {
		char *copy_haystack = (char *)haystack;
		const char *copy_needle = needle;

		while (*copy_needle != '\0' && *copy_needle == *copy_haystack) {
			copy_needle++;
			copy_haystack++;
		}

		if (*copy_needle == '\0')
			return (char *)haystack;

		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (*needle == '\0')
		return (char *)haystack;

	char *last = NULL;

	while (*haystack != '\0') {
		char *copy_haystack = (char *)haystack;
		const char *copy_needle = needle;

		while (*copy_needle != '\0' && *copy_needle == *copy_haystack) {
			copy_needle++;
			copy_haystack++;
		}

		if (*copy_needle == '\0')
			last = (char *)haystack;

		haystack++;
	}

	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *copy_destination = (char *)destination;
	const char *copy_source = (const char *)source;

	while (num > 0) {
		*copy_destination = *copy_source;
		copy_destination++;
		copy_source++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *copy_destination = (char *)destination;
	const char *copy_source = (const char *)source;

	if (copy_destination < copy_source) {
		while (num > 0) {
			*copy_destination = *copy_source;
			copy_destination++;
			copy_source++;
			num--;
		}
	} else if (copy_destination > copy_source) {
		copy_destination += num;
		copy_source += num;

		while (num > 0) {
			copy_destination--;
			copy_source--;
			*copy_destination = *copy_source;
			num--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *copy_ptr1 = (char *)ptr1;
	char *copy_ptr2 = (char *)ptr2;

	while (num > 0) {
		if (*copy_ptr1 != *copy_ptr2)
			return *copy_ptr1 - *copy_ptr2;

		copy_ptr1++;
		copy_ptr2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *copy_source = (char *)source;

	while (num > 0) {
		*copy_source = (char)value;
		copy_source++;
		num--;
	}

	return source;
}
