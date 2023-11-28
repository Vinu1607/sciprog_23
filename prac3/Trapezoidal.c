#include <stdio.h>
#include <math.h>

// use #define macro to use math.h value for pi
#define _USE_MATH_DEFINES

int main(void)
{
    float area_tan = log(2);
    printf("Using the log(2) supplied by the math header: %.8f\n", area_tan);

    // a = x_0 and b = x_N
    float a = 0.0, b = M_PI/3.0;

    // number of equidistant points
    int N = 12;

    // declare float arrays for x and y
    float x[N], y[N];

    //initialise certain x and y values
    x[0] = a;
    y[0] = tan(a), y[N-1] = tan(b);

    // initialise dx the distance between each generated x point
    float dx = b/(N-1);

    int k;
    for (k=0; k<N; k++)
    {
        x[k] = k * dx;
    }

    // initialise h the sum of the tan of x values
    float h = y[0] + y[N-1];

    // loop skips x_0 and x_N as they are already accounted for above
    int i;
    for (i=1; i<N-1; i++)
    {
        y[i] = 2*tan(x[i]);
        h = h + y[i];
    }

    printf("Using the trapezoidal rule with N=12: %.8f\n", ((b-a)/(2*(N-1)))*h );
    printf("The absolute error is %.8f\n", fabs(area_tan-((b-a)/(2*(N-1)))*h));

    return 0;

}
