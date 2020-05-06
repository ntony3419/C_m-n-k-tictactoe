#include <stdio.h>
#include "FileIO.h"
#include <time.h>
#include <stdlib.h>
void loadSetting(int * m, int *n, int *k, char* fileName)
{

    FILE *fpt;
    char front ;
    int back;

    fpt = fopen(fileName, "r");
/* Scann each line to get the data*/
    if (fpt == NULL) /* file not found error */
    {
        perror("problem open file. file not exist ");
    }
    while ( fscanf(fpt, "%c=%d", &front, &back) != EOF )
    {
        if (front == 'M')
        {
            *m = back;
        }
        if (front == 'N')
        {
            *n = back;
        }
        if (front == 'K')
        {
            *k = back;
        }
    }
    fclose(fpt);

}
void saveToFile(LinkedList *logPtr)
{
    FILE *fptr;
    int m,n,k;
    char* fileName ;
	JNode* cursor; /* to move around the list */
    /*get the time data */
    time_t rawTime;
    struct tm *info;
    time(&rawTime);
    info = localtime(&rawTime);
    /*end get time */
	
	
	fileName = (char*)malloc(sizeof(char)*100);
    cursor = logPtr->head;
    m = cursor->width;
    n = cursor->height;
    k= cursor ->win;
    /* create file with the require name */
    sprintf(fileName,"MNK_%d-%d-%d_%d-%d_%d_%d.log", m,n,k,info->tm_hour, info->tm_min, info->tm_mday,info->tm_mon);
    /* end create file */

    fptr = fopen(fileName,"w");/* FILE pointer */


    fprintf(fptr, "Setting: \n\tM: %d\n\tN: %d\n\tK: %d\n", m,n,k);/* save the setting to top of the file */

    while (cursor != NULL)/* keep moving from head to tail*/
    {
        fprintf(fptr, "Game %d:\n\tTurn: %d \n\tPlayer: %c \n\tLocation: %d,%d \n\n\tTurn: %d \n\tPlayer: %c \n\tLocation: %d,%d \n",
                    cursor->game, cursor-> playerOneTurn, cursor-> playerOne, cursor->locationOne[0],cursor->locationOne[1],
                    cursor->playerTwoTurn, cursor-> playerTwo, cursor-> locationTwo[0],cursor->locationTwo[1] );
        cursor = cursor->next;
    }

    fclose(fptr);
}
