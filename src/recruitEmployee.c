#include "../include/headerA3.h"

/*allows the user to manually enter the
employee data from standard input and add their information to the end of the linked list
passed as a parameter to this function.*/
void recruitEmployee (struct employee ** headLL)
{
    //Initialize variables
    char choice = 'y';
    int count = 0;
    int sum = 0;

    //Allocate memory to new employee
    struct employee *newEmployee = malloc(sizeof(struct employee));
    
    //Ask user for firstname and last name of employee
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmployee -> fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmployee -> lname);

    //Generate an employee Id
    for (int i = 0; i < strlen(newEmployee->fname); i++) 
    {
        sum += newEmployee->fname[i];
    }
    int empId = sum + strlen(newEmployee->lname);
    
    //Check if the empId already exists in the list and create a random number if necessary
    struct employee *currEmployee = *headLL;
    while (currEmployee != NULL) 
    {
        if (currEmployee->empId == empId) 
        {
            empId = rand() % 999 + 1;
            currEmployee = *headLL;
        } 
        else 
        {
            currEmployee = currEmployee->nextEmployee;
        }
    }
    newEmployee->empId = empId;

    //Set number of sependents to zero
    newEmployee->numDependents = 0;

    //Allocate memory to 2d array dependents
    newEmployee -> dependents = malloc(sizeof(char *));

    while(tolower(choice) == 'y')
    {
        //Allocate memory to account for a new row
        newEmployee -> dependents = realloc(newEmployee -> dependents, sizeof(char *) * (count + 1));
        //Allocate memory to store dependent names
        newEmployee -> dependents[count] = malloc(sizeof(char) * MAX_LENGTH);

        printf("\nEnter name of dependent# %d: ", (count + 1));
        scanf("%s", newEmployee -> dependents[count]);

        newEmployee -> dependents[count][strlen(newEmployee -> dependents[count])] = '\0';
        //Allocate memory to size of dependent name
        newEmployee -> dependents[count] = realloc(newEmployee -> dependents[count], sizeof(char)*(strlen(newEmployee -> dependents[count]) + 1));

        printf("Do you have any more dependents? ");
        scanf(" %c", &choice);
        count++;
    }

    //Set number of dependents to count
    newEmployee->numDependents = count;

    printf("\nYou have %d dependents.", count);

    //Make new employee the last node
    newEmployee->nextEmployee = NULL;

    //Make new employee the head if list is empty
    if (*headLL == NULL) 
    {
        *headLL = newEmployee;
    } 
    else 
    {
        struct employee *lastEmployee = *headLL;
        
        while (lastEmployee->nextEmployee != NULL) 
        {
            lastEmployee = lastEmployee->nextEmployee;
        }
        lastEmployee->nextEmployee = newEmployee;
    }

    printf("\n\nYour computer-generated empId is %d\n", empId);
} 