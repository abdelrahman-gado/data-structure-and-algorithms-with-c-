#include <iostream>
#include <vector>

void binary_search_iterative(std::vector<int> list, int target)
{
    int start = 0;
    int last = list.size()-1;
    
    while (start <= last)
    {
        int mid = (start + last) / 2;
        
        if (list[mid] == target)
        {
            std::cout << target << " is at " << mid << std::endl;
            return;
        }
        else if (list[mid] < target)
        {
            start = mid + 1;
        }
        else if (list[mid] > target)
        {
            last = mid - 1;
        }
    }
    
    std::cout << target << " is not found" << std::endl;
    return;
}


void binary_search_recursive(std::vector<int> list, int start, int last, int target)
{
    if (start > last)
    {
        std::cout << target << " not found (recursively)" << std::endl;
        return;
    }
    
    int mid = (start + last) / 2;
        
    if (list[mid] == target)
    {
        std::cout << target << " is at (recusively) " << mid << std::endl;
        return;
    }
    else if (list[mid] < target)
    {
        binary_search_recursive(list, mid+1, last, target);
    }
    else if (list[mid] > target)
    {
        binary_search_recursive(list, start, mid-1, target);
    }
    
}


int main() 
{
    std::vector<int> list {1, 4, 6, 8, 9, 12, 34, 45};
    binary_search_iterative(list, 45);
    binary_search_recursive(list, 0, list.size()-1, 45);
    return 0;
}