#include <stdlib.h>
#include <stdio.h>
#include "table.h"


void createBoard(int height, int width,  int heightBorder,    int widthBorder,  char** board)
{
    int i,j;

    
       	        	
   

 /* width of the table */

   
  /*make the border of  the table */
    for (i=0; i < heightBorder; i ++)
    {
        if (i==0 || i ==(heightBorder-1))
        {
            for (j = 0; j < widthBorder; j++)
            {
                board[i][j] = '=';
            }

        }
         else
        {

            for (j = 0; j < widthBorder; j++)
            {
                if (j == 0 || j ==1 || j == (widthBorder-1) || j == (widthBorder-2) )
                {
                    board[i][j] = '|';
                }

                else
                {

                    if (j%2 != 0)
                    {
                        board[i][j] = '|';
                    }
                     else
                    {
                        board[i][j] = ' ';
                    }

                }
            }
        }
        if (i >1 && i%2 == 0 && (i< heightBorder-1) )
        {
             for (j = 2; j < widthBorder-2; j++)
            {
                board[i][j] = '-';
            }
        }


    }
    /* end border the table*/
    /* end create table */
   /* return board;*/
}
