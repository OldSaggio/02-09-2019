#include "rapporti.h"

struct rapporto* leggi_rapporti(const char* filename, uint16_t* n)
{
	if (filename == NULL)
		return NULL;

	FILE* f = fopen(filename, "rb");

	if (f != NULL)
	{
		uint16_t dim;

		if (fread(&dim, sizeof(uint16_t), 1, f) == 1)
		{
			struct rapporto* ris = malloc(dim * sizeof(struct rapporto));

			bool isCorrect = true;

			for (size_t i = 0; i < dim; i++)
			{
				if (fread(&ris[i].id, sizeof(uint16_t), 1, f) != 1)
				{
					isCorrect = false;
					break;
				}
				if (fread(&ris[i].tipo, 1, 1, f) != 1)
				{
					isCorrect = false;
					break;
				}
				if (fread(&ris[i].valore, sizeof(float), 1, f) != 1)
				{
					isCorrect = false;
					break;
				}
			}

			if (isCorrect == true)
			{
				fclose(f);
				*n = dim;
				return ris;
			}

			else
			{
				fclose(f);
				free(ris);
				return NULL;
			}

		}
		else
		{
			fclose(f);
			return NULL;
		}
	}
	else
		return NULL;
}