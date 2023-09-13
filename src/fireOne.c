#include "../include/headerA3.h"

/*The user is prompted to give a value between
1 and the total number of employees in the current LL. They then get rid of the 
employee at that index*/
void fireOne (a3Emp ** headLL, int whichOne)
{
    struct employee *currEmployee = *headLL;
    struct employee *temp;

    if (*headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return;
    }

    //Check if employee is head
    if (whichOne == 1)
    {
        printf("Employee [Id: %d] fired.\n", currEmployee-> empId);
        temp = (*headLL)->nextEmployee;
        freeEmployee(*headLL);
        *headLL = temp;
        printf("\nThere are now %d employees.\n\n", countEmployees(*headLL));
        return;
    }
    
    //Check if employee is tail
    else if (whichOne == countEmployees(*headLL))
    {
        while(currEmployee->nextEmployee->nextEmployee != NULL)
        {
            currEmployee = currEmployee->nextEmployee;
        }

        printf("Employee [Id: %d] fired.\n", currEmployee->nextEmployee-> empId);
        //
        freeEmployee(currEmployee->nextEmployee);
        
        currEmployee->nextEmployee = NULL;
        printf("\nThere are now %d employees.\n\n", countEmployees(*headLL));
    }
    
    //Check if its in center
    else
    {
        for(int i=2; i < whichOne; i++) 
        {
            if(currEmployee->nextEmployee != NULL) 
            {
                currEmployee = currEmployee->nextEmployee;
            }
        }
        printf("Employee [Id: %d] fired.\n", currEmployee->nextEmployee-> empId);

        temp = currEmployee->nextEmployee->nextEmployee;
        freeEmployee(currEmployee->nextEmployee);
        currEmployee->nextEmployee = temp;
        printf("\nThere are now %d employees.\n\n", countEmployees(*headLL));
    }
}