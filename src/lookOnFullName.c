#include "../include/headerA3.h"

/*given as
input, the full name of the employee, it searches the current LL, and returns the position of this
employee in the current LL. */
int lookOnFullName (struct employee * headLL, char whichName [100])
{
    int count = 1;
    int numSpaces = 0;
    char temp[100];

    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return -1;
    }

    //Loops through name passed as paramenter and counts how many space characters there are
    for (int i = 0; i < strlen(whichName); i++)
    {
        if (whichName[i] == ' ')
        {
            numSpaces++;
        }
    }

    struct employee *currEmployee = headLL;

    //Loops through employees
    while (currEmployee != NULL) 
    {
        //Copies current employee name into temp string
        strcpy(temp, currEmployee->fname);

        //Concatinates temp string with the number of spaces that is in parameter string
        for (int j = 0; j < numSpaces; j++)
        {
            strcat(temp," ");
        }

        //Concatinates temp string with current employee last name
        strcat(temp, currEmployee->lname);

        //If parameter string and temp string are the same return the position
        if (strcmp(temp, whichName) == 0) 
        {
            return count;
        }

        count++;
        
        currEmployee = currEmployee->nextEmployee;
    }

    //If none, return -1
    return -1;
}