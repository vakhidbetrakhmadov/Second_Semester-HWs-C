/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW08_141044086_Vakhid_Betrakhmadov                                       */
/*                                                                          */
/* main.c                                                                   */
/* ---------                                                                */
/* Created on 04/22/2016 by Vakhid_Betrakhmadov                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* Includes                                                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>

/*--------------------------------------------------------------------------*/
/*                           #defines                                       */
/*--------------------------------------------------------------------------*/
#define BOARD_SIZE 8

/*---------------------------------------------------------------------------*/
/* Function Prototypes                                                       */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  int isPieceMovable(char *board)                                          */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */
/* This function checks if the move is possiable according to the            */
/* game's rules ( is piece movable itself, is target cell occupied by        */ 
/* firendly piece                                                            */
/*---------------------------------------------------------------------------*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isInCheck(char* board)                                                */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/*                                                                           */
/* Returns                                                                   */
/* ------                                                                    */
/* 1- if white king is in check                                              */
/* 2- black king is in check                                                 */
/* 0- there is no check at all                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function looks if either of kings on the board is currently in check */
/* This function returns it's result according to the last black and white   */
/* kings found on the board,so there can be only one white and only one black*/
/* king on the board simultaneously for the correct result of the function   */ 
/*---------------------------------------------------------------------------*/
int isInCheck(char* board);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int makeMove(char *board, char sc, int sr, char tc, int tr)               */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sc- column of the source cell                                             */
/* sr - row of the source cell                                               */
/* tc- column of the target cell                                             */
/* tr - row of the target cell                                               */
/*                                                                           */
/* Returns                                                                   */
/* ------                                                                    */
/* 0 - move is invalid                                                       */
/* 1 - move is invalid because same player's king is in check                */
/* 2 - move is valid                                                         */
/* 3 - move is valid and opponent player's king is in check                  */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function makes move if the attempted move is possible according to   */
/* the game's rules                                                          */
/*---------------------------------------------------------------------------*/
int makeMove(char *board, char sc, int sr, char tc, int tr);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  void initBoard(char *board)                                              */
/* -----------                                                               */
/*                                                                           */
/* board - character array to store the chess board                          */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Function does not return anything                                         */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function initializes the chess board by at first setting all         */
/*elements of the array to spaces,and then placing the pieces in the correct */
/* order for both users                                                      */
/*---------------------------------------------------------------------------*/
void initBoard(char *board);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  void getPosition(char* col,int* row)                                     */
/* -----------                                                               */
/*                                                                           */
/* col- column on the chess board                                            */
/* row - row on the chess board                                              */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Function does not return anything                                         */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function gets to inputs from the user and return them through the    */
/* pointers                                                                  */
/*---------------------------------------------------------------------------*/
void getPosition(char* col,int* row);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  int isValidCell (char col,int row)                                       */
/* -----------                                                               */
/*                                                                           */
/* col- column on the chess board                                            */
/* row - row on the chess board                                              */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks whether given adress is within board's size          */
/*---------------------------------------------------------------------------*/
int isValidCell (char col,int row);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  void printBoard (char *board)                                            */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* Function does not return anything                                         */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function prints the current state of the chess board on the screen   */
/*---------------------------------------------------------------------------*/
void printBoard (char *board);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  int isKingMovable(char *board,char sourceCol,                            */
/*  int sourceRow,char targetCol,int targetRow)                              */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a King is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*  int isRookMovable(char *board,char sourceCol,int sourceRow,              */
/*  char targetCol,int targetRow)                                            */
/* -----------                                                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a Rook is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/
int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isBishopMovable(char *board,char sourceCol,int sourceRow,             */
/* char targetCol,int targetRow)                                             */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a Bishop is movable according to the game's rules */
/*---------------------------------------------------------------------------*/
int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isQueenMovable(char *board,char sourceCol,int sourceRow,              */
/* char targetCol,int targetRow)                                             */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a Queen is movable according to the game's rules  */
/*---------------------------------------------------------------------------*/
int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isKnightMovable(char *board,char sourceCol,int sourceRow,             */
/* char targetCol,int targetRow)                                             */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a Knight is movable according to the game's rules */
/*---------------------------------------------------------------------------*/
int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isPawnMovable(char *board,char sourceCol,                             */
/* int sourceRow,char targetCol,int targetRow)                               */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1 on success                                                              */
/* 0 on failer                                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function checks if a Pawn is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/
int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* char whatIsInTheCell(char *board,char col,int row                         */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* сol- column on the chess board                                            */
/* row - number of row on the chess board                                    */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* content of the cell with adress col and row                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function figures out what is curently loccated in the cell           */
/*---------------------------------------------------------------------------*/
char whatIsInTheCell(char *board,char col,int row);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int adressOfTheCell(char col,int row )                                    */
/*                                                                           */
/* сol- column on the chess board                                            */
/* row - number of row on the chess board                                    */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* Decimal adress in the array                                               */
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function converts adress of the cell on the chess board given by     */
/* column letter and row number to decimal adress in the array               */
/*---------------------------------------------------------------------------*/
int adressOfTheCell(char col,int row);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int getPlayer(char *board, char col,int row)                              */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* сol- column on the chess board                                            */
/* row - number of row on the chess board                                    */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1- the piece is white(upper case )                                        */
/* 0- the piece is black(lower case )                                        */
/* Description                                                               */
/* -----------                                                               */ 
/* This function check's the collor of the piece in the cell with adress col */
/* and row on the board                                                      */
/*---------------------------------------------------------------------------*/
int getPlayer(char *board, char col,int row);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isBlack(int currPlayer)                                               */
/*                                                                           */
/* currPlayer-integer indicating current player (1 -white,0 -black)          */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1- currPlayer==0                                                          */
/* 0- currPlayer==1                                                          */
/* Description                                                               */
/* -----------                                                               */ 
/* This function is true if the currPlayer is black(0)                       */
/*---------------------------------------------------------------------------*/
int isBlack(int currPlayer);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* int isBlack(int currPlayer)                                               */
/*                                                                           */
/* currPlayer-integer indicating current player (1 -white,0 -black)          */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* 1- currPlayer==1                                                          */
/* 0- currPlayer==0                                                          */
/* Description                                                               */
/* -----------                                                               */ 
/* This function is true if the currPlayer is white(1)                       */
/*---------------------------------------------------------------------------*/
int isWhite(int currPlayer);

/*---------------------------------------------------------------------------*/
/*                                                                           */
/* void kingsLocation(char *board,char *whiteKingCol,int* whiteKingRow,      */
/*    char* blackKingCol,int* blackKingRow)                                  */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* whiteKingCol - column of the white kings current location on the board    */
/* whiteKingRow - row of the white kings current location on the board       */
/* blackKingCol - column of the black kings current location on the board    */
/* blackKingRow - row of the black kings current location on the board       */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* Returns ,through the pointers  mentioned above ,current loccations of the */
/* white and black king on the board                                         */ 
/*                                                                           */
/* Description                                                               */
/* -----------                                                               */ 
/* This function finds and returns current loccations of the last white and  */
/* black king found on the board                                             */
/*---------------------------------------------------------------------------*/
void kingsLocation(char *board,char *whiteKingCol,int* whiteKingRow,
    char* blackKingCol,int* blackKingRow);


/*---------------------------------------------------------------------------*/
/*                                                                           */
/* void moveThePiece(char *board,char sourceCol,int sourceRow,char targetCol,*/
/*   int targetRow)                                                          */
/*                                                                           */
/* board - chess board ( array of size 64 )                                  */
/* sourceCol- column of the source cell                                      */
/* sourceRow - row of the source cell                                        */
/* targetCol- column of the target cell                                      */
/* targetRow - row of the target cell                                        */
/*                                                                           */ 
/* Return                                                                    */
/* ------                                                                    */
/* Nothing                                                                   */
/* -----------                                                               */ 
/* This function moves piece from source adress to the target adress filling */
/* source adress with empty character                                        */
/*---------------------------------------------------------------------------*/
void moveThePiece(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow);

/******************************************************************************/

int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);

    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        /*emptyBuffer();*/
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n ");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black":"White" );
    return 0;
}

/******************************************************************************/

/*---------------------------------------------------------------------------*/
/* Function Implementations                                                  */
/*---------------------------------------------------------------------------*/ 
/*here we have empty buffer function*/
void emptyBuffer(void)
{
    char tresh;

    while(tresh!='\n')
    {
        scanf("%c",&tresh);
    }
}

/* Function  getPlayer                                                       */
/* -----------                                                               */ 
/* This function check's the collor of the piece in the cell with adress col */
/* and row on the board                                                      */
/*---------------------------------------------------------------------------*/

/*here we have function which looks what's in the source adress*/
/*Returns: >1 if white player is trying to make a move */
/* >2 if black player is trying to make a move  */
int getPlayer(char *board, char col,int row)
{
    if(isValidCell(col,row))
    {
        if(isupper(whatIsInTheCell(board,col,row)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0    ;
}

/*---------------------------------------------------------------------------*/ 
/* Function  isBlack                                                         */
/* -----------                                                               */ 
/* This function is true if the currPlayer is black(0)                       */
/*---------------------------------------------------------------------------*/
int isBlack(int currPlayer)
{
    if(!currPlayer)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*---------------------------------------------------------------------------*/ 
/* Function  isWhite                                                         */
/* -----------                                                               */ 
/* This function is true if the currPlayer is white(1)                       */
/*---------------------------------------------------------------------------*/
int isWhite(int currPlayer)
{
    if(currPlayer)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*---------------------------------------------------------------------------*/ 
/* Function getPosition                                                      */
/* -----------                                                               */ 
/* This function gets to inputs from the user and return them through the    */
/* pointers                                                                  */
/*---------------------------------------------------------------------------*/
void getPosition(char* col,int* row)
{
    scanf("%c%d",col,row);
}

/* Function isValidCell                                                      */
/* -----------                                                               */ 
/* This function checks whether given adress is within board's size          */
/*---------------------------------------------------------------------------*/
/*here we check if the entered adress is within board size*/
int isValidCell (char col,int row)
{
    if(((col>='a') && (col<='h')) && ((row>=1)&&(row<=8)) )
        return  1;
    else 
        return 0;
}

/* Function whatIsInTheCell                                                  */
/* -----------                                                               */ 
/* This function figures out what is curently loccated in the cell           */
/*---------------------------------------------------------------------------*/
/*here we return the piece loccated in the cell with adress col and row*/
char whatIsInTheCell(char *board,char col,int row)
{
    int adress=0;

    /*if we start to check beyond the board (cases col<a or row>8*/
    if (isValidCell(col,row)==0)
    {
        return ' ';
    }

    adress = adressOfTheCell(col,row);

    /*returns the content of the cell */
    return board[adress];
}

/* Function adressOfTheCell                                                  */
/* -----------                                                               */ 
/* This function converts adress of the cell on the chess board given by     */
/* column letter and row number to decimal adress in the array               */
/*---------------------------------------------------------------------------*/
/*here we convert col-row adress on the board to the appropriate array index */
int adressOfTheCell(char col,int row)
{
    int column;

    if(isValidCell(col,row)==0)
    {   
        return 0;
    }

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

/* Function initBoard                                                        */
/* -----------                                                               */ 
/* This function gets to inputs from the user and return them through the    */
/* pointers                                                                  */
/*---------------------------------------------------------------------------*/
/*here we initialize the board*/
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

/* Function printBoard                                                       */
/* -----------                                                               */
/* This function prints the current state of the chess board on the screen   */
/*---------------------------------------------------------------------------*/

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

/* Function kingsLocation                                                    */
/* -----------                                                               */ 
/* This function finds and returns current loccations of the last white and  */
/* black king found on the board                                             */
/*---------------------------------------------------------------------------*/

/* Here we find current location of both kings on the board*/
/* Because the function returns positions of the last found pair of kings*/
/* (white and black) there can be only one black and only one white king */
/* simultaneously on the board*/
void kingsLocation(char *board,char *whiteKingCol,int* whiteKingRow,
    char* blackKingCol,int* blackKingRow)
{
    int row;
    char col;

    for(row=1;row<=BOARD_SIZE;++row)
    {
        for(col='a';col<='h';++col)
        {
            if(whatIsInTheCell(board,col,row)=='K')
            {
                *whiteKingCol=col;
                *whiteKingRow=row;
            }
            else if(whatIsInTheCell(board,col,row)=='k')
            {
                *blackKingCol=col;
                *blackKingRow=row;
            }
            else
            {
                /*do nothing*/
            }
        }
    }
}

/* Function moveThePiece                                                     */
/* -----------                                                               */ 
/* This function moves piece from source adress to the target adress filling */
/* source adress with empty character                                        */
/*---------------------------------------------------------------------------*/
/*here we move piece on the board from source adress to the target adress*/
void moveThePiece(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
{
    int sourceAdress;
    int targetAdress;

    sourceAdress=adressOfTheCell(sourceCol, sourceRow);
    targetAdress=adressOfTheCell(targetCol, targetRow);

    board[targetAdress]=board[sourceAdress];
    board[sourceAdress]=' ';
}

/* Function makeMove                                                         */
/* -----------                                                               */ 
/* This function makes move if the attempted move is possible according to   */
/* the game's rules                                                          */
/*---------------------------------------------------------------------------*/
/*here we check if the move can be accomplished according to the game's rules*/
/*and move it if yes */
int makeMove(char *board, char sc, int sr, char tc, int tr)
{
    int currPlayer;
    char tempPiece;

    /*here we figure out whose turn it is */
    currPlayer = getPlayer(board, sc,sr);

    /*if piece is inmovable - move is invalid*/
    if(isPieceMovable(board,sc,sr,tc,tr)==0)
    {
        return 0;
    }

    /*else if piece is movable*/
    else
    {
        /*we look if the current player's king is in check*/
        if((isInCheck(board)==1 && isWhite(currPlayer))||
        (isInCheck(board)==2 && isBlack(currPlayer)))
        {   
            /*if yes,we look if he is still in check after the attempted move*/
            /*takes piece in target cell to the temp variable*/
            tempPiece=whatIsInTheCell(board,tc,tr);
            /*makes move*/
            moveThePiece(board,sc,sr,tc,tr);

            /*checks if the current player's king is in check again after the move*/
            /*if yes - backs the move,returns 1 (so move is invalid)*/
            if((isInCheck(board)==1 && isWhite(currPlayer))||
            (isInCheck(board)==2 && isBlack(currPlayer)))
            {
                /*here we reverse the move*/
                moveThePiece(board,tc,tr,sc,sr);
                board[adressOfTheCell(tc,tr)]=tempPiece;

                return 1;
            }

            /*the player's king is not in check anymore after the move */
            /*so the move is valid,now let's see what's going on with */
            /*opponent player's king */
            
            /*opponent player's king is in check after the move*/
            if((isInCheck(board)==1 && isBlack(currPlayer))||
            (isInCheck(board)==2 && isWhite(currPlayer)))
            {
                return 3;
            }

            /*here we just rescued the king*/
            return 2;
        }

        tempPiece=whatIsInTheCell(board,tc,tr);
        moveThePiece(board,sc,sr,tc,tr);

        /***********************************************/
        /* IS THERE A CHECK FOR ME AFTER THE MOVE */
        /**********************************************/
         /*checks if current player's king is in check after the move*/
        if((isInCheck(board)==1 && isWhite(currPlayer))||
        (isInCheck(board)==2 && isBlack(currPlayer)))
        {
            /*here we reverse the move*/
            moveThePiece(board,tc,tr,sc,sr);
            board[adressOfTheCell(tc,tr)]=tempPiece;

            return 1;
        }

        /*opponent player's king is in check after the move*/
        if((isInCheck(board)==1 && isBlack(currPlayer))||
        (isInCheck(board)==2 && isWhite(currPlayer)))
        {
            return 3;
        }

        return 2;
    }

    return 0;
}

/* Function isPieceMovable                                                   */
/* -----------                                                               */ 
/* This function checks if the move is possiable according to the            */
/* game's rules ( is piece movable itself, is target cell occupied by        */ 
/* firendly piece                                                            */
/*---------------------------------------------------------------------------*/
/* here we check if the particular piece can move the required way and if */
/* the target cell is not occuppied by any friendly piece */
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{   
    char sourceCage;
    char targetCage;

    /*checks what is in the source and target cells given by user */
    sourceCage=whatIsInTheCell(board,sc,sr);
    targetCage=whatIsInTheCell(board,tc,tr);

    /*calls appropriate function according to the piece loccated in the source*/
    /*cell*/
    switch(sourceCage)
    {
        case 'p':
        {
            /*checks if the piece is movable according to the game's rules */
            /*and if the target cell is occupied by a friendly piece */
            if(isPawnMovable(board,sc,sr,tc,tr) &&
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
            if(isPawnMovable(board,sc,sr,tc,tr) &&
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
            if(isRookMovable(board,sc,sr,tc,tr)&&
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
            if(isRookMovable(board,sc,sr,tc,tr)&&
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
            if(isKnightMovable(board,sc,sr,tc,tr)&&
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
                (isKnightMovable(board,sc,sr,tc,tr)))
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
            if(isBishopMovable(board,sc,sr,tc,tr)&&
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
            if(isBishopMovable(board,sc,sr,tc,tr)&&
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
            if(isQueenMovable(board,sc,sr,tc,tr)&&
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
            if(isQueenMovable(board,sc,sr,tc,tr)&&
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
            if(isKingMovable(board,sc,sr,tc,tr)&&
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
            if(isKingMovable(board,sc,sr,tc,tr)&&
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

/* Function isInCheck                                                        */
/* -----------                                                               */ 
/* This function looks if either of kings on the board is currently in check */
/* This function returns it's result according to the last black and white   */
/* kings found on the board,so there can be only one white and only one black*/
/* king on the board simultaneously for the correct result of the function   */ 
/*---------------------------------------------------------------------------*/

int isInCheck(char* board)
{
    char whiteKingCol;
    int whiteKingRow;
    char blackKingCol;
    int blackKingRow;
    int i,j;
    int safe;
    char cellContent;

    /*finds the current location of the both kings on the board*/
    kingsLocation(board,&whiteKingCol,&whiteKingRow,&blackKingCol,
        &blackKingRow);

    /*-----------------FOR THE WHITE KING------------------*/
    
    /*checks if there is enemy pawn nearby*/
    if(whatIsInTheCell(board,whiteKingCol+1,whiteKingRow+1)=='p' || 
        whatIsInTheCell(board,whiteKingCol-1,whiteKingRow+1)=='p')
    {
        return 1;
    }

    /*checks if there is a knight nearby*/
    if (whatIsInTheCell(board,whiteKingCol+1,whiteKingRow+2)=='n' ||
        whatIsInTheCell(board,whiteKingCol+2,whiteKingRow+1)=='n' ||
        whatIsInTheCell(board,whiteKingCol+1,whiteKingRow-2)=='n' ||
        whatIsInTheCell(board,whiteKingCol+2,whiteKingRow-1)=='n' ||
        whatIsInTheCell(board,whiteKingCol-1,whiteKingRow+2)=='n' ||
        whatIsInTheCell(board,whiteKingCol-2,whiteKingRow+1)=='n' ||
        whatIsInTheCell(board,whiteKingCol-1,whiteKingRow-2)=='n' ||
        whatIsInTheCell(board,whiteKingCol-2,whiteKingRow-1)=='n')
    {
        return 1;
    }

    safe=0;

    /*scans for the check to the right of the row */
    for(i=whiteKingCol+1;i<='h';++i)
    {
        cellContent=whatIsInTheCell(board,i,whiteKingRow);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        row*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='p' ||
            cellContent=='n' || cellContent=='b' || cellContent=='k')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the row and the pass is not safe */
        if((cellContent=='q' || cellContent=='r') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans for the check to the left of the row */
    for(i=whiteKingCol-1;i>='a';--i)
    {
        cellContent=whatIsInTheCell(board,i,whiteKingRow);
        
        /*indicates that the pass is safe if there is a friendly piece on the
         row*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='p' ||
            cellContent=='n' || cellContent=='b' || cellContent=='k')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the row and the pass is not safe */
        if((cellContent=='q' || cellContent=='r') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans the column up for the check */
    for(i=whiteKingRow+1;i<=8;++i)
    {
        cellContent=whatIsInTheCell(board,whiteKingCol,i);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        column*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='p' ||
            cellContent=='n' || cellContent=='b' || cellContent=='k')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not
         safe */
        if((cellContent=='q' || cellContent=='r') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans the column down for the check*/
    for(i=whiteKingRow-1;i>=1;--i)
    {
        cellContent=whatIsInTheCell(board,whiteKingCol,i);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='p' ||
            cellContent=='n' || cellContent=='b' || cellContent=='k')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='q' || cellContent=='r') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans diagonally right up for the check*/
    for(i=whiteKingCol+1,j=whiteKingRow+1;i<='h' && j<=8;++i,++j)
    {
        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on 
        the clumn*/
        if((cellContent>='A' && cellContent<='Z' && cellContent!='K') ||
         cellContent=='r' || cellContent=='n' || cellContent=='k' || 
         cellContent=='p')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not
         safe */
        if((cellContent=='b' || cellContent=='q') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans diagonally right down for the check */
    for(i=whiteKingCol+1,j=whiteKingRow-1;i<='h' && j>=1;++i,--j)
    {
        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='r' ||
            cellContent=='n' || cellContent=='k' || cellContent=='p')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='b' || cellContent=='q') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans diagonally left up for the check */
    for(i=whiteKingCol-1,j=whiteKingRow+1;i>='a' && j<=8;--i,++j)
    {
        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='A' && cellContent<='Z' && cellContent!='K') || 
            cellContent=='r' || cellContent=='n' || cellContent=='k' || 
            cellContent=='p')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='b' || cellContent=='q') && safe==0)
        {
            return 1;
        }
    }

    safe=0;

    /*scans diagonally left down for the check */
    for(i=whiteKingCol-1,j=whiteKingRow-1;i>='a' && j>=1;--i,--j)
    {   
        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='A' && cellContent<='Z') || cellContent=='r' ||
            cellContent=='n' || cellContent=='k' || cellContent=='p')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not
         safe */
        if((cellContent=='b' || cellContent=='q') && safe==0)
        {
            return 1;
        }
    }

    /*---------------------FOR THE BLACK KING---------------------- */

    /*checks if there is enemy pawn nearby*/
    if(whatIsInTheCell(board,blackKingCol+1,blackKingRow-1)=='P' || 
        whatIsInTheCell(board,blackKingCol-1,blackKingRow-1)=='P')
    {
        return 2;
    }

    /*checks if there is a knight nearby*/
    if (whatIsInTheCell(board,blackKingCol+1,blackKingRow+2)=='N' ||
        whatIsInTheCell(board,blackKingCol+2,blackKingRow+1)=='N' ||
        whatIsInTheCell(board,blackKingCol+1,blackKingRow-2)=='N' ||
        whatIsInTheCell(board,blackKingCol+2,blackKingRow-1)=='N' ||
        whatIsInTheCell(board,blackKingCol-1,blackKingRow+2)=='N' ||
        whatIsInTheCell(board,blackKingCol-2,blackKingRow+1)=='N' ||
        whatIsInTheCell(board,blackKingCol-1,blackKingRow-2)=='N' ||
        whatIsInTheCell(board,blackKingCol-2,blackKingRow-1)=='N')
    {
        return 2;
    }

    safe=0;

    /*scans for the check to the right of the row */
    for(i=blackKingCol+1;i<='h';++i)
    {
        cellContent=whatIsInTheCell(board,i,blackKingRow);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        row*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='P' ||
            cellContent=='N' || cellContent=='B' || cellContent=='K')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the row and the pass is not safe */
        if((cellContent=='Q' || cellContent=='R') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans for the check to the left of the row */
    for(i=blackKingCol-1;i>='a';--i)
    {
        cellContent=whatIsInTheCell(board,i,blackKingRow);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        row*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='P' ||
            cellContent=='N' || cellContent=='B' || cellContent=='K')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the row and the pass is not safe */
        if((cellContent=='Q' || cellContent=='R') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans the column up for the check */
    for(i=blackKingRow+1;i<=8;++i)
    {
        cellContent=whatIsInTheCell(board,blackKingCol,i);
        
        /*indicates that the pass is safe if there is a friendly piece on the
         clumn*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='P' ||
            cellContent=='N' || cellContent=='B' || cellContent=='K')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='Q' || cellContent=='R') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans the column down for the check*/
    for(i=blackKingRow-1;i>=1;--i)
    {
        cellContent=whatIsInTheCell(board,blackKingCol,i);
        
        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='P' ||
            cellContent=='N' || cellContent=='B' || cellContent=='K')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='Q' || cellContent=='R') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans diagonally right up for the check*/
    for(i=blackKingCol+1,j=blackKingRow+1;i<='h' && j<=8;++i,++j)
    {

        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='a' && cellContent<='z' && cellContent!='k') ||
         cellContent=='R' || cellContent=='N' || cellContent=='K' || 
         cellContent=='P')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe */
        if((cellContent=='B' || cellContent=='Q') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans diagonally right down for the check */
    for(i=blackKingCol+1,j=blackKingRow-1;i<='h' && j>=1;++i,--j)
    {
        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='R' ||
            cellContent=='N' || cellContent=='K' || cellContent=='P')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not 
        safe*/ 
        if((cellContent=='B' || cellContent=='Q') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans diagonally left up for the check */
    for(i=blackKingCol-1,j=blackKingRow+1;i>='a' && j<=8;--i,++j)
    {

        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the 
        clumn*/
        if((cellContent>='a' && cellContent<='z' && cellContent!='k') || 
            cellContent=='R' || cellContent=='N' || cellContent=='K' || 
            cellContent=='P')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not
         safe */
        if((cellContent=='B' || cellContent=='Q') && safe==0)
        {
            return 2;
        }
    }

    safe=0;

    /*scans diagonally left down for the check */
    for(i=blackKingCol-1,j=blackKingRow-1;i>='a' && j>=1;--i,--j)
    {

        cellContent=whatIsInTheCell(board,i,j);

        /*indicates that the pass is safe if there is a friendly piece on the
         clumn*/
        if((cellContent>='a' && cellContent<='z') || cellContent=='R' ||
            cellContent=='N' || cellContent=='K' || cellContent=='P')
        {
            safe=1;
        }

        /*quits if there is queen or rook on the column and the pass is not
         safe */
        if((cellContent=='B' || cellContent=='Q') && safe==0)
        {
            return 2;
        }
    }

    /*if no king is in check*/
    return 0;

}

/* Function isKingMovable                                                    */
/* -----------                                                               */ 
/* This function checks if a King is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/
int isKingMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
{

    /*checks if the move is one step move in any direction */
    if ((targetCol==sourceCol || targetCol==sourceCol+1 || 
        targetCol==sourceCol-1) && (targetRow==sourceRow || 
        targetRow==sourceRow+1 || targetRow==sourceRow-1)) 
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return 0;
}

/* Function isRookMovable                                                    */
/* -----------                                                               */ 
/* This function checks if a Rook is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/

int isRookMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
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

/* Function isBishopMovable                                                  */
/* -----------                                                               */ 
/* This function checks if a Bishop is movable according to the game's rules */
/*---------------------------------------------------------------------------*/

int isBishopMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
{
    /*Diagonal moves . The same as in the queen function*/

    int i,j;

    if((targetCol>sourceCol)&&(targetRow>sourceRow))
    {
        j=sourceRow;

        for(i=sourceCol;i<targetCol;++i)
        {
            if ((whatIsInTheCell(board,i,j)!=' ') &&
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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

/* Function isQueenMovable                                                   */
/* -----------                                                               */ 
/* This function checks if a Queen is movable according to the game's rules  */
/*---------------------------------------------------------------------------*/

int isQueenMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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
                (whatIsInTheCell(board,i,j)!=whatIsInTheCell(board,sourceCol,
                    sourceRow)))
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

/* Function isKnightMovable                                                  */
/* -----------                                                               */ 
/* This function checks if a Knight is movable according to the game's rules */
/*---------------------------------------------------------------------------*/

int isKnightMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
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

/* Function isPawnMovable                                                    */
/* -----------                                                               */ 
/* This function checks if a Pawn is movable according to the game's rules   */
/*---------------------------------------------------------------------------*/

int isPawnMovable(char *board,char sourceCol,int sourceRow,char targetCol,
    int targetRow)
{   
    /*black and white pawns cant move back*/
    if((whatIsInTheCell(board,sourceCol,sourceRow)=='p' && targetRow>sourceRow) 
        || (whatIsInTheCell(board,sourceCol,sourceRow)=='P' && 
            targetRow<sourceRow))
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