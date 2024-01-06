#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


bool isVowel(char s)
{
	s = tolower(s);

	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
		return true;

	return false;
}

char* serpentino_encode(const char* s)
{
	if (s == NULL)
		return NULL;

	size_t dim = strlen(s);

	size_t j = 0;

	char* ris = malloc((dim*3+1)*sizeof(char));

	for (size_t i = 0; i < dim; i++)
	{
		if (isVowel(s[i]) == true)
		{
			ris[j] = s[i];
			ris[j + 1] = 's';
			ris[j + 2] = s[i];
			j += 3;
		}
		else
		{
			ris[j] = s[i];
			j++;
		}
	}

	return realloc(ris, strlen(ris)+1);
}