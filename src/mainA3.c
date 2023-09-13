#include "../include/headerA3.h"

int main (int argc, char *argv[])
{
    //Initialize variables
    int menuOption = 0;
    int whichOne;
    int whichEmpId;
    int numEmployees;
    int pos;
    char whichName[100];

    struct employee *head = NULL;

    loadEmpData(&head,"proFile.txt");

    while (menuOption != 10)
    {
        //Print menu
        printf("Menu: \n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n\n");
        printf("Enter your menu option: ");
        scanf("%d", &menuOption);
        printf("\n");

        //Do specific action based on user option
        switch(menuOption)
        {
            case 1:
                recruitEmployee(&head);
                printf("\n");
                break;
            case 2:
                printAll(head);
                printf ("\nCurrently, there are %d employees.\n", countEmployees(head));
                printf("\n");
                break;
            case 3:
                printf("Enter a position: ");
                scanf("%d", &whichOne);
                printf("\n");
                printOne(head, whichOne);
                printf("\n\n");
                break;
            case 4:
                printf("Enter an employee ID: ");
                scanf("%d", &whichEmpId);
                printf("\n");
                pos = lookOnId(head, whichEmpId);
                printOne(head, pos);
                printf("\n\n");
                break;
            case 5:
                printf("Enter the full name of the employee: ");
                getchar();
                fgets(whichName, 100, stdin);
                printf("\n");
                whichName[strlen(whichName) - 1] = '\0';
                pos = lookOnFullName (head, whichName);
                printOne(head, pos);
                printf("\n\n");
                break;
            case 6:
                numEmployees = countEmployees (head);
                printf("Total number of employees = %d", numEmployees);
                printf("\n\n");
                break;
            case 7:
                printf("After sorting on empId, the employees are as follows:\n\n");
                sortEmployeesId (head);
                break;
            case 8:
                printf("Currently there are %d employees.\n", countEmployees(head));
                printf("Which employee do you wish to fire - enter a value between 1 and %d: ", countEmployees(head));
                scanf("%d", &whichOne);
                fireOne(&head, whichOne);
                break;
            case 9:
                fireAll(&head);
                break;
            default:
                if (menuOption != 10)
                { 
                    printf("Invalid menu option. Try again: \n\n");
                }
                break;
        }
    }

    //Free employees
    struct employee *currEmployee = head;
    struct employee *temp; 

    while (currEmployee != NULL) 
    {
        temp = currEmployee->nextEmployee;
        freeEmployee(currEmployee);
        currEmployee= temp;
    }

    return 0;
}