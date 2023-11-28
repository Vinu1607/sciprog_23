#include <stdio.h>


int main(void) {
/* Declare variables */
   int i;
   float sum1, sum2, diff;
   

/* First sum */
   sum1 = 0.0;
   for (i=1; i<=1000; i++) { 
      sum1 = sum1 + 1/(float) i;
   }


/* Second sum */
   sum2 = 0.0;
   for (i=1000; i>0; i--) {
      sum2 = sum2 + 1/(float) i ;
   }

   printf(" Sum1=%f\n",sum1);
   printf(" Sum2=%f\n",sum2);

/* Find the difference */
   diff = sum1 - sum2;
// the two sums are mathematically the same, only differing in the order of the start and end point. The diff should be zero.

   printf(" Difference between the two is %f\n",diff);

   return 0;
}
