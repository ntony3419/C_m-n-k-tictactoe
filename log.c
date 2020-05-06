#include <stdio.h>
#include <stdlib.h>
#include "log.h"
LogList* CreateLog(void)
{
    LogList* list ;
    list = (LogList*) malloc(sizeof(LogList)); /* create the list */
    list -> head = NULL;
    return list;
}

