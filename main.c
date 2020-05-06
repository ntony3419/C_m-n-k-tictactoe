#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#include "UserInterface.h"
#include "FileIO.h"
int main(int argc, char * argv[])
{
    /* run the program */
    if (argc < 1)
    {
        perror("Setting file is missing");
    }
    else
    {
        start(argc, argv); /* from UserInterface*/
    }



    /* display the menu*/

    return 0;
}
