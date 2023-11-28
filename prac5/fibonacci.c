#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// the get_n function prompts the user to input the number of fibonacci terms to be printed out.
int get_n();

// gen_fib intakes the last two terms of the fibonacci sequence (i and i-1), adds them together, and assigns the i term to i-1 and the i+1 term to i. The function deals with the terms addresses so it doesn't return a value.
void gen_fib(int *p0, int *p1);

int main(void)
{
    // n is the length of the fibonacci sequence
    int n = get_n();

    // the fibonacci sequence is defined to start with the terms 0,1
    int F0 = 0, F1 = 1;

    // this chunk of code ensures the correct number of terms is printed out for n = 0 or 1 and n > 1.
    int i;
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        printf("%d\n", F0);
    }
    else{
        printf("%d\n", F0);
        printf("%d\n", F1);
    }



    for (i=2; i<n; i++)
    {
        gen_fib(&F0, &F1);
        printf("%d\n", F1);
    }

    return 0;
}

int get_n()
{
    int n;
    printf("Enter n: ");
    if(scanf("%d", &n) != 1){
        printf("Incorrect entry\n");
        exit(-1);
    }
    return n;
}

void gen_fib(int *p0, int *p1)
{
    int fn; 
    fn = *p0 + *p1;
    *p0 = *p1;
    *p1 = fn;
}
