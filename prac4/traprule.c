#include <stdio.h>
#include <math.h>

// deg2rad converts integer degrees to float radians
float deg2rad(float deg);

// traprule applies the trapezoidal rule to an array containing tan values. floats a and b denote the x values between which the integration takes place.
float traprule(int n, float tanarray[n+1], float a, float b);

int main(void)
{   
    // n denotes the number of subintervals 
    int n = 12;

    // a and b are the bounds of integration in degrees
    float a = 0.0, b = 60.0;

    // tanarray stores n+1 tan values 
    float tanarray[n+1];

    // this loop converts equidistant degree values between a and b to radians and stores it in the tanarray
    int i;
    for(i=0; i<n+1; i++){
        tanarray[i] = tan(deg2rad(i*(b-a)/n));
        printf("tan(%.1f)=%f\n", i*(b-a)/n, tanarray[i]);
    }

    // traprule is applied and stored in area
    float area = traprule(n, tanarray, a, b);
    printf("Trapezoidal rule area = %f\n", area);
    printf("log(2.0) = %f\n", log(2.0));
    printf("The difference in values: %f\n", fabs(area - log(2.0)));


    return 0;
}

float deg2rad(float deg)
{   
    return M_PI * deg / 180;
}

float traprule(int n, float tanarray[n+1], float a, float b)
{
    float area = tanarray[0] + tanarray[n];

    int i;
    for(i=0; i<n; i++){
        area += 2*tanarray[i];
    }

    return (area * deg2rad(b - a))/(2*n);
}