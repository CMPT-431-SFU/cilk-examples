#include <stdio.h>
#include <cilk/cilk.h>
#include  <math.h>
#include <cilk/reducer_opadd.h> //needs to be included to use the addition reducer

#if CILKSAN
#include "cilksan.h"
#endif



int main(){
  cilk::reducer< cilk::op_add<int> > parallel_sum(0);
  //defining the sum as a reducer with an int value
 cilk_for(int i = 1; i <= 10000; i++)
   {
    *parallel_sum += i;
   }
 printf("%d\n",parallel_sum.get_value()); //notice that sum is now an object
}
