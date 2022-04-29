#include <iostream>

int findFactorialIterative(int number) // O(n)
{
    int factorial = 1;
    for (int i {number}; i >= 2; i--)
    {
        factorial *= i;
    }
    
    return factorial;
}

int findFactorialRecursively(int number) // O(n)
{
    if (number < 2)
    {
        return 1;
    }
    else
    {
        return number * findFactorialRecursively(number-1);
    }
}

int main() 
{
    
    std::cout << "the factorial recursive for 5 is " << findFactorialRecursively(2) << std::endl;
    std::cout << "the factorial iterative for 5 is " << findFactorialIterative(2) << std::endl;
    
    return 0;
}