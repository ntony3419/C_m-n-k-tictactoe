#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

/*a. create linked list*/
LinkedList *createLL(void)
{
    LinkedList *list;
    list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/* b. insert at start*/
void insertStart(LinkedList *list, int height, int width, int win, int playerOneTurn, char playerOne, int *locationOne, int playerTwoTurn, char playerTwo, int* locationTwo, int game, char winner)
{
	JNode *newNode = (JNode * ) malloc(sizeof(JNode));
	        newNode->locationOne = (int*)malloc(sizeof(int)*2);
        newNode->locationTwo = (int*)malloc(sizeof(int)*2);
	newNode->height = height;
        newNode -> width = width;
        newNode -> win = win;
        newNode -> playerOneTurn = playerOneTurn;
        newNode -> playerOne= playerOne;
        newNode -> locationOne[0] = locationOne[0];
                newNode -> locationOne[1] = locationOne[1];
        newNode -> playerTwoTurn = playerTwoTurn;
        newNode -> playerTwo= playerTwo;
        newNode -> locationTwo[0] = locationTwo[0];
                newNode -> locationTwo[1] = locationTwo[1];
        newNode -> game = game;
        newNode -> winner = winner;
	newNode->next = NULL;
	if (list->head == NULL)
	{
		list->head = newNode;
	}
	else
	{
		newNode-> next = list->head;
		list->head = newNode;
	}

}
/* c. remove from start*/


void removeStart(LinkedList *list)
{
    JNode *newNode = (JNode*) malloc(sizeof(JNode));
    if (list->head == NULL)
    {
        printf("empty linkedlist \n");
    }
    else
    {


    /* point the head to next node */
    list->head = list->head-> next;
    }
    free(newNode);

}
/*d. retrive */


JNode * retrieveElement(LinkedList * list, int index)
{
    JNode *newNode = (JNode*) malloc(sizeof(JNode));
    int counter=0;
    if (list->head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        newNode = list->head;
        counter = 1;
        if (counter == index)
        {
            printf("found the node\n");
        }
        else
        {
            while (newNode-> next !=NULL )
            {
                newNode = newNode-> next;
                counter ++;
                if (counter == index)
                {
                    printf ("found the node \n");

                }
            }
        }
    }
    return newNode;
}

/* print game setting */
void printSetting(LinkedList *list)
{
    printf("Setting : \n\tM: %d\n\tN: %d\n  \tK: %d\n", list->head->height, list->head->width, list->head->win);


}
/*e print content */
void printLL(LinkedList *list)
{

    JNode *cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;/* cursor at the head */
    

    /* loop the cursor through the list and print every loop */
    if (cursor == NULL)
    {
        printf("list empty \n");
    }
    else /* when loop is not empty */
    {
        while (cursor !=NULL)
        {
            printf("Game %d:\n\tTurn: %d \n\tPlayer: %c \n\tLocation: %d,%d \n\n\tTurn: %d \n\tPlayer: %c \n\tLocation: %d,%d \n\n\tWinner is: %c \n\n",
                    cursor->game, cursor -> playerOneTurn, cursor -> playerOne, cursor->locationOne[0],cursor->locationOne[1],
                    cursor->playerTwoTurn, cursor-> playerTwo, cursor-> locationTwo[0],cursor->locationTwo[1], cursor -> winner );
            cursor = cursor-> next;



        }

    }

}
/* f quest 3*/
void insertEnd(LinkedList *list, int height, int width, int win, int playerOneTurn, char playerOne, int *locationOne, int playerTwoTurn, char playerTwo, int* locationTwo, int game, char winner)
{
	JNode *newNode, *cursor;
    cursor = (JNode*)malloc(sizeof(JNode));
    cursor = list->head;
    /* loop untill the end of the linkedlist */
    if (cursor == NULL)
    {
         insertStart(list,  height,  width,  win,  playerOneTurn,  playerOne, locationOne,  playerTwoTurn,  playerTwo,  locationTwo, game,winner);
    }
    else
    {
       while (cursor -> next != NULL)
        {
            cursor = cursor->next;
        }
        /* cursor is at the end of the linkedlist */
        /* create new Node */
        
        newNode = (JNode*)malloc(sizeof(JNode));
        newNode->locationOne = (int*)malloc(sizeof(int)*2);
        newNode->locationTwo = (int*)malloc(sizeof(int)*2);
        newNode-> height = height;
        newNode -> width = width;
        newNode -> win = win;
        newNode -> playerOneTurn = playerOneTurn;
        newNode -> playerOne= playerOne;
        newNode -> locationOne[0] = locationOne[0];
                newNode -> locationOne[1] = locationOne[1];
        newNode -> playerTwoTurn = playerTwoTurn;
        newNode -> playerTwo= playerTwo;
        newNode -> locationTwo[0] = locationTwo[0];
                newNode -> locationTwo[1] = locationTwo[1];
        newNode -> game = game;
    	newNode -> winner = winner;
        newNode -> next = NULL;

        /* set the cursor.next to newNode */
        cursor -> next = newNode;
    }

}
/*
int main(int argc, char* argv[])
{

    LinkedList *listPtr;
    JNode *cursor;
    listPtr = createLL();
       insertStart(listPtr, 5,12,2019, "nothing");
    insertStart(listPtr, 5,12,2019, "nothing 2");
    insertStart(listPtr, 5,12,2019, "nothing 3");
    insertEnd(listPtr, 5,12,2019, "nothing 4");
    printLL(listPtr);
    removeStart(listPtr);
    printLL(listPtr);

    cursor = listPtr-> head;
    while (cursor!= NULL)
    {
        listPtr-> head = cursor->next;
        free(cursor);
        cursor = listPtr-> head;


    }
    free(listPtr);
}
*/
