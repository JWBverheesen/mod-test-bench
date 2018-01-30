#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])                //main loop. only executed once
{                                               //argv: number of strings pointed
    if(argc == 3)                               //to by argv. default 1.
    {
        fprintf(stdout, "%d", atoi(argv[1]) + atoi(argv[2]));   //print sum   
    }
    else
    {
        exit(2);                                //exit and return 2
    }
    return 0;
}