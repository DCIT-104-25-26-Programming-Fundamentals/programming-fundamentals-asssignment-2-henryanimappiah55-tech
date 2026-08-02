#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    char choice;
    cout << "Matrix Operations" << endl;
    cout << "  A - Transpose" << endl;
    cout << "  B - Add two matrices" << endl;
    cout << "  C - Multiply two matrices" << endl;
    cout << "Choose an operation (A/B/C): ";
    cin >> choice;

    if (choice == 'A' || choice == 'a') {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
            cout << "Error: dimensions must be between 1 and " << MAX_SIZE << "." << endl;
            return 0;
        }

        int matrix[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        readMatrix(matrix, rows, cols);
        transposeMatrix(matrix, rows, cols, result);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);
        cout << "\nTransposed Matrix:" << endl;
        printMatrix(result, cols, rows);
    }
    else if (choice == 'B' || choice == 'b') {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
            cout << "Error: dimensions must be between 1 and " << MAX_SIZE << "." << endl;
            return 0;
        }

        int matA[MAX_SIZE][MAX_SIZE];
        int matB[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matA, rows, cols);
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(matB, rows, cols);

        addMatrices(matA, matB, rows, cols, result);

        cout << "\nMatrix A:" << endl;
        printMatrix(matA, rows, cols);
        cout << "\nMatrix B:" << endl;
        printMatrix(matB, rows, cols);
        cout << "\nSum (A + B):" << endl;
        printMatrix(result, rows, cols);
    }
    else if (choice == 'C' || choice == 'c') {
        int rowsA, colsA, rowsB, colsB;

        cout << "Enter rows of Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns of Matrix A: ";
        cin >> colsA;
        cout << "Enter rows of Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns of Matrix B: ";
        cin >> colsB;

        if (rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0 ||
            rowsA > MAX_SIZE || colsA > MAX_SIZE || rowsB > MAX_SIZE || colsB > MAX_SIZE) {
            cout << "Error: dimensions must be between 1 and " << MAX_SIZE << "." << endl;
            return 0;
        }

        if (colsA != rowsB) {
            cout << "Error: columns of A must equal rows of B for multiplication." << endl;
            return 0;
        }

        int matA[MAX_SIZE][MAX_SIZE];
        int matB[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matA, rowsA, colsA);
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(matB, rowsB, colsB);

        multiplyMatrices(matA, matB, rowsA, colsA, colsB, result);

        cout << "\nMatrix A:" << endl;
        printMatrix(matA, rowsA, colsA);
        cout << "\nMatrix B:" << endl;
        printMatrix(matB, rowsB, colsB);
        cout << "\nProduct (A x B):" << endl;
        printMatrix(result, rowsA, colsB);
    }
    else {
        cout << "Error: invalid choice." << endl;
    }

    return 0;
}