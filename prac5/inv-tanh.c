#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// the get_delta function prompts the user to input a value for the smallest allowable term in the maclaurin series of arc tanh.
double get_delta();

// artanh1 calculates the maclaurin series of arc tanh to a precision defined by the delta variable.
double artanh1(const double x, const double delta);

// artanh2 calculates arc tanh using logarithms
double artanh2(const double x);

int main(void)
{
    double delta = get_delta();

    int length = 1000;

    // creates arrays to store the arc tanh values
    double atanh1[length];
    double atanh2[length];

    printf("The differences at x:\n");
    int i = 0;
    double x = -0.9;

    // this while loop interates as long as x is less than or equal to 0.9 and the number of iterations isn't greater than the length of the atanh arrays. In each iteration the 
    while(x<=0.9 && i<length){
        atanh1[i] = artanh1(x, delta);
        atanh2[i] = artanh2(x);
        printf("x=%.2f, diff=%.8f\n", x, fabs(atanh1[i] - atanh2[i]));
        i++;
        x+=0.01;
    }
    
    return 0;
}

double get_delta()
{
    double delta;
    printf("Enter delta: ");
    if(scanf("%lf", &delta) != 1){
        printf("Incorrect entry\n");
        exit(-1);
    }
    return delta;
}

double artanh1(const double x, const double delta)
{
    double sum = 0.0, nth_term = 1.0;
    int n = 0;

    while (fabs(delta) < fabs(nth_term))
    {
        nth_term = (pow(x, 2 * n + 1)) / (2 * n + 1);
        sum += nth_term;
        n += 1;
    }

    return sum;
}

double artanh2(double x)
{
    return 0.5 * ( log(1+x) - log(1-x) );
}