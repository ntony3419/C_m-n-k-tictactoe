#include "table.h"
#include "linkedList.h"
void run(int width, int height, int win, LinkedList* logPtr,char**board ,int *XWinPtr, int *OWinPtr, int  *locationOne, int* locationTwo);
void display(int m, int n, char ** table);

int alreadyPlayed(char** board, int x , int y);
void winnerFound(char ** board, int widthBorder, int heightBorder , int win , int *XwinPtr, int * OwinPtr);
