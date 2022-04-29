#include <iostream>
#include <vector>

int linear_search(std::vector<int> &list, int target)
{
    for (int i {0}; i < list.size(); i++)
    {
        if (list[i] == target)
            return i;
    }
    
    return -1;
}


int main() 
{
    std::vector<int> list {2, 3, 1, 76, 34, 4};
    std::cout << "4 is found at " << linear_search(list, 0) << std::endl;
    
    return 0;
}