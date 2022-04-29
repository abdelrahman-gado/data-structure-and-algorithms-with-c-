#include <iostream>
#include <vector>
#include <set>

bool has_pair_with_sum (std::vector<int> arr, int sum)
{
    std::set<int> comp_arr;
    for (int i {0}; i < arr.size(); i++)
    {
        if (comp_arr.find(arr[i]) != comp_arr.end())
        {
            return true;
        }
        comp_arr.insert(arr[i]);
    }
    
    return false;
}


int main() 
{
    std::cout << has_pair_with_sum({1, 2, 3, 9}, 8) << std::endl;
    std::cout << has_pair_with_sum({1, 2, 4, 4}, 8) << std::endl;
    return 0;
}