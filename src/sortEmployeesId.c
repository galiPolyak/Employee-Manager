#include "../include/headerA3.h"

//Prints sorted employees based on employee id. From smallest to largest 
void sortEmployeesId (struct employee * headLL)
{
    if (headLL == NULL) 
    { 
        printf("Error - List is empty.");
        return;
    }

    //Initialize variables
    struct employee *currEmployee = headLL;
    int arr[countEmployees(headLL)];
    int count = 0;
    int pos;

    //Loops through employees and puts all employee ids into an integer array
    while (currEmployee != NULL) 
    {
        arr[count] = currEmployee->empId; 
        count++;

        currEmployee = currEmployee->nextEmployee;
    }


    //Loop through array of empployee Ids and use bubble sort 
    for (int i = 0; i < countEmployees(headLL); i++) 
    {
        for (int j = 0; j < countEmployees(headLL) - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

   //Loop through sorted employee Id array and print employee based on employee Id
   for (int i = 0; i < countEmployees(headLL); i++)
   {
        pos = lookOnId(headLL, arr[i]);
        printOne(headLL, pos);
        printf("\n\n");
   }
}