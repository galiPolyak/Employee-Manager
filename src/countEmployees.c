#include "../include/headerA3.h"

//Counts number of employees
int countEmployees (a3Emp * headLL)
{
    int count = 0;

    struct employee *currEmployee = headLL;

    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return 0;
    }

    //Loops through employees
    while (currEmployee != NULL) 
    {
        currEmployee = currEmployee->nextEmployee;
        count++;
    }

    //Returns count
    return count;
}