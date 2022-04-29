#include <iostream>
#include <unordered_map>

int fib(int n, std::unordered_map<int, int> &cache)
{
    if (cache.find(n) != cache.end())
    {
       return cache[n]; 
    }
    
    int result {0};
    if (n < 2)
        result = n;
    else
        result = fib(n-1, cache) + fib(n-2, cache);
    
    cache[n] = result;
    
    return result;
}

int main() 
{
    std::unordered_map<int, int> cache;
    
    std::cout << fib(6, cache) << std::endl;
    return 0;
}