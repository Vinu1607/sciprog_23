#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// allocatearray creates an array in memory of length n and type double. Returns a pointer pointing to the first element in the array.
int *allocatearray(int n){
    int *p;
    p = (int *) malloc(n * sizeof(int));
    if(p==NULL){printf("Error in allocation\n");}
    return p;
}

// fillwithones intakes an array pointer and iterates through each of the array elements assigning 1 to them
void fillwithones(int *array, int n){
    int i; 
    for(i=0; i<n; i++){
        array[i] = 1;
    }
}

// This prints each element in an inputted array separated by a comma. Each array is printed to a new line
void printarray(int *array, int n){
    int i;
    for(i=0; i<n-1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[n-1]);
}

// the inputted array is deallocated from memory and assigned NULL
void freearray(int *array){
    free(array);
    array = NULL;
}

int main(void)
{
    int *a;

    // creates and frees up arrays of increasing length. Each array is filled with ones and printed to the console.
    int i, max_length = 10; 
    for(i=1; i<max_length+1; i++){
    a = allocatearray(i);
    fillwithones(a, i);
    printarray(a, i);
    freearray(a);
    }
    
    return 0;
    
}