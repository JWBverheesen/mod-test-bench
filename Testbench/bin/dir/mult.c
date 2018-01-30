#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double val[6];
double result;
int main(int argc, char *argv[])                //main loop. only executed once
{                                               //argv: number of strings pointed
    if(argc == 7)                               //to by argv. default 1.
    {
    	val[0] = atof(argv[1]);					//convert sdtin char to float
    	val[1] = atof(argv[2]);
    	val[2] = atof(argv[3]);
    	val[3] = atof(argv[4]);
    	val[4] = atof(argv[5]);
        val[5] = atof(argv[6]);
    	result = val[5]/(((val[0] + val[1] + val[2] + val[3] + val[4]) / 5)*1000);

        fprintf(stdout, "%f", result);   		//print sum to stdout as a float
    }
    else
    {
        exit(2);                                //exit and return 2
    }
    return 0;
}