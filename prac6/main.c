#include <stdio.h>

// declare function matmult from matmult.c. This intakes 3 matrices as well as their dimensions. The matrices are multiplied as follows AxB=C.
void matmult(int n, int p, int q, int A[n][p], int B[p][q], int C[n][q]);

int main(void)
{
    // the matrices and thier dimensions are initialised
    int n = 5, p = 3, q = 4;
    int A[n][p];
    int B[p][q];
    int C[n][q];

    // 0 is assigned to all elements in C
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<q; j++){
            C[i][j] = 0;
        }
    }

    
    // each element in A is assigned the sum of its indexes i and j
    for (i=0; i<n; i++){
        for (j=0; j<p;  j++){
            A[i][j] = i + j;
        }
    }

    // each element in B is assigned i - j where i and j are indexes
    for (i = 0; i < p; i++){
        for (j = 0; j < q; j++){
            B[i][j] = i - j;
        }
    }

    matmult(n, p, q, A, B, C);

    printf("\nMatrix A\n");
    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B\n");
    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C\n");
    for (i=0; i<n; i++){
        for (j=0; j<q; j++){
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
