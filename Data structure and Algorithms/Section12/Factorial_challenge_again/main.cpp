#include <iostream>

int fact_iterative(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    
    return result;
}


int fact_recursive(int n)
// find factorial recursively
{
    if (n < 2)
        return 1;
    else
        return n*fact_recursive(n-1);
}

int main() 
{
    std::cout << "the factorial for 5 iterative: " << fact_iterative(5) << std::endl;
    std::cout << "the factorial for 5 recursivly: " << fact_recursive(5) << std::endl;
    return 0;
}