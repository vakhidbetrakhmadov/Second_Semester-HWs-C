#include <stdio.h>
#include <math.h>

void initBoard(char *board);
void getPosition(char* col,int* row);
int isValidCell (char col,int row);
void printBoard (char *board);
int isPieceMovable(char *board);
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
void emptyBuffer(void);
char whatIsInTheCell(char *board,char col,int row);
int adressOfTheCell(char col,int row);


int main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		command=0;
		scanf("%d", &command);
	
	}
	return 0;
}


void emptyBuffer()
{
	while ( getchar() != '\n' );
}



void initBoard(char *board)
{
	int i;

	for(i=0;i<64;++i)
		board[i]=' ';

	/*Black pieces on the board */

	board[0]='r';
	board[1]='n';
	board[2]='b';
	board[3]='q';
	board[4]='k';
	board[5]='b';
	board[6]='n';
	board[7]='r';	

	for (i=8;i<16;++i)
	{
		board[i]='p';
	}

	/*White pieces on the board */

	board[56]='R';
	board[57]='N';
	board[58]='B';
	board[59]='Q';
	board[60]='K';
	board[61]='B';
	board[62]='N';
	board[63]='R';

	for (i=48;i<56;++i)
	{
		board[i]='P';
	}
}

void printBoard (char *board)
{
	int i,j;

	printf ("  a b c d e f g h\n");
	printf("  - - - - - - - -\n");

	/* prints bord ,line by line */
	for(i=8;i!=0;--i)
	{
		/*ptints numbers on the left side of the board */
		printf("%d|",i);
		
		for(j=(8*(8-i));j<8*(9-i);++j)
		{
			printf("%c",board[j]);

			/*leaves spaces between the characters on the board, omiting the space */
			/* after last character of each line */
			if(j!=(8*(9-i)-1))
				printf(" ");
		}

		/*gets to the new line at the end of each line */
		printf("|");
		printf("\n");
	}

	printf("  - - - - - - - -\n");
}

int isPieceMovable(char *board)
{	
	char empty;
	char col;
	int row;
	char sourceCol;
	int sourceRow;
	char targetCol;
	int targetRow;
	char sourceCage;
	char targetCage;

	/*gets source cell adress from the user*/
	getPosition(&col,&row);

	/*checks if the cell is within the board */
	if(isValidCell(col,row))
	{
		sourceCol=col;
		sourceRow=row;
	}
	else 
	{
		return 0;
	}

	/*reads space character between 1st and 2nd cell adresses*/
	scanf("%c", &empty);

	/*gets target cell adress from the user */
	getPosition(&col,&row);

	/*checks if the cell is within the board*/
	if(isValidCell(col,row))
	{	
		targetCol=col;
		targetRow=row;
	}
	else
	{
		return 0;
	}

	/*checks what is in the source and target cells given by user */
	sourceCage=whatIsInTheCell(board,sourceCol,sourceRow);
	targetCage=whatIsInTheCell(board,targetCol,targetRow);

	/*calls appropriate function according to the piece loccated in the source cell*/
	switch(sourceCage)
	{
		case 'p':
		{
			/*checks if the piece is movable according to the game's rules */
			/*and if the target cell is occupied by a friendly piece */
			if(isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow) &&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		case 'P':
		{
			if(isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow) &&
				!(targetCage>='A' && targetCage<='Z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		case 'r':
		{
			if(isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else
			{
				return 0;
			} 
		}break;

		case 'R':
		{
			if(isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='A' && targetCage<='Z'))
			{
				return 1;
			}
			else
			{	
				return 0;
			}
		}break;

		case 'n':
		{
			if(isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else
			{
				return 0;
			} 	
		}break;

		case 'N':
		{

			if(!(targetCage>='A' && targetCage<='Z') &&
				(isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}break;

		case 'b':
		{
			if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		case 'B':
		{
			if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='A' && targetCage<='Z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}	
		}break;

		case 'q':
		{
			if(isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		case 'Q':
		{
			if(isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='A' && targetCage<='Z'))
			{
				return 1;
			}
			else
			{ 
				return 0;
			}
		}break;

		case 'k':
		{
			if(isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='a' && targetCage<='z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		case 'K':
		{
			if(isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow)&&
				!(targetCage>='A' && targetCage<='Z'))
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}break;

		default: 
		{
			return 0;

		}break;
	}

	return 0;
}

void getPosition(char* col,int* row)
{
	scanf("%c%d",col,row);
}

int isValidCell (char col,int row)
{
	if(((col>='a') && (col<='h')) && ((row>=1)&&(row<=8)) )
		return	1;
	else 
		return 0;
}

char whatIsInTheCell(char *board,char col,int row)
{
	int adress = adressOfTheCell(col,row);

	/*returns the content of the cell */
	return board[adress];
}

int adressOfTheCell(char col,int row)
{
	int column;

	switch (col)
	{
		case 'a':column=0;break;
		case 'b':column=1;break;
		case 'c':column=2;break;
		case 'd':column=3;break;
		case 'e':column=4;break;
		case 'f':column=5;break;
		case 'g':column=6;break;
		case 'h':column=7;break;
		default:break;
	}

	/*formule for the adress of the cell on the board (8*(8-row)+col)*/
	return((8*(8-row))+(column));
}

int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{

	/*checks if the move is one step move in any direction */
	if ((targetCol==sourceCol || targetCol==sourceCol+1 || targetCol==sourceCol-1) &&
		(targetRow==sourceRow || targetRow==sourceRow+1 || targetRow==sourceRow-1))	
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 0;
}

int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{	
	/* column and row moves.The same as in the queen function */

	int i;

	if(targetCol==sourceCol)
	{
		if(targetRow>sourceRow)
		{
			for(i=sourceRow+1;i<targetRow;++i)
			{
				if (whatIsInTheCell(board,sourceCol,i)!=' ')
				{
					return 0;
				}
			}

			return 1;
		}

		else 
		{
			for(i=sourceRow-1;i>targetRow;--i)
			{
				if (whatIsInTheCell(board,sourceCol,i)!=' ')
				{
					return 0;
				}
			}

			return 1;
		} 	
	}
	
	else if (targetRow==sourceRow)
	{
		if(targetCol>sourceCol)
		{
			for(i=sourceCol+1;i<targetCol;++i)
			{
				if (whatIsInTheCell(board,i,sourceRow)!=' ')
				{
					return 0;
				}
			}

			return 1;
		}

		else 
		{
			for(i=sourceCol-1;i>targetCol;--i)
			{
				if (whatIsInTheCell(board,i,sourceRow)!=' ')
				{
					return 0;
				}
			}

			return 1;
		} 	
	}

	else 
	{
		return 0;
	}

	return 0;
}

int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	/*Diagonal moves . The same as in the queen function*/

	int i,j;

	if((targetCol>sourceCol)&&(targetRow>sourceRow))
	{
		j=sourceRow;

		for(i=sourceCol;i<targetCol;++i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			++j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	else if ((targetCol>sourceCol)&&(targetRow<sourceRow))
{
		j=sourceRow;

		for(i=sourceCol;i<targetCol;++i) 
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			--j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	else if((targetCol<sourceCol)&&(targetRow>sourceRow))
	{
		j=sourceRow;

		for(i=sourceCol;i>targetCol;--i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			++j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	else if ((targetCol<sourceCol)&&(targetRow<sourceRow))
{
		j=sourceRow;

		for(i=sourceCol;i>targetCol;--i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			--j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	else 
	{
		return 0;
	}

	return 0;
}

int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	int i,j;

	/*checks if the move is along the same column*/
	if(targetCol==sourceCol)
	{
		/* if up the column*/
		if(targetRow>sourceRow)
		{
			for(i=sourceRow+1;i<targetRow;++i)
			{
				/*checks for the obstacle on the pass */
				if (whatIsInTheCell(board,sourceCol,i)!=' ')
				{
					return 0;
				}
			}

			return 1;
		}

		/*if down the column*/
		else 
		{
			for(i=sourceRow-1;i>targetRow;--i)
			{
				if (whatIsInTheCell(board,sourceCol,i)!=' ')
				{
					return 0;
				}
			}

			return 1;
		} 	
	}
	
	/*if along the same row */
	else if (targetRow==sourceRow)
	{
		/*to the right*/
		if(targetCol>sourceCol)
		{
			for(i=sourceCol+1;i<targetCol;++i)
			{
				if (whatIsInTheCell(board,i,sourceRow)!=' ')
				{
					return 0;
				}
			}

			return 1;
		}

		/*to the left*/
		else 
		{
			for(i=sourceCol-1;i>targetCol;--i)
			{
				if (whatIsInTheCell(board,i,sourceRow)!=' ')
				{
					return 0;
				}
			}

			return 1;
		} 	
	}

	/*diagonally right up */
	else if((targetCol>sourceCol)&&(targetRow>sourceRow))
	{
		j=sourceRow;

		/*check the diagonal for the obstacles, starting from the source cell*/
		for(i=sourceCol;i<targetCol;++i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			++j;
		}

		/*checks whether the target is really on the diagonal*/
		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	/*diagonally right down*/
	else if ((targetCol>sourceCol)&&(targetRow<sourceRow))
{
		j=sourceRow;

		for(i=sourceCol;i<targetCol;++i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			--j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	/*diagonally left up*/
	else if((targetCol<sourceCol)&&(targetRow>sourceRow))
	{
		j=sourceRow;

		for(i=sourceCol;i>targetCol;--i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			++j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	/*diagonally left down */
	else if ((targetCol<sourceCol)&&(targetRow<sourceRow))
{
		j=sourceRow;

		for(i=sourceCol;i>targetCol;--i)
		{
			if ((whatIsInTheCell(board,i,j)!=' ') &&
				(whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,sourceRow)))
			{
				return 0;
			}	

			--j;
		}

		if ((targetCol-i==0)&&(targetRow-j==0))
			return 1;
		else 
			return 0;	
	}

	else 
	{
		return 0;
	}

	return 0;
}

int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
	/*checks if the move is within first two columns from each side*/
	if((targetCol==sourceCol+1) || (targetCol==sourceCol-1))
	{
		/*cheks if the move is within second two rows from each side */
		if((targetRow==sourceRow+2) || (targetRow==sourceRow-2))
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	/*cheks if the move is within second two columns from each side */
	else if ((targetCol==sourceCol+2) || (targetCol==sourceCol-2))
	{
		/*checks if the move is within first two rows from each side*/
		if((targetRow==sourceRow+1) || (targetRow==sourceRow-1))
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	else 
	{
		return 0;
	}

	return 0;
}

int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{	
	if((whatIsInTheCell(board,sourceCol,sourceRow)=='p' && targetRow>sourceRow) ||
		(whatIsInTheCell(board,sourceCol,sourceRow)=='P' && targetRow<sourceRow))
	{
		return 0;
	}

	/*checks if the move is along the same column*/
	if(targetCol==sourceCol)
	{
		/*checks if the move is one cage forward */
		/* and if there is any obstacle */
		if (((targetRow==sourceRow+1) || (targetRow==sourceRow-1))
			&&(whatIsInTheCell(board,targetCol,targetRow)==' ')) 
			return 1;
		else
			return 0;
	}
	/* Checks if the move is cross move  */
	else if ((targetCol==sourceCol+1) || (targetCol==sourceCol-1))
	{
		/*Checks if the move is one step cross move and if there is an enemy */
		if (((targetRow==sourceRow+1) || (targetRow==sourceRow-1))
			&&(whatIsInTheCell(board,targetCol,targetRow)!=' '))
			return 1;
		else 
			return 0;
	}
	else 	
	{
		return 0;
	}

	return 0;
}
