#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: pointer to the main string to search within
 * @needle: pointer to the substring to find
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h_track;
	char *n_track;

	/* Edge case: an empty needle matches the start of haystack instantly */
	if (*needle == '\0')
	{
		return (haystack);
	}

	/* Stream through the primary haystack string byte-by-byte */
	while (*haystack != '\0')
	{
		/* Set up temporary tracking fingers for the trial run alignment */
		h_track = haystack;
		n_track = needle;

		/* Step forward as long as the sub-elements match perfectly */
		while (*h_track == *n_track && *n_track != '\0')
		{
			h_track++;
			n_track++;
		}

		/* If the tracking finger successfully hit the end of the needle */
		if (*n_track == '\0')
		{
			return (haystack);
		}

		haystack++; /* Advance the search frame by 1 byte */
	}

	/* Return NULL if the substring phrase was not found in the stream */
	return (NULL);
}
