#include <iostream>
#include <vector>

int binary_search_iterative (std::vector<int> &list, int target)
{
    int start = 0;
    int last = list.size()-1;
    
    while (start <= last)
    {
        int mid = (start + last) / 2;
        
        if (list[mid] == target)
            return mid;
        else if (list[mid] < target)
            start = mid + 1;
        else if (list[mid] > target)
            last = mid - 1;
    }
    
    return -1;
}

int binary_search_recursive (std::vector<int> &list, int start, int last, int target)
{
    if (start > last)
        return -1;
    
    int mid = (start + last) / 2;
    
    if (list[mid] == target)
        return mid;
    else if (list[mid] < target)
        return binary_search_recursive(list, mid+1, last, target);
    else
        return binary_search_recursive(list, start, mid-1, target);
    
}



int main() 
{
    std::vector<int> list {1, 2, 3, 4, 5, 6, 7, 8};
    int target = 1;
    std::cout << target << " is at " << binary_search_iterative(list, target) << std::endl;
    std::cout << target << " is at " << binary_search_recursive(list, 0, list.size()-1, target) << std::endl;
    
    return 0;
}