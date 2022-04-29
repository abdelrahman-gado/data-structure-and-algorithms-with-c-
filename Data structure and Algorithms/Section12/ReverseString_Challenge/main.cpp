#include <iostream>
#include <string>

std::string reverse_string_iterative (std::string str)
{
    std::string reversed_str {};
    for (int i = str.size()-1; i >= 0; i--)
    {
        reversed_str.push_back(str[i]);
    }
    return reversed_str;
}

std::string reverse_string_recurive (std::string str)
{
    if (str.size() == 0)
        return str;
    else
        return reverse_string_recurive(str.substr(1)) + str[0];
}



int main() 
{
    std::cout << "reversing (YoYo Master) iteratively : " << reverse_string_iterative("YoYo Master") << std::endl;
    std::cout << "reversing (YoYo Master) Recursively : " << reverse_string_recurive("YoYo Master") << std::endl;
    
    return 0;
}