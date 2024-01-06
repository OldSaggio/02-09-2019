#include "matrix.h"

size_t maxTwoNumbers(size_t a, size_t b)
{
	if (a > b)
		return a;

	return b;
}

struct matrix* mat_rendiquadrata(const struct matrix* a)
{

	const size_t MAX = maxTwoNumbers(a->cols, a->rows);
	
	double* data = calloc(MAX * MAX *sizeof(double), 1);

	for (size_t r = 0; r < MAX; r++)
		for (size_t c = 0; c < MAX; c++)
			data[r * MAX + c] = a->data[r * a->cols + c];

	struct matrix* ris = malloc(sizeof(struct matrix));

	ris->rows = MAX;
	ris->cols = MAX;

	ris->data = data;

	return ris;

}