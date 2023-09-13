#include "../include/headerA3.h"

/*This function prints the data of all
employees currently in the LL.*/
void printAll (struct employee * headLL)
{
    int count = 0;

    struct employee *currEmployee = headLL;

    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return;
    }

    //Loop through limked list and print each employee
    while (currEmployee != NULL) 
    {
        printf("Employee # %d:\n", (count + 1));
        printf("    Employee id: %d\n", currEmployee-> empId);
        printf("    First name: %s\n", currEmployee->fname);
        printf("    Last name: %s\n", currEmployee->lname);
        printf("    Dependents [%d]: ", currEmployee->numDependents);

        for (int i = 0; i < currEmployee->numDependents; i++) 
        {
            printf("%s", currEmployee->dependents[i]);
            if (i != currEmployee->numDependents - 1) 
            {
                printf(", ");
            }
        }
        printf("\n\n");

        currEmployee = currEmployee->nextEmployee;

        count++;
    }
}