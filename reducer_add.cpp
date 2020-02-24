#include <stdio.h>
#include <cilk/cilk.h>
#include  <math.h>
#include <cilk/reducer_opadd.h> //needs to be included to use the addition reducer

#if CILKSAN
#include "cilksan.h"
#endif



int main(){
  cilk::reducer_opadd<float> sum;
  //defining the sum as a reducer with an int value
  cilk_for (int i = 0; i <= 10E6; i++)
    sum += 3^i;
  printf("%f\n",sum.get_value()); //notice that sum is now an object
}
