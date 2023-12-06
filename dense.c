#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define BLOCK_SIZE 2 // Adjust block size as needed


void denseECAlgorithm(int m, int n, int q, int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS]);
void displayMatrix(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]);

int main() {
    int m, n, p,q; // Dimensions of matrices

    printf("Enter the dimensions of the first matrix : ");
    scanf("%d %d", &m, &n);

    printf("Enter the dimensions of the second matrix : ");
    scanf("%d %d", &p, &q);

    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], res[MAX_ROWS][MAX_COLS]; // Assuming maximum dimensions

    if(n!=p){
        printf("please enter valid dimensions");
    }
    else{
        printf("Enter elements for matrix A (%d x %d):\n", m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("A[%d][%d]: ", i, j);
                scanf("%d", &A[i][j]);
            }
        }

        // Input elements for matrix B
        printf("Enter elements for matrix B (%d x %d):\n", p, q);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                printf("B[%d][%d]: ", i, j);
                scanf("%d", &B[i][j]);
            }
        }
        denseECAlgorithm(m, n, q, A, B, res);
        printf("Resulting matrix:\n");
        displayMatrix(m, q, res);
    }
}

void denseECAlgorithm(int m, int n, int q, int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int res[MAX_ROWS][MAX_COLS]) {
    for(int c=0;c<m;c++){
        for (int d=0;d<q;d++) 
        { 
            res[c][d] = 0;
            for (int e= 0; e < n; e++) {
                if (A[c][e] != 0 && B[e][d] != 0) {
                    res[c][d] += A[c][e] * B[e][d];
                    break;
                }
            }
        }
    }
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