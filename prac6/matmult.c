void matmult(int n, int p, int q, int A[n][p], int B[p][q], int C[n][q])
{
    int i, j, k;
    for (i = 0; i < n; i++){
        for (j = 0; j < q; j++){
            for (k=0; k<p; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}