#include <iostream>
#include <unordered_map>

int fibonacci_master (int n, std::unordered_map<int, int> &cache)
{
    if (cache.find(n) != cache.end())
    {
        return cache[n];
    }
    
    int result {0};
    
    if (n < 2)
        result = n;
    else
        result = fibonacci_master(n-1, cache) + fibonacci_master(n-2, cache);
    
    cache[n] = result;
    
    return result;
}

int main() 
{
    std::unordered_map<int, int> cache;
    std::cout << fibonacci_master(35, cache) << std::endl;
    return 0;
}