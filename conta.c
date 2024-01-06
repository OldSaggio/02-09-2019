#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


size_t contanumeri(const char* nomefile)
{
	size_t n = 0;

	if (nomefile != NULL)
	{
		FILE* f = fopen(nomefile, "r");
		if (f == NULL)
		{
			fclose(f);
			return 0;
		}

		char tmp;

		while (true)
		{
			if (fread(&tmp, 1, 1, f) == 1)
			{
				if (isdigit(tmp) == true)
					n++;
			}
			else
				break;
		}

		fclose(f);
	}
}