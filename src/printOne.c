#include "../include/headerA3.h"

/* This function takes a sequence
number (i.e., an int) as input and prints the data of the employee at that position in the current
LL.*/
void printOne (struct employee * headLL, int whichOne)
{
    int count = 1;

    struct employee *currEmployee = headLL;

    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return;
    }

    //Loop through employees 
    while (currEmployee != NULL) 
    {
        //If it equals position parameter then print the employee
        if (count == whichOne)
        {
            printf("Employee id: %d\n", currEmployee-> empId);
            printf("First name: %s\n", currEmployee->fname);
            printf("Last name: %s\n", currEmployee->lname);
            printf("Dependents: ");

            for (int i = 0; i < currEmployee->numDependents; i++) 
            {
                printf("%s", currEmployee->dependents[i]);
                if (i != currEmployee->numDependents - 1) 
                {
                    printf(", ");
                }
            }

            return;
        }

        currEmployee = currEmployee->nextEmployee;
        count++;
    }
}