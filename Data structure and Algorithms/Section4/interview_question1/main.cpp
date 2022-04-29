#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>


// if the each array consists of unique items
bool has_common_items (const std::vector<char> &array1, const std::vector<char> &array2)
{
    std::set<char> set1 (array1.begin(), array1.end());
    std::set<char> all_items (array2.begin(), array2.end());
    all_items.insert(set1.begin(), set1.end());
    if (all_items.size() < (array1.size() + array2.size()))
        return true;
    else
        return false;
}

// O(arr1+arr2) === > O(a+b) - time complexity
// O(a) - space complexity
bool has_common_items2 (const std::vector<char> &array1, const std::vector<char> &array2)
{
    std::map<char, bool> map1;   
    for (int i {0}; i < array1.size(); i++)
    {
        map1[array1[i]] = true;
    }
    
    for (int i {0}; i < array2.size(); i++)
    {
        if (map1[array2[i]] == true)
        {
            return true;
        }
    }
    
    return false;
}



bool has_common_items3 (std::vector<char> array1, std::vector<char> array2)
{
    std::sort(array1.begin(), array1.end());
    
    for (char c : array2)
    {
        int start = 0;
        int end = array1.size()-1;
        int mid = start + (end-start)/2;
        while (mid <= end && mid >= start)
        {
            if (c == array1[mid])
            {
                return true;
            }
            else if (c > array1[mid])
            {
                start = mid + 1;
                mid = start + (end-start)/2;
            }
            else if (c < array1[mid])
            {
                end = mid - 1;
                mid = start + (end-start)/2;
            }
        }
    }
    
    return false;
}



int main() 
{
    std::cout << has_common_items2({'a', 'b', 'c', 'x'}, {'z', 'y', 'i'}) << std::endl;
    std::cout << has_common_items2({'a', 'b', 'c', 'x'}, {'z', 'y', 'x'}) << std::endl;
    return 0;
}