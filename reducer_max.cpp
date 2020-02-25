#include <cilk/cilk.h>
#include <cilk/reducer_max.h>
#include <iostream>

using namespace std;

int main(){
  int A [1000000];
  for (int i = 0; i < 1000000; i++)
    A[i] = i;

  cilk::reducer< cilk::op_max<int> > best;

  cilk_for (int i = 0; i < 1000000; i++)
    best->calc_max(A[i]);

  cout << best.get_value() << "\n";
}
