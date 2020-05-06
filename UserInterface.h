#include "linkedList.h"
void menu(void);
void start(int argc, char *argv[]);
void run(int width, int height, int win, LinkedList* logPtr,char**board ,int *XWinPtr, int *OWinPtr, int  *locationOne, int* locationTwo);
void printSetting(LinkedList * logList);
void freeMemoryUI(char*fileName, int*widthPtr, int*heightPtr, int*winPtr, char** board, int*XWinPtr, int* OWinPtr, int* locationOne, int*locationTwo,    LinkedList* logList, int heightBorder, int widthBorder);
