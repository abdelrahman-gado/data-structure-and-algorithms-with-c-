#include <iostream>
#include <vector>

// fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13
int fib_iterative(int n)
{
    std::vector<int> resultFibList {1, 2};
    for (int i = 2; i <= n; i++)
    {
        resultFibList.push_back(resultFibList[i-1] + resultFibList[i-2]);
    }
    
    return resultFibList[n-2];
}

int fib_recursive(int n)
{
    if (n < 2)
        return n;
    else
        return (fib_recursive(n-1) + fib_recursive(n-2));
}


int main() 
{
    std::cout << "fib for 5 iterative is : " << fib_iterative(5) << std::endl;
    std::cout << "fib for 5 recursive is : " << fib_recursive(5) << std::endl;
    
    return 0;
}