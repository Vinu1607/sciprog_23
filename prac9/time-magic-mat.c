#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <sys/time.h>
#include "magic_square.h"

// uses srand to allow the rand function from stdlib.h to produce random values (according to the time)
void randomize();

// Uses malloc to create a pointer that points to an array of pointers which each point to the inital element of an array. Each array has dimensions length. The created matrix is length squared in size
int **creatematrix(int length);

// printmat prints all matrix elements to the console
void printmat(int **mat, int length);

// write_mat opens a file named matrix-data.txt and writes the matrix mat to it. The function intakes a matrix in the form of a double pointer and the matrices length. After writing the file is closed.
void write_mat(int **mat, int length);

// read_mat opens the file matrix-data.txt and reads the matrix stored inside it. It then closes the file
void read_mat(int **mat, int length);

// cleanmat iteratively applies free to each pointer composing a matrix mat and then assigns NULL to each pointer
void cleanmat(int **mat, int length);

// find_time uses sys/time.h to measure the time it takes to complete iterate iterations of the isMagicSquare function being applied to matrix mat of dimension length squared. sys/time.h is used to get microsecond precision
double find_time(int **mat, int length, int iterate);

int main(void)
{
    randomize();

    int length = 5;
    int min = 0, max = 9;

    // a matrix A of lengths 5 is created with element assigned a random integer between 0 and 9
    int **A = creatematrix(length);
    int i, j, k;
    for(i=0; i<length; i++){
        for(j=0; j<length; j++){
            A[i][j] = ((int) rand() % (max + 1 - min)) + min;
        }
    }

    // A is then written to file and then cleaned from memory
    write_mat(A, length);
    printmat(A, length);
    cleanmat(A, length);

    // the matrix B is created and it's values are read from the file matrix-data.txt. B is then cleaned from memory
    // A and B should be the same.
    int **B = creatematrix(length);
    read_mat(B, length);
    printmat(B, length);
    cleanmat(B, length);

    // Creates a file times.txt to write to. 
    FILE *f;
    f = fopen("times.txt", "w");

    // The next section of code creates a matrix C and assigns to it random values. It then uses find_time to calculate how long it takes to iterate through max_iter's of isMagicSquare applied to matrix C. This process is looped over for increasing dimension length of C. The times are written along side the matrix length to time.txt. After the time is written C is cleaned from memory. Once the loop is completed times.txt is closed. 
    int max_length = 1000;
    int max_iter = 1;
    for(i=1; i<max_length; i++){

        int **C = creatematrix(i);
        
        for(k=0; k<i; k++){
            for(j=0; j<i; j++){
                C[k][j] = ((int) rand() % (max + 1 - min)) + min;
            }
        }
        fprintf(f, "%d ", i);
        fprintf(f, "%lf\n", find_time(C, i, max_iter));
        cleanmat(C, i);
    }
    fclose(f);
    
    return 0;
}

void randomize()
{
    srand(time(0));
}

int **creatematrix(int length)
{
    int **mat = (int **) malloc(length * sizeof(int *));
    int i;
    for(i=0; i<length; i++){
        mat[i] = (int *) malloc(length * sizeof(int));
    }

    return mat;
     
}

void printmat(int **mat, int length)
{
    int i, j;
    for(i=0; i<length; i++){
        for(j=0; j<length; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void write_mat(int **mat, int length)
{
    FILE *f;
    f = fopen("matrix-data.txt", "w");
    int i, j;
    for(i=0; i<length; i++){
        for(j=0; j<length; j++){
            fprintf(f, "%d ", mat[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void read_mat(int **mat, int length)
{
    FILE *f;
    f = fopen("matrix-data.txt", "r");

    // failsafe if file doesn't exist or cannot be opened
    if(f == NULL){
        printf("cannot open file\n");
        exit(-1);
    }
    int i, j;
    for(i=0; i<length; i++){
        for(j=0; j<length; j++){
            fscanf(f, "%d ", &mat[i][j]);
        }
    }
}

void cleanmat(int **mat, int length)
{
    int i;
    for(i=0; i<length; i++){
        free(mat[i]);
        mat[i] = NULL;
    }
    free(mat);
    mat = NULL;
}

double find_time(int **mat, int length, int iterate)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int i;
    for(i=0; i<iterate; i++){
        isMagicSquare(mat, length);
    }

    gettimeofday(&end, NULL);
    
    return ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000.0;
}