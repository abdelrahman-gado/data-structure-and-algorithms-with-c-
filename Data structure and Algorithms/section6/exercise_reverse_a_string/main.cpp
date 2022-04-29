#include <iostream>
#include <algorithm>
#include <typeinfo>

// O(n) --> time
// O(1) --> space
std::string reverse1(std::string str)
{
    int start = 0;
    int last = str.length()-1;
    while (start < last)
    {
        char temp_char = str[start];
        str[start] =  str[last];
        str[last] = temp_char;
        
        start++;
        last--;
    }
    
    return str;
}

std::string reverse2 (std::string str)
{
    std::string reversed_str;
    for (int i {str.length()-1}; i >= 0; i--)
    {
        reversed_str.push_back(str[i]);
    }
    return reversed_str;
}

std::string reverse3 (std::string str)
{
    std::reverse(str.begin(), str.end());
    return str;
}



int main() 
{
    std::cout << reverse1("Hi My name is Andrei") << std::endl;
    
    return 0;
}