#include "../include/headerA3.h"

/*given as input, an
empId, it searches the current LL using the given empId, and returns the position of this
employee in the current LL*/
int lookOnId (struct employee * headLL, int whichEmpId)
{
    int count = 1;

    struct employee *currEmployee = headLL;

    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return -1;
    }

    //Loops through employees
    while (currEmployee != NULL) 
    {
        //If current employee ID equals the ID passed down, return postion
        if (currEmployee->empId == whichEmpId) 
        {
            return count;
        }
        count++;
        currEmployee = currEmployee->nextEmployee;
    }

    //If none, return -1
    return -1;
}