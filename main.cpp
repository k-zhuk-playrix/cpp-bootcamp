#include <iostream>
#include "main.h"

int main()
{
    int n;
    std::cout << "Enter an integer: ";
    std::cin >> n;
    
    std::cout << "Fibonacci(" << n << ") = " << FibonacciRecursive(n) << std::endl;
}  

unsigned long long FibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

unsigned long long FibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    unsigned long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}