/* Program to assist in the challenge of solving sudoku puzzles.

   Skeleton program written by Alistair Moffat, ammoffat@unimelb.edu.au,
   August 2021, with the intention that it be modified by students
   to add functionality, as required by the assignment specification.

   Student Authorship Declaration:

   (1) I certify that except for the code provided in the initial skeleton
   file, the  program contained in this submission is completely my own
   individual work, except where explicitly noted by further comments that
   provide details otherwise.  I understand that work that has been developed
   by another student, or by me in collaboration with other students, or by
   non-students as a result of request, solicitation, or payment, may not be
   submitted for assessment in this subject.  I understand that submitting for
   assessment work developed by or in collaboration with other students or
   non-students constitutes Academic Misconduct, and may be penalized by mark
   deductions, or by other penalties determined via the University of
   Melbourne Academic Honesty Policy, as described at
   https://academicintegrity.unimelb.edu.au.

   (2) I also certify that I have not provided a copy of this work in either
   softcopy or hardcopy or any other form to any other student, and nor will I
   do so until after the marks are released. I understand that providing my
   work to other students, regardless of my intention or any undertakings made
   to me by that other student, is also Academic Misconduct.

   (3) I further understand that providing a copy of the assignment
   specification to any form of code authoring or assignment tutoring service,
   or drawing the attention of others to such services and code that may have
   been made available via such a service, may be regarded as Student General
   Misconduct (interfering with the teaching activities of the University
   and/or inciting others to commit Academic Misconduct).  I understand that
   an allegation of Student General Misconduct may arise regardless of whether
   or not I personally make use of such solutions or sought benefit from such
   actions.

   Signed by: [Thanakon Kimsan 1208848]
   Dated:     [03 September 2021]

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* these #defines provided as part of the initial skeleton */

#define NDIM 3		/* sudoku dimension, size of each inner square */
#define NDIG (NDIM*NDIM)
					/* total number of values in each row | 3 x 3 = 9 */
#define NGRP 3		/* number of sets each cell is a member of */
#define NSET (NGRP*NDIG)
					/* total number of sets in the sudoku | 3 x 9 = 27 */
#define NCLL (NDIG*NDIG)
					/* total number of cells in the sudoku | 9 x 9 = 81 */

#define ERROR (-1)	/* error return value from some functions */


/* these global constant arrays provided as part of the initial skeleton,
   you may use them in your code but must not alter them in any way,
   regard them as being completely fixed. They describe the relationships
   between the cells in the sudoku and provide a basis for all of the
   sudoku processing loops */

/* there are 27 different different sets of elements that need to be
   checked against each other, this array converts set numbers to cells,
   that's why its called s2c */
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



/* there are 81 cells in a dimension-3 sudoku, and each cell is a
   member of three sets, this array gets filled by the function 
   fill_c2s(), based on the defined contents of the array s2c[][] */
int c2s[NCLL][NGRP];

void
fill_c2s() {
	int s=0, d=0, c;
	for ( ; s<NSET; s++) {
		/* record the first set number each cell is part of */
		for (c=0; c<NDIM*NDIM; c++) {
			c2s[s2c[s][c]][d] = s;
		}
		if ((s+1)%(NGRP*NDIM) == 0) {
			d++;
		}
	}
#if 0
	/* this code available here if you want to see the array
	   cs2[][] that gets created, just change that 0 two lines back
	   to a 1 and recompile */
	for (c=0; c<NCLL; c++) {
		printf("cell %2d: sets ", c);
		for (s=0; s<NGRP; s++) {
			printf("%3d", c2s[c][s]);
		}
		printf("\n");
	}
	printf("\n");
#endif
	return;
}

/* find the row number a cell is in, counting from 1 */
int
rownum(int c) {
	return 1 + (c/(NDIM*NDIM));
}

/* find the column number a cell is in, counting from 1 */
int
colnum(int c) {
	return 1 + (c%(NDIM*NDIM));
}

/* find the minor square number a cell is in, counting from 1 */
int
sqrnum(int c) {
	return 1 + 3*(c/NSET) + (c/NDIM)%NDIM;
}

/* If you wish to add further #defines, put them below this comment,
   then prototypes for the functions that you add

   The only thing you should alter above this line is to complete the
   Authorship Declaration 
*/


/****************************************************************/
#define UNKN_CLL '.'	
#define VERT_BAR '|'
#define ROW_SPRT "------+-------+------"
#define S1_HEADER "strategy one"

/* function prototypes */
void readValues(int SDKGrid[]);
void validateGrid(int SDKGrid[]);
void generateGrid(int SDKGrid[], int* unknownCount);
void ta_daa(void);
void newLine(void);
void getSetmates(int SDKGrid[], int cellNum, int cellMates[]); 
void digitCounter(int A[], int n, int set, int *missingCount, int *missingVal); 
void strategyOne(int sudoku[], const int* constantUnknowns);
int missingNum(int SDKGrid[]); 
int getFreq(int setNum, int A[], int n, int c, int *violations);
/****************************************************************/

int
main(int argc, char *argv[]) 
{
	/* initialise size of array to 81 */
	int sudokuValues[NCLL], unknownCount = 0;

	/* stage 1 (1): reads and stores 81 integer values */
	readValues(sudokuValues);

	/* stage 1 (2): prints scanned values out in sudoku grid */ 
	generateGrid(sudokuValues, &unknownCount);

	/* fills the two-dimensional array c2s */
	fill_c2s();
	
	/* stage 2: checking if sudoku puzzle contains any mistake */
	validateGrid(sudokuValues);

	/* set unknown cells from stage 1 to be constant int in order to compare 
	   with unknown counts after implementing strategy one */
	const int constantUnknowns = unknownCount;

	/* stage 3: solving the sudoku puzzle */
	strategyOne(sudokuValues, &constantUnknowns);

	return 0;
}

/* scans 81 integers and stores in array*/
void
readValues(int SDKGrid[]) 
{
	int i;
	/* read and store 81 integers from data txt */
	for (i = 0; i < NCLL; i++) 
	{
		scanf("%d", &SDKGrid[i]);
	}
}

/* Function to print out scanned values in sudoku grid format */
void
generateGrid(int SDKGrid[], int* unknownCount) 
{
	/* to count how many unknown cells there are in the puzzle*/
	// int unknownCount=0;
	int	crntCell;

	for (crntCell = 0; crntCell < NCLL; crntCell++) 
	{
		/* format 9 values each row */
	    if (crntCell % NDIG == 0) 
		{
	        newLine();
	    }

		/* separate every 3 values in each row */
	    if (((crntCell % NDIM == 0) || ((crntCell % (NDIM + NDIM) == 0))) && 
			(crntCell % (NDIM * NDIM) != 0)) 
		{
	        printf("%-2c", VERT_BAR);
	    }
		
		/* separate every 3 values in column */
	    if ((crntCell % NSET == 0) && (crntCell % NCLL != 0)) 
		{
	        printf(ROW_SPRT);
	    	newLine();
		}

		/* replace 0 with . while keeping count of it */
	    if (SDKGrid[crntCell] == 0) 
		{
			if (crntCell % NDIG == (NDIG-1)) {
				printf("%c", UNKN_CLL);
			} else {
				printf("%-2c", UNKN_CLL);
			}
			(*unknownCount)++;
		} 

		/* print out rest of integers in the formatted sudoku grid */
		else if (crntCell % NDIG == (NDIG-1)) 
		{
			printf("%d", SDKGrid[crntCell]);
		} 
		else 
		{
			printf("%-2d", SDKGrid[crntCell]);
		}
	}

	/* formatted is for solved sudokus - add a space before */
	if (*unknownCount == 0)
	{
		printf("\n\n %d cells are unknown\n", *unknownCount);
	}

	/* print unknowns */
	else 
	{
		printf("\n\n%d cells are unknown\n", *unknownCount);
	}
}

/* stage 2: checks if the values in every set from s2c are unique numbers, 
   otherwise terminate program */
void
validateGrid(int SDKGrid[]) 
{
	newLine();

	/* create a temporary array that store 9 values for each sets */
	int temp[NDIG];
		
	/* count the number of sets that are illegal */
	int violations = 0, setViolations = 0;

	int setNum, j, cellNum;

	/* temporary array fills the values from sudoku into the sets of s2c */
    for (setNum=0; setNum<NSET; setNum++) 
	{
		for (j=0; j<NDIG; j++) 
		{
			temp[j] = SDKGrid[s2c[setNum][j]]; 
            cellNum = s2c[setNum][j];
        }
		
		/* set violations increases by one every time the function returns
		   unique sets violated */
        setViolations += getFreq(setNum, temp, NDIG, cellNum, &violations);
    }

	/* prints out the counts if a sudoku is incorrect and terminates 
       the program */
	if (violations) 
	{
		printf("\n%d different sets have violations", setViolations);
		printf("\n%d violations in total\n", violations);
		exit(EXIT_FAILURE);
	}
}

/* counts the instances of digits (1-9) in each sets and look for values that
   has the frequency of over once. if a set is incorrect, there'll be a flag
   that counts how many sets in total are invalid */
int 
getFreq(int setNum, int temp[NDIG], int n, int cell, int *violations) 
{
	/*  flag to check if set violation occurs*/
    int setViolation = 0;

	/* 	initialise frequency array to count the instances of the 
		numbers in each sets  */
	int freq[n], 
		cellNum;

	/*	set default values from 1 to 9 where its frequency starts at 0 */ 
	for (cellNum = 0; cellNum <= n; cellNum++) 
	{
		freq[cellNum] = 0;
	}

	/* 	increment the frequency of the number that exist in the set	*/
	for (cellNum = 0; cellNum < n; cellNum++) 
	{
		freq[temp[cellNum]]++;
	}
	
	/* 	iterate through the array to print frequencies */
	for (cellNum = 0; cellNum <= n; cellNum++) 
	{
		/* filters for instances over 1 and cells that are unknown */
		if (freq[cellNum] > 1 && cellNum > 0) 
		{
			/* violated sets are counted uniquely */
			setViolation = 1;
			(*violations)++;
            
			printf("set %2d ", setNum);

			/* finds the group of which the sets are in */
			if (setNum < NDIG) 
			{
				printf("(row %d): ", rownum(cell));
			}

			else if (setNum < (NDIG + NDIG) && setNum > NDIG) 
			{
				printf("(col %d): ", colnum(cell));
			}

			else if (setNum > (NDIG + NDIG) && setNum < NSET) 
			{
				printf("(sqr %d): ", sqrnum(cell));
			}

			/* prints out the instances of the illegal sets */
			printf("%d instances of %d\n",freq[cellNum], cellNum);
		}
	}

	/* returns the value of 1 for unique sets */
    return setViolation;
}

/* merges the cells that are in the same set as a chosen cell in to one array
*/
void 
getSetmates(int SDKGrid[], int cellNum, int cellMates[]) 
{
	int setIdx, setCell;
	/* stores 3 by 9 values into empty into array from argument of NSET */
	for (setIdx = 0; setIdx < NGRP; setIdx++)
	{
		for (setCell = 0; setCell < NDIG; setCell++) 
		{
			/* array size of cellMates will be from 0 to < NSET */
			cellMates[(setIdx * NDIG) + setCell] = SDKGrid[s2c[c2s[cellNum]
													[setIdx]][setCell]];
		}
	}
}

/* stage 3 function: strategy will take set mates and check for missing
   numbers. the desired quantity of missing number is 1 and the program will
   recursively do so until every cell is solved */
void 
strategyOne(int SDKGrid[], const int* constantUnknowns) 
{
    printf(S1_HEADER);
    newLine();

	/* empty 3 x 9 array where it will be filled by the merged sets under
	getSetmates function */
	int cellMates[NDIG * NGRP];

	/* empty 81 array that serves as a copy for the original grid to update
	   in one go */
	int tempGrid[NCLL];

	int unknownCount = 0, cellNum;
	
	/* make a copy of orignal sudoku grid */
	for (cellNum = 0; cellNum < NCLL; cellNum++)
	{
		tempGrid[cellNum] = SDKGrid[cellNum];
	}

	/* look for zero cells and check if its possible missing value equals to
	   one otherwise move on to the next zero cell*/
	for (cellNum = 0; cellNum < NCLL; cellNum++) 
	{
		/* these variables' addressed will be passed to store accordingly */
		int missingVal, missingCount = 0;

		if (SDKGrid[cellNum] == 0) 
		{
			/* returns cellMates of merged set column and square */
			getSetmates(SDKGrid, cellNum, cellMates);

			/* looks at all existing values in merged array, counts digits 
			that aren't present in it */
			digitCounter(cellMates, NDIG, NSET, &missingCount, &missingVal);
			
			if (missingCount == 1)
			{
				/* fills in for the unknown cell */
				tempGrid[cellNum] = missingVal;
				
				/* fills in and print the correct value of the sudoku */
				printf("row %d col %d must be %d\n", rownum(cellNum), 
						colnum(cellNum), tempGrid[cellNum]);
			} 
		}
	}
	/* update filled values to the original sudoku grid */
	for (cellNum = 0; cellNum < NCLL; cellNum++)
	{
		SDKGrid[cellNum] = tempGrid[cellNum];
		
		/* count the number of unknowns if there are any remaining*/
		if (SDKGrid[cellNum] == 0)
		{
			unknownCount++;
		}
	}

	/* if initial count and end count doesn't change that it went through the 
	   entire grid and found no solutions. sudoku is unsolvable. */
	if ((*constantUnknowns == unknownCount))
	{
		int unknownCount = 0;
		generateGrid(SDKGrid, &unknownCount);
		exit(EXIT_FAILURE);
	}

	/* since sudoku isn't expected to be fully filled in one go, function will 
	repeat everytime until there are no more unknown cells */
	else if (unknownCount > 0) 
	{
		newLine();
		strategyOne(SDKGrid, &unknownCount);
	}

	/* sudoku successfully solved !!! */
	else if (unknownCount == 0)
	{
		generateGrid(SDKGrid, &unknownCount);
		ta_daa();
	}
}	

/* check for numbers (1-9) in the merged array, count the number(s) that 
   has the count of zero which is considered a possible solution */
void 
digitCounter(int grid[], int N, int set, int *missingCount, int *missingValue) 
{
    int freq[N], cellNum;

	/* fill empty with zeros to set frequency */
	for (int i=0; i<=N; i++)
	{
		freq[i] = 0;
	}

	/* initialise default value of zero to cellNum's frequency */
	for (cellNum = 1; cellNum <= N; cellNum++) 
	{
		freq[cellNum] = 0;
	}

	/* increment the frequency of the number that exists inside the set */
	for (cellNum = 0; cellNum < set; cellNum++) 
	{
		freq[grid[cellNum]]++;
	}

	/* for frequencies of 0 and known cells, count possible values that exists
	   and assign variable missingValue to i because only one value is needed*/
    for (int i = 0; i <= N; i++)
    {
        if (freq[i] == 0 && i > 0) 
		{
            *missingValue = i;
            (*missingCount)++;
        }
    }
}

/* short cut for new line */
void
newLine(void) 
{
	printf("\n");
}

/* short cut for printing celebration */
void
ta_daa(void) 
{
	printf("\nta daa!!!\n");
}

/* algorithms are fun */ 

/****************************************************************/

