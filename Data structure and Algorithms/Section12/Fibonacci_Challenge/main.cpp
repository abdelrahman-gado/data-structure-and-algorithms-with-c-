#include <iostream>

int fib_iterative(int number)  // O(n)
{
    int first = 0;
    int second = 1;
    int result = 0;
    for (int i {0}; i < number-1; i++)
    {
        result = first + second;
        first = second;
        second = result;
    }
    
    return result;
}


int fib_recursive(int number) // O(2^n)
{
    if (number < 2)
    {
        return number;
    }
    else
    {
        return fib_recursive(number-1) + fib_recursive(number-2);
    }
}


int main() 
{
    std::cout << "the fibonacci sequenece for 0 is " << fib_iterative(0) << std::endl;
    std::cout << "the fibonacci sequence for 5 is " << fib_recursive(45) << std::endl;
    
    return 0;
}