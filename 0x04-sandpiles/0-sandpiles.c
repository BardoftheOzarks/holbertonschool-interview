#include "sandpiles.h"

/**
 * sandpiles_sum - adds two 3 x 3 matrices and sandpiles the result
 * @grid1: first matrix
 * @grid2: second matrix
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i, j, limit_passed;

limit_passed = 0;
for (i = 0; i < 3; i++)
for (j = 0; j < 3; j++)
{
grid1[i][j] = grid1[i][j] + grid2[i][j];
grid2[i][j] = 0;
if (grid1[i][j] > 3)
limit_passed++;
}
if (limit_passed > 0)
sandpile(grid1, grid2);
}

/**
 * sandpile - disperse each cell of a matrix until equals maximum of 3
 * @grid1: matrix to be sandpiled
 * @grid2: grid to be overwritten
 */
void sandpile(int grid1[3][3], int grid2[3][3])
{
int i, j;

print_pile(grid1);
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid1[i][j] > 3)
{
grid1[i][j] -= 4;
if (i > 0)
grid2[i - 1][j] += 1;
if (i < 2)
grid2[i + 1][j] += 1;
if (j > 0)
grid2[i][j - 1] += 1;
if (j < 2)
grid2[i][j + 1] += 1;
}
}
}
sandpiles_sum(grid1, grid2);
}

/**
 * print_pile - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_pile(int grid[3][3])
{
int i, j;

printf("=\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
}
printf("\n");
}
}