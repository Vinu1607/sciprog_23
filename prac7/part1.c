#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

// the get_order function prompts the user to input the polynomial order
int get_order();

// factorial function calculates the factorial of some inputted integer n
int factorial(int n);

// allocatearray creates an array in memory of length n and type double. Returns a pointer pointing to the first element in the array.
double *allocatearray(int n);

int main(void)
{
    double e, *terms;
    int order = get_order();

    // allocate space for terms array 
    // terms is a pointer
    terms = allocatearray(order);

    int i;
    for(i=0; i<order; i++){
        terms[i] = 1.0/(double) factorial(i+1);
        printf("order = %d, term = %1.14lf\n", i+1, terms[i]);
    }

    // states in question to set x=1
    e = 1.0;
    for(i=0; i<order; i++){
        e += terms[i];
    }

    // frees up terms array from memory
    free(terms);
    
    // assigns NULL to terms
    terms = NULL;

    printf("\ne = %.10lf\ndifference = %.10lf\n", e , fabs(e-exp(1.0)));

    return 0;
}

int get_order()
{
    int order;
    printf("Enter polynomial order: ");
    if(scanf("%d", &order) != 1){
        printf("Incorrect entry\n");
        exit(-1);
    }
    return order;
}

int factorial(int n)
{
    if(n<0){
        printf("Error: n is negative.\n");
        return -1;
    }
    else if(n==0){
        return 1;
    }
    else{
        //recursive function
        return(n*factorial(n-1));
    }
}

double *allocatearray(int n)
{
    double *p;
    p = (double *) malloc(n * sizeof(double));
    if(p==NULL){printf("Error in allocation\n");}
    return p;
}
