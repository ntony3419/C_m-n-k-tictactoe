#include <stdio.h>
#include <stdlib.h>
#include "UserInterface.h"
#include "FileIO.h"
#include "table.h"
#include "TicTacToe.h"
#include "linkedList.h"
#include <ctype.h>
/*#define SECRET*/
/* run function */

void start(int argc, char *argv[])
{
    int option, width, height, win;
    char*fileName;
    int *widthPtr, *heightPtr, *winPtr;
    char**board ;
    int *XWinPtr, *OWinPtr;
     int  *locationOne,* locationTwo;
     int heightBorder,i;
    int widthBorder;
    
    #ifdef Edit
	    char answer;
    #endif
    LinkedList* logList;
    
    XWinPtr = (int*)malloc(sizeof(int));
   	OWinPtr = (int*)malloc(sizeof(int));
  	locationOne = (int*) malloc(2*sizeof(int));
	locationTwo = (int*) malloc(2*sizeof(int));
	
    
    width = 0;
    height = 0;
    win = 0;
    widthPtr = &width; /* point to width */ /* m */
    heightPtr = &height; /* point to depth */ /* n */
    winPtr = &win; /* point to win condition */ /* k */
    fileName = (char*)malloc(sizeof(char)*100);
    fileName = argv[1];
    loadSetting(widthPtr,heightPtr,winPtr, fileName );

	widthBorder = (width*2)+3; /* amount collum */ /*m*/
    heightBorder = (height * 2)+1; /* amount row */     
    
	board = (char**) malloc(sizeof(board)*heightBorder);/*array for the board */
	for (i = 0; i < widthBorder; i ++)
    {
        board[i] = (char*) malloc (sizeof(char) * widthBorder);
    }

     createBoard( height,  width,   heightBorder,    widthBorder,   board);
    /* create a logList */
    logList = createLL();
        /* error checking for not having enough 3 requrire setting */
    if (width <= 0 || height <= 0 || win <= 0)
    {
        perror ("not enough setting need three setting larger than zero\n");
    }
    else
    {
        do
        {
            menu(); /* dis play menu */
            /* load the setting from the setting files automatically*/

            /* choose an option */
            printf("Enter option (from 1-7): ");
            scanf("%d", &option);
            switch (option)
            {
                case 1:
                    printf("Start new Game\n");
                    /* run the game with above setting */
                    /*run(width, height, win, logList);*/
					run( width, height, win, logList, board ,XWinPtr, OWinPtr, locationOne, locationTwo);
                break;
                #ifdef EDIT
                case 2:
                    print("enter new setting M N K" );
                    scanf("%d %d %d", width,height, win);
                break;

                #else
                case 2:
                    printf("Setting of the game\n\n");
                    printf("width: %d\n", width);
                    printf("height: %d\n",height);
                    printf("win condition: %d in a row\n", win);
                #endif
                break;
                case 3:
                    printf("Current Log\n\n");
                    if ( logList -> head == NULL)
                    {
                    	printf("log is empty\n");
                    }
                    else
                    {
	                    printSetting(logList);
                    	printLL(logList);
                    }
                break;
                
			#ifndef SECRET
                case 4:
                    printf("Save log to file\n\n");
                    if (logList->head == NULL)
                    {
                    	printf("log is empty\n");
                    }
                    else
                    {
	                    saveToFile(logList);
                    }
                break;
            #else
			#endif

			#ifdef Edit
				case 5: /* edit mode */
					printf("enter new width: ");
					scanf("%d",&width);
					printf("enter new height: ");
					scanf("%d",&height);
					printf("enter new win condition: ");
					scanf("%d",&win);
					printf("editing the board with new setting \n");
					printf("do you want to continue previous game ? (Y/N)\n");
					
						printf("answer is : ");	
						scanf(" %c",&answer);
						if (toupper(answer) == 'Y') /* continue game */
						{
							/* auto fill all the previous location base on log file */
							printf("restoring the game on new board\n");
						}
						else if (toupper(answer) == 'N') /* new game */
						{
							printf("return to main menu \n");
						}
						else
						{
							printf("Y or N only");
						}
					
				break;
			#endif
                case 7:

                    printf("Exit");
                break;
                default:
                    printf("not a correct format\n");
                break;
            }
        }
        while (option != 7);

    }
   
	freeMemoryUI(fileName, widthPtr, heightPtr, winPtr, board, XWinPtr, OWinPtr,locationOne, locationTwo,     logList, heightBorder,  widthBorder);
}

/* free memmory */
void freeMemoryUI(char*fileName, int*widthPtr, int*heightPtr, int*winPtr, char** board, int*XWinPtr, int* OWinPtr, int* locationOne, int*locationTwo,    LinkedList* logList, int heightBorder, int widthBorder)
{
	int i;
	JNode * cursor;
	
	free(fileName);
	free(widthPtr);
	free(heightPtr);
	free(winPtr);
	free(XWinPtr);
	free(OWinPtr);
	free(locationOne);
	free(locationTwo);
	
	
	for (i = 0; i < widthBorder	;i++)
	{
		free(board[i]);
	}
	free(board);
	
	
	
	
	cursor = (JNode*) malloc (sizeof(JNode));
	cursor = logList -> head;
	while(cursor->next != NULL)
	{
		logList->head = logList->head->next;
		free(cursor);
		cursor = logList->head;

	}
}

/* menu*/
void menu(void)
{
    printf("\nWelcome to tic tac toe\n");
    printf("Choose an option\n");
    printf("1. Start new game\n");
    printf("2. View setting of the game\n");
    printf("3. View current log\n");
#ifndef SECRET
	printf("4. Save the log to file\n");
#else
    
#endif /* SECRET */

#ifdef Edit
	printf("5. Edit setting\n");
#endif
    printf("7. Exit\n");
}
