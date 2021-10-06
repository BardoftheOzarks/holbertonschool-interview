#include "menger.h"

/**
 * menger - prints a 2D Menger Sponge
 * @level: sponge size
 */
void menger(int level)
{
	int size = pow(3, level), row, col, denom;
	bool print;

	if (level == 0)
		puts("#");
	if (level > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (col = 0; col < size; col++)
			{
				print = true;
				for (denom = size; denom; denom /= 3)
					if (((row / denom) % 3) == 1 &&
					    ((col / denom) % 3) == 1)
						print = false;
				if (print == true)
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
