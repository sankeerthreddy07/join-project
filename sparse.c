#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define BLOCK_SIZE 2 // Adjust block size as needed

void sparseBMMAlgorithm(int m, int n, int p, int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]);
void displayMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]);

int main() {
    int m, n, p; // Dimensions of matrices
    printf("Enter the dimensions of the first matrix (m x n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the dimensions of the second matrix (n x p): ");
    scanf("%d %d", &n, &p);
    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];     // Assuming maximum dimensions
    sparseBMMAlgorithm(m, n, p, A, B, result);
    printf("Resulting matrix:\n");
    displayMatrix(m, p, result);
    return 0;
}

void sparseBMMAlgorithm(int m, int n, int p, int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS]) {
   typedef struct {
    int row;
    int col;
    double value;
} SparseMatrixEntry;

typedef struct {
    int rows;
    int cols;
    int numEntries;
    SparseMatrixEntry* entries;
} SparseMatrix;

SparseMatrix* createSparseMatrix(int rows, int cols) {
    SparseMatrix* matrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->numEntries = 0;
    matrix->entries = NULL;
    return matrix;
}

void setSparseMatrixEntry(SparseMatrix* matrix, int row, int col, double value) {
    SparseMatrixEntry* entry = (SparseMatrixEntry*)malloc(sizeof(SparseMatrixEntry));
    entry->row = row;
    entry->col = col;
    entry->value = value;
    
    matrix->numEntries++;
    matrix->entries = (SparseMatrixEntry*)realloc(matrix->entries, matrix->numEntries * sizeof(SparseMatrixEntry));
    matrix->entries[matrix->numEntries - 1] = *entry;
}

SparseMatrix* multiplySparseMatrices(SparseMatrix* matrixA, SparseMatrix* matrixB) {
    if (matrixA->cols != matrixB->rows) {
        printf("Error: Incompatible matrix dimensions\n");
        return NULL;
    }
    
    SparseMatrix* result = createSparseMatrix(matrixA->rows, matrixB->cols);
    
    for (int i = 0; i < matrixA->numEntries; i++) {
        for (int j = 0; j < matrixB->numEntries; j++) {
            if (matrixA->entries[i].col == matrixB->entries[j].row) {
                double value = matrixA->entries[i].value * matrixB->entries[j].value;
                setSparseMatrixEntry(result, matrixA->entries[i].row, matrixB->entries[j].col, value);
            }
        }
    }
    
    return result;
}


void freeSparseMatrix(SparseMatrix* matrix) {
    free(matrix->entries);
    free(matrix);
}

  SparseMatrix* AA = createSparseMatrix(3, 3);
    setSparseMatrixEntry(AA, 0, 0, 1.0);
    setSparseMatrixEntry(AA, 1, 1, 2.0);
    setSparseMatrixEntry(AA, 2, 2, 3.0);
    
    SparseMatrix* BB = createSparseMatrix(3, 3);
    setSparseMatrixEntry(BB, 0, 0, 4.0);
    setSparseMatrixEntry(BB, 1, 1, 5.0);
    setSparseMatrixEntry(BB, 2, 2, 6.0);
    
    SparseMatrix* CC = multiplySparseMatrices(AA, BB);
    
   // printSparseMatrix(CC);
    
   freeSparseMatrix(AA);
   freeSparseMatrix(BB);
   freeSparseMatrix(CC);
    

}

void displayMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}