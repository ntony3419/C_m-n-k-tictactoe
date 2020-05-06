#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include "linkedList.h"
#include "table.h"
#include "UserInterface.h"
void run(int width, int height, int win, LinkedList* logPtr,char**board ,int *XWinPtr, int *OWinPtr, int  *locationOne, int* locationTwo)
{


      /* create a table base on the input width height */
    int  widthBorder, heightBorder,x,y, moveLeft,game, playerOneTurn, playerTwoTurn;/*playerOneTurn and playerTwoTurn record the turn the player play*/
    
	int XWin, OWin;
	
    char playerOneName,playerTwoName;
	char winner;
   
   
	XWin = 0;
	OWin = 0;
	XWinPtr = &XWin;
	OWinPtr = &OWin;
    playerOneTurn=1;
    playerTwoTurn = 2;
    game=0;
    playerOneName = 'X';
    playerTwoName = 'O';
    widthBorder = (width*2)+3; /* amount collum */
    heightBorder = (height * 2)+1; /* amount row */
    moveLeft = width * height; /* total cell available*/


    /*create the board */

    /* end create the board*/
    display(height, width, board);

    /* create the log pointer*/
    /*choose player */
			/* check winner */
            printf("X play first\n");

            while (moveLeft != 1 && XWin == 0 && OWin == 0) /* move available and no winner*/
            {            	
                printf("move left : %d", moveLeft);
            /*    printf("move left %d",moveLeft);*/
                game++; /*counting the amount of game after each player played one turn */
                /* playerone move */
				if ( OWin == 0) 
				{
                    do
                    {
                        printf("------------ player %c turn ------------\n", playerOneName);
                        do
                        {
                            printf("\nchoose a tile (x y): ");
                            scanf(" %d %d", &x, &y);
                            locationOne[0]=x; /* x user*/ 
                            locationOne[1]=y;
                            if (x < 1 || y < 1)
                            {
                                printf("x y must not be less than 0 Again\n");
                            }
                            if (x >= heightBorder-1 || y >=widthBorder-2)
                            {
                                printf("x y must not be less than size of the board. Again\n");
                            }

                        }while (x<1 || x>(heightBorder-1) || y< 1 || y>= (widthBorder-1));  /*out of border */
                        if (alreadyPlayed(board,x,y) == 1 )
                        {
                            printf("that tile already played choose another \n");

                        }
                    }while (alreadyPlayed(board,x,y)==1);

                    /* accept the tile place the tile into the board */
                    if (x==1)
                    {
                        board[x][y*2]= playerOneName;
                    }
                    else
                    {
                        board[(x*2)-1][y*2]= playerOneName;
                    }

                    display(height, width, board);
                     /* check if the player one has won*/
					winnerFound( board,  widthBorder,  heightBorder ,  win ,  XWinPtr, OWinPtr);
                    /*printf("\nwon the game condition %d \n", wonTheGame);*/

                    /* if not won then continue to player 2 turn */
                    /* display the result */

				
                /*check con dition of winner after player One played*/

                moveLeft--; /*calculate the tiles left*/
				}
			

                /* playertwo */
                printf("move left : %d", moveLeft);
            /*    printf("move left %d",moveLeft);*/
                if (XWin == 0)
				{
                    do
                    {
                        printf("------------ player %c turn ------------\n", playerTwoName);
                        do
                        {
                            printf("\nchoose a tile (x y): ");
                            scanf(" %d %d", &x, &y);
                                locationTwo[0]=x; /* O user*/
                                locationTwo[1]=y;

                            if (x < 1 || y < 1)
                            {
                                printf("x y must not be less than 0 Again\n");
                            }
                            {
                            if (x >= heightBorder-1 || y >=widthBorder-2)
                                printf("x y must not be less than size of the board. Again\n");
                            }

                        }while (x<1 || x>(heightBorder-1) || y < 1 || y>= (widthBorder-1));  /*out of border */
                        if (alreadyPlayed(board,x,y) == 1 )
                        {
                            printf("that tile already played choose another \n");

                        }
                    }while (alreadyPlayed(board,x,y)==1);

                    /* accept the tile place the tile into the board */
                    if (x==1)
                    {
                        board[x][y*2]= playerTwoName;
                    }
                    else
                    {
                        board[(x*2)-1][y*2]= playerTwoName;
                    }
                   


/*					printf("current log\n");*/
					/*printLL(logPtr);*/
					 display(height, width, board);
                /*check con dition of winner after player two played*/
					winnerFound( board,  widthBorder,  heightBorder ,  win ,  XWinPtr, OWinPtr);

                /* save the move to the log */
                   

                moveLeft--; /* calulate the tile left */
                }
                
                if (moveLeft ==1)
				{
					printf("\nOut of Move . Tie \n");							
				}
				winner = ' ';
				if (XWin ==1 )
				{
					winner = 'X';
					insertEnd(logPtr,  height,  width,  win,  playerOneTurn,  playerOneName, locationOne,  playerTwoTurn,  playerTwoName,  locationTwo, game, winner);
				}
				
				if (OWin == 1)
				{
					winner = 'O';
					insertEnd(logPtr,  height,  width,  win,  playerOneTurn,  playerOneName, locationOne,  playerTwoTurn,  playerTwoName,  locationTwo, game, winner);
				}
				
				if (XWin ==0 && OWin == 0)
				{
					insertEnd(logPtr,  height,  width,  win,  playerOneTurn,  playerOneName, locationOne,  playerTwoTurn,  playerTwoName,  locationTwo, game, winner);
				}

            }
			if (XWin ==1)
			{
				printf("Player X win \n" );
			}
			if (OWin ==1)
			{
							printf("Player O win \n" );
			}

				printf("\n");			
    /* display table */
  /*  display(widthBorder, heightBorder, board);*/
    /* free memory */


}

int alreadyPlayed(char** board, int x , int y)
{
    int played ;
    played = 1;/* 1 mean true or already played*/
    if (x ==1)
    {
        if (board[x][y*2] == ' ')
        {
            played = 0;
        }
    }
    else
    {
        if (board[(x*2)-1][y*2]==' ')
        {
            played = 0;
        }

    }
    return played;
}

int endGame(int moves)
{
    int end = 0;
    if (moves == 0)
    {
        end = 1;
    }
    return end;


}

void winnerFound(char ** board, int widthBorder, int heightBorder , int win , int *XwinPtr, int * OwinPtr)
{
	int i,j,countX, countO; /* i for height or row, j for width or colum*/
	int l, m ; /* for diagnal check */
	countX = 0;
	countO = 0;
	
	/* look through current board to find winner*/
	/* row win */
	for (i = 1; i < heightBorder ; i += 2) /* player X , increment every 2 row*/
	{
		for (j = 2; j < widthBorder; j+=2)
		{
			if (board[i][j] == 'X') /* player one */
			{
				countX += 1; /* continously X*/				


			}
			 if (board[i][j] == 'O')
			{
				countX = 0; /* player O block */
			}
			if (countX == win) /* playerone reach the winning condition*/ 
			{			
				(*XwinPtr) = 1;
			}
		}	
		if ( (*XwinPtr) == 0)
		{
			countX = 0;/* there not enough mark on the line so reset for the next row */
		}

	}

	for (i = 1; i < heightBorder ; i+=2 ) /* player O */
	{
		for (j = 2; j < widthBorder; j+=2)
		{

			if (board[i][j] == 'O') /* player two */
			{
				countO += 1; /* continously O*/

			}
			if (board[i][j] == 'X')
			{
				countO = 0; /* player X block */
			}
			if (countO == win) /* playerTwo reach the winning condition*/ 
			{
				*OwinPtr = 1;
			}
		}
		if ((*OwinPtr) == 0)
		{
			countO = 0; /* nt enough countinuous O on the row for a win*/	
		}

	}
	
	/* colum check*/	
	i=1;
	j=2;
	while (j < widthBorder-1) /* xplayer*/
	{
		while (i < heightBorder)
		{/*
			printf("current width %d\n", j);
			printf("current height %d\n", i);*/
			if (board[i][j] == 'X') /* player one */
			{
				countX += 1; /* continously X*/								
				/* increse i by 2 */
				i+=2;
			}
			else
			{
				i+=2;
			}
			 if (board[i][j] == 'O')
			{
				countX = 0; /* player O block */
				i+=2; /*increase i by 2*/
			}
			
			if (countX == win) /* playerone reach the winning condition*/ 
			{			
				(*XwinPtr) = 1;
			}
/*			printf("small loop width %d\n", j);
			printf("small loop height %d\n", i);*/
		}
		if ( (*XwinPtr) == 0)
		{
			countX = 0;/* there not enough mark on the line so reset for the next row */
		}
		j+=2;
		i=1; /* reset the height */

/*					printf("bigg lopp width %d\n", j);
			printf("big loop height %d\n", i);*/
	}	

	i=1;
	j=2;
	while (j < widthBorder-1) /* O player */
	{
		while (i < heightBorder)
		{

			if (board[i][j] == 'O') /* player Two */
			{
				countO += 1; /* continously O*/				
/*				printf("\nO player colum win : %d", countO);*/

				i+=2;				/* increse i by 2 */
			}
			else
			{
				i+=2;
			}
			 if (board[i][j] == 'X') /* block by X */
			{
				countO = 0; /* player X block */
				i+=2; /*increase i by 2*/
			}
			
			if (countO == win) /* playerone reach the winning condition*/ 
			{			
				(*OwinPtr) = 1;
			}

		}
		if ( (*OwinPtr) == 0)
		{
			countO = 0;/* there not enough mark on the line so reset for the next row */
		}
		j+=2;
		i=1; /* reset the height */
	}
	/* diagonal check*/
	i=1;
	j=2;
	while (i < heightBorder ) /* x player*/
	{
		while (j < widthBorder)
		{
	/*	printf ("i is %d \nj is %d \n",i,j);*/
		/*
			printf("current width %d\n", j);
			printf("current height %d\n", i);*/
			if (board[i][j] == 'X')
			{				
				countX=1;
											/*printf("1 count X %d\n",countX);*/
				l=i;
				m=j;
				/* diagnoal top left to bottom right */
				/* check top left */
				while (l>1 && m>1)
				{
					
						l-=2;
						m-=2;
						if (board[l][m] =='X') /* found another one top left */
						{
							countX ++;
																/*		printf("2 count X %d\n",countX);*/
							if (countX == win)
							{
								*XwinPtr = 1;
								
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=0;
							m=0;
						}
					
				}
				/*check bottom right */
				l=i;
				m=j;
				while (l < heightBorder && m< widthBorder)
				{
					
						l+=2;
						m+=2;
						if (board[l][m] =='X') /* found another one top left */
						{
							countX ++;
														/*				printf("3 count X %d\n",countX);*/
							if (countX == win)
							{
								*XwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=widthBorder;
						}
					
				}
				/* diagnal bottom left to top right */
				/* reset the countX to orignial*/
				l=i;
				m=j;
				while (l<heightBorder && m > 1) /* bottom left  */
				{
						l+=2;
						m-=2;
						if (board[l][m] =='X') /* found another one top left */
						{
							countX ++;
																/*		printf("4 count X %d\n",countX);*/
							if (countX == win)
							{
								*XwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=0;
						}
					
				}
				/*check top right */
				l=i;
				m=j;
			
				while (l > 1 && m < widthBorder)
				{
						l-=2;
						m+=2;
						if (board[l][m] =='X') /* found another one top left */
						{
							countX ++;
/*																		printf("5 count X %d\n",countX);*/
							if (countX == win)
							{
								*XwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=widthBorder;
						}
					
				}
			}			
		j+=2;	
/*			printf("small loop width %d\n", j);
			printf("small loop height %d\n", i);*/
		}/* end loop j*/
		if ( (*XwinPtr) == 0)
		{
			countX = 0;/* there not enough mark on the line so reset for the next row */
		}
		i+=1; 
		j=2;

/*					printf("bigg lopp width %d\n", j);
			printf("big loop height %d\n", i);*/
	}
	/* diagnal check O player */
	i=1;
	j=2;
	while (i < heightBorder ) /* O player*/
	{
		while (j < widthBorder)
		{
	/*	printf ("i is %d \nj is %d \n",i,j);*/
		/*
			printf("current width %d\n", j);
			printf("current height %d\n", i);*/
			if (board[i][j] == 'O')
			{				
				countO=1;
										/*	printf("1 count O %d\n",countO);*/
				l=i;
				m=j;
				/* diagnoal top left to bottom right */
				/* check top left */
				while (l>1 && m>1)
				{
					
						l-=2;
						m-=2;
						if (board[l][m] =='O') /* found another one top left */
						{
							countO ++;
															/*			printf("2 count O %d\n",countO);*/
							if (countO == win)
							{
								*OwinPtr = 1;
								
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=0;
							m=0;
						}
					
				}
				/*check bottom right */
				l=i;
				m=j;
				while (l < heightBorder && m< widthBorder)
				{
					
						l+=2;
						m+=2;
						if (board[l][m] =='O') /* found another one top left */
						{
							countO ++;
																/*		printf("3 count O %d\n",countO);*/
							if (countO == win)
							{
								*OwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=widthBorder;
						}
					
				}
				/* diagnal bottom left to top right */
				/* reset the countX to orignial*/
				l=i;
				m=j;
				while (l<heightBorder && m > 1) /* bottom left  */
				{
						l+=2;
						m-=2;
						if (board[l][m] =='O') /* found another one top left */
						{
							countO ++;
																/*		printf("4 count O %d\n",countO);*/
							if (countO == win)
							{
								*OwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=0;
						}
					
				}
				/*check top right */
				l=i;
				m=j;
			
				while (l > 1 && m < widthBorder)
				{
						l-=2;
						m+=2;
						if (board[l][m] =='O') /* found another one top left */
						{
							countO ++;
																/*		printf("5 count O %d\n",countO);*/
							if (countO == win)
							{
								*OwinPtr = 1;
							}
						}
						else/* blocked by something elfse*/
						{
							/* end this loop */
							l=heightBorder;
							m=widthBorder;
						}
					
				}
			}			
		j+=2;	
/*			printf("small loop width %d\n", j);
			printf("small loop height %d\n", i);*/
		}/* end loop j*/
		if ( (*OwinPtr) == 0)
		{
			countO = 0;/* there not enough mark on the line so reset for the next row */
		}
		i+=1; 
		j=2;

/*					printf("bigg lopp width %d\n", j);
			printf("big loop height %d\n", i);*/
	}
	
	
	
}

void display(int height, int width, char** table)
{
    int i, j,num,k,col;
    int widthBorder;
    int heightBorder;
    widthBorder = (width*2)+3; /* amount collum */
    heightBorder = (height * 2)+1; /* amount row */
    num=1;
    col=1;
    printf("  y ");
    for (k=0; k< width; k++) /*cordinate y */
    {
    	printf("%d ",col++);
    }
    printf("\n");
    for (i=0; i < heightBorder; i ++)
    {
    	if (i==0) /* cordinate x */
    	{
    		printf("x ");
    	}
    	else if (i%2==0)
    	{
    		printf("  ");
    	}
    	else
    	{
    		printf("%d ",num++);
    	}
    	
        for (j = 0; j < widthBorder;j++)
        {
            printf("%c",table[i][j]);
        }
        printf("\n");
    }

}
