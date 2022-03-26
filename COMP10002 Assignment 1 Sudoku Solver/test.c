#include <stdio.h>

#define NDIM 3		/* sudoku dimension, size of each inner square */
#define NDIG (NDIM*NDIM)
					/* total number of values in each row | 3 x 3 = 9 */
#define NGRP 3		/* number of sets each cell is a member of */
#define NSET (NGRP*NDIG)
					/* total number of sets in the sudoku | 3 x 9 = 27 */
#define NCLL (NDIG*NDIG)
					/* total number of cells in the sudoku | 9 x 9 = 81 */

#define ERROR (-1)	/* error return value from some functions */

#define UNKN_CLL '.'	
#define VERT_BAR '|'
#define ROW_DVD	 '-'
#define ROW_SPRT "------+-------+------"

int s2c[NSET][NDIM*NDIM] = {
	/* the first group of nine sets describe the sudoku's rows */
	{  0,  1,  2,  3,  4,  5,  6,  7,  8 }, // set[0]	rowStart
	{  9, 10, 11, 12, 13, 14, 15, 16, 17 },
	{ 18, 19, 20, 21, 22, 23, 24, 25, 26 },
	{ 27, 28, 29, 30, 31, 32, 33, 34, 35 },
	{ 36, 37, 38, 39, 40, 41, 42, 43, 44 },
	{ 45, 46, 47, 48, 49, 50, 51, 52, 53 },
	{ 54, 55, 56, 57, 58, 59, 60, 61, 62 },
	{ 63, 64, 65, 66, 67, 68, 69, 70, 71 },
	{ 72, 73, 74, 75, 76, 77, 78, 79, 80 },	// set[8]	rowEnd
	/* the second group of nine sets describes the sudoku's columns */
	{  0,  9, 18, 27, 36, 45, 54, 63, 72 }, // set[9] 	colStart
	{  1, 10, 19, 28, 37, 46, 55, 64, 73 },
	{  2, 11, 20, 29, 38, 47, 56, 65, 74 },
	{  3, 12, 21, 30, 39, 48, 57, 66, 75 },
	{  4, 13, 22, 31, 40, 49, 58, 67, 76 },
	{  5, 14, 23, 32, 41, 50, 59, 68, 77 },
	{  6, 15, 24, 33, 42, 51, 60, 69, 78 },
	{  7, 16, 25, 34, 43, 52, 61, 70, 79 },
	{  8, 17, 26, 35, 44, 53, 62, 71, 80 },	// set[17]	colEnd
	/* the last group of nine sets describes the inner squares */
	{  0,  1,  2,  9, 10, 11, 18, 19, 20 },	// set[18]	sqrStart
	{  3,  4,  5, 12, 13, 14, 21, 22, 23 },
	{  6,  7,  8, 15, 16, 17, 24, 25, 26 },
	{ 27, 28, 29, 36, 37, 38, 45, 46, 47 },
	{ 30, 31, 32, 39, 40, 41, 48, 49, 50 },
	{ 33, 34, 35, 42, 43, 44, 51, 52, 53 },
	{ 54, 55, 56, 63, 64, 65, 72, 73, 74 },
	{ 57, 58, 59, 66, 67, 68, 75, 76, 77 },
	{ 60, 61, 62, 69, 70, 71, 78, 79, 80 }, // set[26]	sqrEnd
};

void
readSudoku(int A[]) {
	int i;
	/* read and store 81 integers from data txt */
	for (i=0; i<NCLL; i++) 
	{
		scanf("%d", &A[i]);
	}
}

void
generateGrid(int A[]) {
	int	i, unknownCount=0;

	for (i=0; i<NCLL; i++) {
		//int k=1;
	    if (i % NDIG == 0) 
		{
	        printf("\n");
	    }

	    if (((i % NDIM == 0) || ((i % (2*NDIM) == 0))) && (i % (3*NDIM) != 0)) 
		{
	        printf("%-2c", VERT_BAR);
	    }
		
	    if ((i % NSET == 0) && (i % NCLL != 0)) 
		{
	        printf(ROW_SPRT);
	    	printf("\n");
		}

	    if (A[i] == 0) {
			if (i % NDIG == (NDIG-1)) {
				printf("%c", UNKN_CLL);
			} else {
				printf("%-2c", UNKN_CLL);
			}
			unknownCount++;
		} 

		else if (i % NDIG == (NDIG-1)) {
			printf("%d", A[i]);
		} else {
			printf("%-2d", A[i]);
		}
	}
	printf("\n");
	printf("\n%d cells are unknown\n\n", unknownCount);
}


int main() {
    int val[NCLL];
	readSudoku(val);
    generateGrid(val);
    int i, j;
    int arr_row;

    for (i=0; i<NDIG; i++) 
	{
		for (j=0; j<NDIG; j++) 
		{
			arr_row = val[s2c[i][j]];
			if (j % 9 == 0) {
				printf("\n");
			}

			printf("%d ", arr_row); 
		}
			if (i % 9 == 0 && i != 0) {
			printf("\n");
		}
    }
}