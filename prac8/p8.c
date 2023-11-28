#include <stdio.h>
#include <stdlib.h>

// the get_integer function prompts the user to input an integer for use in the Euclidian algorithm
int get_integer();

// function that finds the greatest common denominator bewteen two integers a and b iteratively
int gcd_iter(int a, int b);

// function that finds the greatest common denominator bewteen two integers a and b recursively
int gcd_recur(int a, int b);

int main(void)
{
    int a = get_integer();
    int b = get_integer();

    int hcf_it = gcd_iter(a, b);
    printf("Iterative = %d\n", hcf_it);

    int hcf_re = gcd_recur(a, b);
    printf("Recursive = %d\n", hcf_re);

    return 0;
}

int get_integer()
{
    int integer;
    printf("Enter an integer: ");
    if(scanf("%d", &integer) != 1){
        printf("Incorrect entry\n");
        exit(-1);
    }
    return integer;
}

int gcd_iter(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int gcd_recur(int a, int b)
{
    if(b==0){
        return a;
    }
    else if(b != 0){
        return gcd_recur(b, a%b);
    }
    return -1;
}