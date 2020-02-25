#include <future>
#include <iostream>
#include <thread>

int fib(int n)

{
    if (n < 2)
    {
        return n;
    }
    else
    {
        int y;
        std::future<int> x = std::async(std::launch::async, fib, n - 1);
        y = fib(n - 2);
        int z = x.get();
        return (z + y);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: fib [<cilk options>] <n>\n");
        exit(1);
    }
    int n = atoi(argv[1]);

    int *result = new int;
    *result = fib(n);
    std::cout << "Fib(" << n << ") =" << *result;
}
