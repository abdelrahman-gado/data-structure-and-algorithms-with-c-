#include <iostream>
#include <vector>

void findNemo (std::vector<std::string> array)
{
    for (int i {0}; i < array.size(); i++)
    {
        if (array[i] == "nemo")
        {
            std::cout << "Found Nemo!" << std::endl; 
        }
    }
}

int main() 
{
    
    std::vector<std::string> nemo {"nemo"};
    
    findNemo(nemo);
    
    
    return 0;
}