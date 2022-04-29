#include <iostream>
#include <vector>

void linear_search (std::vector<std::string> list,  std::string str)
{
    for (int i {0}; i < list.size(); i++)
    {
        if (list[i] == str)
        {
            std::cout << str << " is at " << i << std::endl;
            return;
        }
    }
    
    std::cout << str << " not found" << std::endl; 
}



int main() 
{
    std::vector<std::string> beasts {"Centeur", "Godzilla", "Monsura", "Minoteur", "Hydra", "Nessia"};
    linear_search(beasts, "hello war");
    
    return 0;
}