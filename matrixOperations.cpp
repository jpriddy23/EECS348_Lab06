#include <iostream>
#include <fstream>
using namespace std;

// Defining the max size of the matrix
const int MAX_SIZE = 100;

// Creating operation functions to perform on the matrices
void readMatrix(int matrix[][MAX_SIZE], int size, ifstream& input_file);
void printMatrix(int matrix[][MAX_SIZE], int size);
void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size);
void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size);
void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size);

int main()
{
    // Defining the size of the matrix
    int size;
    // First matrix
    int matrixA[MAX_SIZE][MAX_SIZE];
    // Second matrix
    int matrixB[MAX_SIZE][MAX_SIZE];
    // Sum of the two matrices
    int matrixSum[MAX_SIZE][MAX_SIZE];
    // Product of the two matrices
    int matrixProduct[MAX_SIZE][MAX_SIZE];
    // Difference of the two matrices
    int matrixDifference[MAX_SIZE][MAX_SIZE];
    // Input file stream
    ifstream input_file;

    // Open the input file
    input_file.open("matrix_input.txt");

    // If the file is opened wrong
    if (input_file.fail())
    {
        // Exit program with print statement
        cout << "Error: Failed to open the input file." << endl;
        return 1;
    }

    // Read the size of the matrix from first line of file
    input_file >> size;

    // If size is outside the threshold
    if (size <= 0 || size > MAX_SIZE)
    {
        // Exit program with print statement
        cout << "Error: Invalid size of the square matrix." << endl;
        return 2;
    }

    // Read the values of matrix A from the file
    readMatrix(matrixA, size, input_file);

    // Read the values of matrix B from the file
    readMatrix(matrixB, size, input_file);

    // Close the input file
    input_file.close();

    // Printing name and lab number
    cout << "Jaret Priddy" << endl;
    cout << "Lab #6: Matrix manipulation" << endl;

    // Print matrix A
    cout << "\nMatrix A:" << endl;
    printMatrix(matrixA, size);

    // Print matrix B
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, size);

    // Add the two matrices and print the solution
    cout << "\nMatrix Sum (A + B):" << endl;
    addMatrices(matrixA, matrixB, matrixSum, size);
    printMatrix(matrixSum, size);

    // Multiply the two matrices and print the solution
    cout << "\nMatrix Product (A * B):" << endl;
    multiplyMatrices(matrixA, matrixB, matrixProduct, size);
    printMatrix(matrixProduct, size);

    // Subtract the second matrix from the first matrix and print the solution
    cout << "\nMatrix Difference (A - B):" << endl;
    subtractMatrices(matrixA, matrixB, matrixDifference, size);
    printMatrix(matrixDifference, size);

    // Exit the program after a sucessful run
    return 0;
}

// Defining a function to read data from a file and store it in a list/array
void readMatrix(int matrix[][MAX_SIZE], int size, ifstream& input_file)
{
    // Loop through each row and column of the matrix
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            // Reading value from file and storing it in the matrix element
            input_file >> matrix[row][col];
        }
    }
}

// Defining a function to print a matrix in a more readable format
void printMatrix(int matrix[][MAX_SIZE], int size)
{
     // Loop through each row and column of the matrix
     for (int row = 0; row < size; row++)
     {
         for (int col = 0; col < size; col++)
         {
             // Print matrix element with space after it
             cout << " " << matrix[row][col];
         }
         // New line after each row
         cout << endl;
     }
}

// Defining a function that adds two matrices and stores the result in a third matrix
void addMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size)
{
    // Loop through each row and column of the matrices
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            // Add the elements of the two matrices and store the result in the result matrix
            result_matrix[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

// Defining a function for matrix multiplication
void multiplyMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size)
{
    // Loop through each row of the first matrix
    for (int row = 0; row < size; row++)
    {
        // Loop through each column of the second matrix
        for (int col = 0; col < size; col++)
        {
            // Initializing result matrix to zero
            result_matrix[row][col] = 0;

            // Loop through each element of the current row of the first matrix and the current column of the second matrix
            for (int k = 0; k < size; k++)
            {
                // Multiply the elements of the two matrices and store the result in the result matrix
                result_matrix[row][col] += matrix1[row][k] * matrix2[k][col];
            }
        }
    }
}

// Defining a function to subtract one matrix from another and store the result in a third matrix
void subtractMatrices(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int result_matrix[][MAX_SIZE], int size)
{
    // Loop through each row and column of the matrices
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            // Subtract the elements of the two matrices and store the result in the result matrix
            result_matrix[row][col] = matrix1[row][col] - matrix2[row][col];
        }
    }
}
