/******************************************************************************
* Author: Rishiraj Manwatkar <manwatkar.r@gmail.com>;<manwatkar@outlook.com>
* 
* This code generates a terminal based Christmas Tree. As a decoration, it also
* generates random Christmas Balls of random colors.
* 
* Enjoy! Merry Christmas!!
******************************************************************************/

/*
TODO: 1) Lots of redundant and unnecessary symbols / MACRO definitions are
	  residing in this code that need to cleaned up.
	  2) Need to change symbols' names.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define gotoxy(row, col) printf("\033[%d;%dH", (row), (col))

#define changeColor(row) printf("\e[%dm", (row))

#define printStar(row, col)	gotoxy(row, col);\
						printf("*");

#define printSpace(row, col)	gotoxy(row, col);\
						printf(" ");

#define printBall(row, col)	gotoxy(row, col);\
						printf("O");

#define printTrunk(row, col)	gotoxy(row, col);\
						printf("|");

#define OFFSET 	(5)
#define rowA	(0 + OFFSET)
#define colA	(20 + OFFSET)

char *msg = "M E R R Y - C H R I S T M A S";


int generateRandomNumber(int min, int max)
{
	if (min > max)
	{
		min ^= max;
		max ^= min;
		min ^= max;
	}

	return (rand() % (1 + max - min)) + min;
}

int main(int argc, char *argv[])
{
	int i, j, rows = 25;
	int k;
	unsigned ball;
	while(1)
	{
		i=0, j=0;
		gotoxy(rowA, colA);
		while(++i < rows)
		{
			for(k = -2; ++k < rows-i; )
			{
				printSpace(rowA+i, colA+k);
			}

			ball = 1;
			for(j = 0; ++j < 2*i; )
			{
				if(j == generateRandomNumber(j, 2*i) && ball == 1)
				{
					changeColor(generateRandomNumber(31, 36));
					printf("o");
					changeColor(37);
					ball--;
				}
				else
				{
					changeColor(32);
					printf("*");
					changeColor(37);
				}
			}

			for(j=0; j<6; j++)
			{
				for(k=0; k<6; k++)
				{
					changeColor(32);
					printTrunk(rowA+rows+j, colA+rows-3+k);
					changeColor(37);
				}
			}

			gotoxy(rowA+rows+7, colA-rows+35);
			for(j=0; j<strlen(msg); j++)
			{
				if(j==generateRandomNumber(0, strlen(msg)))
				{
					changeColor(generateRandomNumber(31, 36));
					printf("%c", msg[j]);
				}
				else
				{
					printf("%c", msg[j]);
				}
			}
			changeColor(37);

			printf("\n");
			usleep(9000);
		}
	}

	return 0;
}