#include <stdio.h>

// Function for multipication of the matrix
void mat_mul(int row1, int row2, int column1, int column2, int mat1[row1][column1],
             int mat2[row2][column2], int (*sol)[row1])
{

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            sol[i][j] = 0;
            for (int k = 0; k < column2; k++)
            {
                sol[i][j] += (mat1[i][k] * mat2[k][j]); // storing the multiplied value in sol array
            }
        }
    }
}

// Function for addition of the matrix
void mat_sum(int row, int column, int arr1[row][column], int arr2[row][column])
{
    int sum;
    printf("\n\nThe addition of matrix is \n\n");

    for (int i = 0; i < row; i++)
    {
        printf("\t\t");
        for (int j = 0; j < column; j++)
        {
            sum = arr1[i][j] + arr2[i][j]; // adding the elements
            printf("%d \t", sum);          // printing the addition
        }
        printf("\n");
    }
}

// Function for subtraction of the matrix
void mat_sub(int row, int column, int arr1[row][column], int arr2[row][column])
{
    int sub;
    printf("\n\nThe subtraction of matrix is \n\n");

    for (int i = 0; i < row; i++)
    {
        printf("\t\t");

        for (int j = 0; j < column; j++)
        {
            sub = arr1[i][j] - arr2[i][j]; // subtracting the elements
            printf("%d \t", sub);          // printing the subtraction
        }
        printf("\n");
    }
}

//main function
int main()
{
    int row1, column1, row2, column2, choice;

    printf("Enter the number of rows in matrix 1:");
    scanf("%d", &row1); // taking row1 of matrix 1 as input from user

    printf("Enter the number of columns in matrix 1:");
    scanf("%d", &column1); // taking column1 of matrix 1 as input from user

    int mat1[row1][column1]; // declaring the array1 to store the value of matrix 1

    // loop for taking the matrix 1 value as input from the user
    printf("Enter the element in the matrix 1\n");
    for (int i = 0; i < row1; i++) 
    {
        for (int j = 0; j < column1; j++)
        {
            printf("Element[%d][%d]:", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n\n");
    printf("Enter the number of rows in matrix 2:"); // taking row2 of matrix 1 as input from user
    scanf("%d", &row2);

    printf("Enter the number of columns in matrix 2:"); // taking column2 of matrix 1 as input from user
    scanf("%d", &column2);
    int mat2[row2][column2]; // declaring the array 2 for storing the matrix 2 value
    int sol[row1][column2];  // declaring the sol array for storing multipication of matrix in it

    // taking the input of element of matrix 2 from user storing it in the mat2 array
    printf("Enter the element in the matrix 2\n");
    for (int i = 0; i < row2; i++) 
    {
        for (int j = 0; j < column2; j++)
        {
            printf("Element[%d][%d]:", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    // taking input from user which funtion he wants to perform

    printf("To perform adddition Enter 1\nTo perform subtraction enter 2\nTo perform multipication enter 3\n");
    scanf("%d", &choice);

    // switch case for calling the right function according to user choice
    switch (choice)
    {
    case 1:
        if (row1 == row2 && column1 == column2) //condition for addition of matrices
        {
            mat_sum(row1, column1, mat1, mat2); // calls a function which returns the matrix sum
        }
        else
        {
            printf("Matrix addition is not possible on the given matrix\n");
        }
        break;
    case 2:
        if (row1 == row2 && column1 == column2) //condition for subtraction of matrices
        {
            mat_sub(row1, column1, mat1, mat2); // calls a function which return the matrix subtraction
        }
        else
        {
            printf("Matrix subtraction is not possible on the given matrix\n");
        }
        break;
    case 3:
        if (column1 == row2) //condition for multipication of matrices
        {
            mat_mul(row1, row2, column1, column2, mat1, mat2, sol); // calls a function which returns the matrix multipication
        }
        else
        {
            printf("Matrix multipication is not possible on given matrixs\n");
        }
        break;

    default:
        printf("Enter a valid choice\n");
        break;
    }

    if (choice == 3) // if users want the multipication of matrixs then this is the loop to print the solution
    {
        printf("The multipication of the matrix is  :\n\n");
        for (int i = 0; i < row2; i++)
        {
            printf("\t\t");
            for (int j = 0; j < column2; j++)
            {

                printf("%d \t", sol[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
