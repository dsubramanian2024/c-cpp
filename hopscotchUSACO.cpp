# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning(disable:4996)

/*
read from file
create 2D array of structs (whose attributes are color and value)
start from 2nd to bottom-right and add possibilities
iteration inside recursion
iteration goes 

*/


typedef struct {char color; int val;} cell;


/*check if its correct color, otherwise move on*/


int file(void)
{
	FILE *fp = NULL;
	fp = fopen("censor.in", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int row, col;
	fscanf(fp, "%d %d \n", &row, &col);
	cell arr[15][15];
;	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			fscanf(fp, "%s", &arr[y][x].color);
		}
		fscanf(fp, "\n");
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int x = 1; x + i < row; x++)
			{
				for (int y = 1; y + j < col; y++)
				{
					if (arr[i][j].color != arr[i + x][j + y].color)
						arr[i + x][j + y].val += arr[i][j].val;
				}
			}
		}
	}

	fclose(fp);
	FILE *fp2 = NULL;
	//fopen_s(&fp2, "censor.out", "w");
	fp2 = fopen("censor.out", "w");
	if (fp2 == NULL)
		exit(EXIT_FAILURE);
	fprintf(fp2, "%d", arr[row - 1][col - 1].val);
	fclose(fp2);
	return 0;
}


int main(void)
{
	file();
	//system("pause");
}

