#include <iostream>
#include <thread>
void fib(int *result, int n) {
  int x, y;
  if (n < 2)
    *result = n;
  else {
    int x, y;
    fib(&x, n - 1);
    // std::thread t2 (fib, &y, n-2);
    fib(&y, n - 2);
    // t2.join();
    *result = x + y;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: fib [<cilk options>] <n>\n");
    exit(1);
  }
  int n = atoi(argv[1]);
  int *result = new int;
  fib(result, n);
  std::cout << "Fib(" << n << ") =" << *result;
}
