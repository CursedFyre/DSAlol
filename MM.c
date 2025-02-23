#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory of a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to perform matrix multiplication
void matrixMultiply(int **A, int **B, int **result, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    int **matrixA = allocateMatrix(rowsA, colsA);
    int **matrixB = allocateMatrix(rowsB, colsB);
    int **resultMatrix = allocateMatrix(rowsA, colsB);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    matrixMultiply(matrixA, matrixB, resultMatrix, rowsA, colsA, colsB);

    printf("Resultant matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(resultMatrix, rowsA);

    return 0;
}