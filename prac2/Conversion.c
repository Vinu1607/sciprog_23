#include <stdio.h>
#include <math.h>

//there are 25 binary digits in the int 33554431.
// a c float can represent 32 binary digits.

int main(void) {

/* Declare variables */
   int i,inum,tmp,numdigits;
   float fnum;
   char binnum[60];

/* Intialise 4-byte integer */
   inum = 33554431;

/* Convert to 4-byte float */
   fnum = (float) inum;
// cannot recast inum from int to float - need new var


/* Convert to binary number (string)*/
   i = 0; tmp = inum;
   while (tmp > 0) {
     sprintf(&binnum[i],"%1d",tmp%2);
     tmp = tmp/2;
     i++;
   }

/* Terminate the string */
   binnum[i] = '\0';
       
   numdigits = ceil( log2(inum) );
   printf("The number of digits is %d\n",numdigits);

   printf("inum=%d,  fnum=%f, inum in binary=%s\n",
      inum,fnum,binnum);

   return 0;
}
