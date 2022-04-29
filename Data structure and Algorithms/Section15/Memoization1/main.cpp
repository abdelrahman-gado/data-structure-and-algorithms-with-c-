#include <iostream>
#include <unordered_map>

int addto80 (int n)
{
    std::cout << "long time" << std::endl;
    return n + 80;
}


int memoizedAddTo80 (int n, std::unordered_map<int, int> &cache)
{
    if (cache.find(n) != cache.end())
    {
        return cache[n];
    }
    else
    {
        std::cout << "long time" << std::endl;
        cache[n] = n + 80;
        return cache[n];
    }
}


int main() 
{
    
    std::unordered_map<int, int> cache;
    std::cout << memoizedAddTo80(5, cache) << std::endl;
    std::cout << memoizedAddTo80(5, cache) << std::endl;
    
    
    return 0;
}