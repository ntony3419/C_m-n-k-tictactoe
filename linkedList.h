#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct JNode
{
    int game;
    int height;
    int width;
    int win;
	int playerOneTurn;
	char playerOne; /* player name */
	int* locationOne;
	int playerTwoTurn;
	char playerTwo; /* player name */
	int* locationTwo;
	char winner;
	struct JNode *next;
} JNode;

typedef struct LinkedList
{
    JNode * head;


}LinkedList;


/*a. create linked list*/
LinkedList *createLL(void); /* this is function pointer*/

/* b. insert at start*/
void insertStart(LinkedList *list, int height, int width, int win, int playerOneTurn, char playerOne, int *locationOne, int playerTwoTurn, char playerTwo, int* locationTwo, int game, char winner);
/* c. remove from start*/
void removeStart(LinkedList *list);
/*d. retrive */
JNode *retrieveElement(LinkedList * list, int index);
/*e print content */
void printLL(LinkedList *list);
/* f quest 3*/
void insertEnd(LinkedList *list, int height, int width, int win, int playerOneTurn, char playerOne, int *locationOne, int playerTwoTurn, char playerTwo, int* locationTwo, int game, char winner);

#endif
