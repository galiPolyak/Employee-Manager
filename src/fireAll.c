#include "../include/headerA3.h"

/*This function removes all employees from the
current LL.*/
void fireAll (a3Emp ** headLL)
{
    char choice = 'n';

    //Ask user if they want to fire all employees
    printf("Are you sure you want to fire everyone: ");
    scanf(" %c", &choice);

    struct employee *temp;
    struct employee *currEmployee = *headLL;

    if (*headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return;
    }

    //Check if user choice is yes
    if (tolower(choice) == 'y')
    {
        //Loop through employees
        while (currEmployee != NULL)
        {
            //Free each employee
            temp = currEmployee->nextEmployee;
            freeEmployee(currEmployee);
            currEmployee = temp;
        }

        *headLL = NULL;

        printf("All fired. Linked list is now empty.\n\n");
    }
}